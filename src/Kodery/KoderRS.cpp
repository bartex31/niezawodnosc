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

   // 2. Dopiero teraz tworzymy koder, przekazując gotowy wielomian
   encoder = std::make_unique<encoder_t>(field, generator_polynomial);
}


std::vector<uint8_t> KoderRS::RS_koder(std::vector<uint8_t> ch) {

   schifra::reed_solomon::block<CODE_LENGTH, FEC_LENGTH> block;

   // 1. Przygotowanie danych (padding)
   std::vector<uint8_t> data = ch;
   if (data.size() > DATA_LENGTH) {
      data.resize(DATA_LENGTH);
   } else {
      data.resize(DATA_LENGTH, 0x00);
   }

   // 2. Kopiowanie danych do bloku (RĘCZNA PĘTLA zamiast std::copy)
   // Dane w bloku zaczynają się od indeksu 0
   for (std::size_t i = 0; i < DATA_LENGTH; ++i) {
      block[i] = data[i];
   }

   // 3. Właściwe kodowanie
   if (!encoder->encode(block)) {
      std::cerr << "Error: Encoding failed!" << std::endl;
      return {};
   }

   // 4. Wyciąganie całego bloku do wektora wyjściowego (RĘCZNA PĘTLA)
   // Pobieramy CODE_LENGTH bajtów (czyli 255: dane + kody naprawcze)
   std::vector<uint8_t> result(CODE_LENGTH);
   for (std::size_t i = 0; i < CODE_LENGTH; ++i) {
      result[i] = static_cast<uint8_t>(block[i]);
   }

   return result;
}



