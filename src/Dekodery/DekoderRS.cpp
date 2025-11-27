//
// Created by barto on 24.11.2025.
//

#include "DekoderRS.h"

DekoderRS::DekoderRS()
    : field(FIELD_DESCRIPTOR,
            schifra::galois::primitive_polynomial_size06,
            schifra::galois::primitive_polynomial06),
      decoder(field, GEN_POLY_INDEX)
{
}

std::vector<uint8_t> DekoderRS::RS_Dekoder(const std::vector<uint8_t> received_data) {
    if (received_data.size() != CODE_LENGTH) {
        std::cerr << "Error: Invalid block size for decoding!" << std::endl;
        return {};
    }

    schifra::reed_solomon::block<CODE_LENGTH, FEC_LENGTH> block;

    for (std::size_t i = 0; i < CODE_LENGTH; ++i) {
        block[i] = received_data[i];
    }

    if (!decoder.decode(block)) {
        std::cerr << "Error: Decoding failed (too many errors)!" << std::endl;
    }

    std::vector<uint8_t> recovered_data(DATA_LENGTH);
    for (std::size_t i = 0; i < DATA_LENGTH; ++i) {
        recovered_data[i] = static_cast<uint8_t>(block[i]);
    }

    return recovered_data;
}