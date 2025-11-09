//
// Created by barto on 09.11.2025.
//

#include "Transmision.h"

#include <random>


std::vector<bool> Transmision::BSCchannel(std::vector<bool> content) {
    std::random_device rd;   // non-deterministic generator
    std::mt19937 gen(rd());  // to seed mersenne twister.
    std::bernoulli_distribution dis(0.1);
    for (int i = 0; i < content.size(); i++) {
        if (dis(gen)){
            content[i] = !content[i] ;
        }

    }

    return content;
}
