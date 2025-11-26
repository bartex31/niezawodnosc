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

const int N_CODED = 7;
const int K_MSG = 3;
const int R_PARITY = 4;
const int M = 3;

const int PRIMITIVE_POLYNOMIAL = 0b1011;

const int ALPHA_TO_POWER[8] = {-1, 0, 1, 3, 2, 6, 4, 5};

const int POWER_OF_ALPHA[7] = {1, 2, 4, 3, 6, 7, 5};


int gf8_multiply(int a, int b) {
    if (a == 0 || b == 0) return 0;

    int product = 0;
    while (b > 0) {
        if (b & 1) {
            product ^= a;
        }
        a <<= 1;
        if (a & 0b1000) {
            a ^= PRIMITIVE_POLYNOMIAL;
        }
        b >>= 1;
    }
    return product;
}
int calculate_syndrome(const std::vector<bool>& r) {
    int S1 = 0;

    for (int i = 0; i < N_CODED; ++i) {
        if (r[N_CODED - 1 - i]) {

            int alpha_power = POWER_OF_ALPHA[i];


            S1 ^= alpha_power;
        }
    }
    return S1;
}

std::vector<bool> decode_single_block(std::vector<bool>& received_codeword) {

    int S1 = calculate_syndrome(received_codeword);


    int error_pos = -1;
    if (S1 != 0) {
        int error_exponent = ALPHA_TO_POWER[S1];

        error_pos = (N_CODED - 1) - error_exponent;
    }

    if (error_pos >= 0 && error_pos < N_CODED) {
        received_codeword[error_pos] = !received_codeword[error_pos];
    }

    std::vector<bool> decoded_message(K_MSG);
    for (int i = 0; i < K_MSG; ++i) {
        decoded_message[i] = received_codeword[i];
    }

    return decoded_message;
}

std::vector<std::vector<bool>> DekoderBCH::BCH_Dekoder(std::vector<std::vector<bool>>& ch) {
    std::vector<std::vector<bool>> decoded_messages;

    for (size_t i = 0; i < ch.size(); ++i) {

        if (ch[i].size() != N_CODED) {
            std::cerr << "Ostrzeżenie: Blok " << i << " ma nieprawidłowy rozmiar i zostanie pominięty." << std::endl;
            continue;
        }


        std::vector<bool>& current_block = ch[i];

        std::vector<bool> decoded_u = decode_single_block(current_block);
        decoded_messages.push_back(decoded_u);
    }

    // Wyświetlanie zdekodowanych wiadomości
    // for (const auto& message : decoded_messages) {
    //     for (bool bit : message) {
    //         std::cout << (bit ? 1 : 0) << " ";
    //     }
    //     std::cout << std::endl;
    // }

    return decoded_messages;
}
