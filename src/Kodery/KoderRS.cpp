//
// Created by barto on 24.11.2025.
//

#include "KoderRS.h"

KoderRS::KoderRS()
    : field(FIELD_DESCRIPTOR,
            schifra::galois::primitive_polynomial_size06,
            schifra::galois::primitive_polynomial06),
      generator_polynomial(field),
      encoder(nullptr) // Na razie null
{
   // 1. Najpierw generujemy wielomian
   if (!schifra::make_sequential_root_generator_polynomial(
           field,
           GEN_POLY_INDEX,
           GEN_POLY_ROOT_COUNT,
           generator_polynomial))
   {
      std::cerr << "Error: Failed to create generator polynomial!" << std::endl;
   }

   encoder = std::make_unique<encoder_t>(field, generator_polynomial);
}


std::vector<uint8_t> KoderRS::RS_koder(std::vector<uint8_t> ch) {

   schifra::reed_solomon::block<CODE_LENGTH, FEC_LENGTH> block;

   std::vector<uint8_t> data = ch;
   if (data.size() > DATA_LENGTH) {
      data.resize(DATA_LENGTH);
   } else {
      data.resize(DATA_LENGTH, 0x00);
   }

   for (std::size_t i = 0; i < DATA_LENGTH; ++i) {
      block[i] = data[i];
   }

   if (!encoder->encode(block)) {
      std::cerr << "Error: Encoding failed!" << std::endl;
      return {};
   }

   std::vector<uint8_t> result(CODE_LENGTH);
   for (std::size_t i = 0; i < CODE_LENGTH; ++i) {
      result[i] = static_cast<uint8_t>(block[i]);
   }

   return result;
}



