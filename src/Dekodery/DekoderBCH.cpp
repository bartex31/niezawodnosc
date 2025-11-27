//
// Created by barto on 24.11.2025.
//

#include "DekoderBCH.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

DekoderBCH::DekoderBCH() {

}


std::vector<bool> decode_single_block(std::vector<bool>& received) {
    int N = 7;
    if (received.size() != N) {
        std::cerr << "Błąd: Wymagane jest 7 bitów." << std::endl;
        return received;
    }

    int s0, s1, s2;

    s0 = received[6] ^ received[3] ^ received[1] ^ received[0]; // p0 ^ d0 ^ d2 ^ d3
    s1 = received[5] ^ received[3] ^ received[2] ^ received[0]; // p1 ^ d0 ^ d1 ^ d3
    s2 = received[4] ^ received[3] ^ received[2] ^ received[1]; // p2 ^ d0 ^ d1 ^ d2


    int syndrome_decimal = (s2 << 2) | (s1 << 1) | s0;

    if (syndrome_decimal != 0) {
 
        int error_bit = -1;
        switch (syndrome_decimal) {
            case 1: error_bit = 6; break;
            case 2: error_bit = 5; break;
            case 3: error_bit = 0; break;
            case 4: error_bit = 4; break;
            case 5: error_bit = 1; break;
            case 6: error_bit = 2; break;
            case 7: error_bit = 3; break;
        }

        if (error_bit != -1) {
             received[error_bit] = !received[error_bit];
        }
    }

    std::vector<bool> data_out(4);
    data_out[0] = received[0]; // d3
    data_out[1] = received[1]; // d2
    data_out[2] = received[2]; // d1
    data_out[3] = received[3]; // d0

    return data_out;
}

std::vector<std::vector<bool>> DekoderBCH::BCH_Dekoder(std::vector<std::vector<bool>>& ch) {
    std::vector<std::vector<bool>> decoded_messages;

    for (std::vector<bool> ch1 : ch) {
        decoded_messages.push_back(decode_single_block(ch1));
    }

    // for (const auto& message : decoded_messages) {
    //     for (bool bit : message) {
    //         std::cout << (bit ? 1 : 0) << " ";
    //     }
    //     std::cout << std::endl;
    // }

    return decoded_messages;
}
