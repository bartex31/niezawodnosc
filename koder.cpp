//
// Created by barto on 15.10.2025.
//

#include "koder.h"

#include <vector>

//Repetition code
std::vector<char> RC_koder(std::vector<char> ch) {
    std::vector<char> out;
    for (int i = 0; i < ch.size(); i++) {
        for (int j = 0; j < 3; j++) {
            out.push_back(ch[i]);
        }
    }
}

std::vector<char> BCH_koder(std::vector<char> ch) {

}

std::vector<char> RS_koder(std::vector<char> ch) {

}

std::vector<char> LDP_koder(std::vector<char> ch) {

}

std::vector<char> Turbo_koder(std::vector<char> ch) {

}

std::vector<char> Fountain_koder(std::vector<char> ch) {

}