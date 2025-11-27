//
// Created by barto on 24.11.2025.
//

#include "KoderBCH.h"

#include <iostream>

KoderBCH::KoderBCH() {

}
int N =7;
int K= 4;
int R= 3;
std::vector<bool> encode_bch(const std::vector<bool> &data) {
    if (data.size() != K) {
        std::cout << "brak 4 bitów" << std::endl;
        return {};
    }

    bool d3 = data[0];
    bool d2 = data[1];
    bool d1 = data[2];
    bool d0 = data[3];
    //(d3,d2,d1,d0) 1,1,0,0

    bool p0 = d3 ^ d2 ^ d0; //1 1 0 -> 0
    bool p1 = d3 ^ d1 ^ d0; // 1 0 0 -> 1
    bool p2 = d2 ^ d1 ^ d0; //1 0 0 ->1

    std::vector<bool> codeword(N);
    // 1100 + 110
    codeword[0] = d3;
    codeword[1] = d2;
    codeword[2] = d1;
    codeword[3] = d0;
    codeword[4] = p2;
    codeword[5] = p1;
    codeword[6] = p0;

    return codeword;
}


std::vector<std::vector<bool>> KoderBCH::BCH_koder(std::vector<std::vector<bool>> ch) {
    std::vector<std::vector<bool>> messages;
    for (std::vector<bool> ch : ch) {
        messages.push_back(encode_bch(ch));
    }
    return messages;
}

