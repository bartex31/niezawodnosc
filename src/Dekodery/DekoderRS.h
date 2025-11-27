//
// Created by barto on 24.11.2025.
//

#ifndef DEKODERRS_H
#define DEKODERRS_H


#include <cstdint>
#include <vector>
#include "../../lib/schifra-master/schifra_galois_field.hpp"
#include "../../lib/schifra-master/schifra_reed_solomon_decoder.hpp"
#include "../../lib/schifra-master/schifra_reed_solomon_block.hpp"

#include "../Kody/SchifraConfig.h"

class DekoderRS {
public:
    DekoderRS();
    std::vector<uint8_t> RS_Dekoder(std::vector<uint8_t> ch);
private:
    schifra::galois::field field;
    schifra::reed_solomon::decoder<CODE_LENGTH, FEC_LENGTH, DATA_LENGTH> decoder;
};


#endif //DEKODERRS_H
