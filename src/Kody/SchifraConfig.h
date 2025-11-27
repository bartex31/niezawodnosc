//
// Created by barto on 27.11.2025.
//

#ifndef SCHIFRACONFIG_H
#define SCHIFRACONFIG_H

#include <cstddef>

// Parametry Pola Galois (GF(2^8))
const std::size_t FIELD_DESCRIPTOR    = 8;
const std::size_t GEN_POLY_INDEX      = 120;
const std::size_t GEN_POLY_ROOT_COUNT = 32;

// Parametry Kodu Reed-Solomon (N, K)
// N = 255 (cały blok), FEC = 32 (bajty naprawcze), K = 223 (dane)
const std::size_t CODE_LENGTH = 255;
const std::size_t FEC_LENGTH  = 32;
const std::size_t DATA_LENGTH = CODE_LENGTH - FEC_LENGTH;

#endif //SCHIFRACONFIG_H
