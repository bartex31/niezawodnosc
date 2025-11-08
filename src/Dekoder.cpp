//
// Created by barto on 15.10.2025.
//

#include "Dekoder.h"

#include <cmath>
#include <vector>

//Repetition code
std::vector<bool> Dekoder::RC_dekoder(std::vector<bool> ch) {
    std::vector<bool> RC_dekoder;
    for (int i = 0; i+2 <= ch.size();i+=3) {

        int sum =ch[i] + ch[(i + 1)] + ch[i + 2];
        bool bit = (sum >= 2);
        RC_dekoder.push_back(bit);

    }
    return RC_dekoder;
}

std::vector<char> BCH_dekoder(std::vector<char> ch) {

}

std::vector<char> RS_dekoder(std::vector<char> ch) {

}

std::vector<char> LDP_dekoder(std::vector<char> ch) {

}

std::vector<char> Turbo_dekoder(std::vector<char> ch) {

}

std::vector<char> Fountain_dekoder(std::vector<char> ch) {

}