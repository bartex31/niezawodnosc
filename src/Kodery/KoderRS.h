//
// Created by barto on 24.11.2025.
//

#ifndef KODERRS_H
#define KODERRS_H
#include <memory>
#include <cstdint>


// Schifra headers
#include <vector>

#include "../../lib/schifra-master/schifra_galois_field.hpp"
#include "../../lib/schifra-master/schifra_galois_field_polynomial.hpp"
#include "../../lib/schifra-master/schifra_sequential_root_generator_polynomial_creator.hpp"
#include "../../lib/schifra-master/schifra_reed_solomon_encoder.hpp"
#include "../../lib/schifra-master/schifra_reed_solomon_block.hpp"

#include "../Kody/SchifraConfig.h"

class KoderRS{
public:
    KoderRS();
    std::vector<uint8_t> RS_koder(std::vector<uint8_t> ch);

private:
    schifra::galois::field field;
    schifra::galois::field_polynomial generator_polynomial;
    typedef schifra::reed_solomon::encoder<CODE_LENGTH, FEC_LENGTH, DATA_LENGTH> encoder_t;
    std::unique_ptr<encoder_t> encoder;
};


#endif //KODERRS_H
