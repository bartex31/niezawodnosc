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
// Stałe BCH(7, 3, 1)
const int N_CODED = 7; // n
const int K_MSG = 3;   // k
const int R_PARITY = 4; // r
const int M = 3;       // m (dla GF(2^3))

// Wielomian pierwotny: x^3 + x + 1 (Decyduje o arytmetyce)
const int PRIMITIVE_POLYNOMIAL = 0b1011; // 11 w systemie dziesiętnym

// Tablica: Mapowanie wartości elementu GF(8) na jego potęgę alfa (dla lokalizacji błędu)
// indeks = wartość elementu GF(8); wartość = wykładnik 'i' (gdzie element = alfa^i)
// 0, 1, 2, 3, 4, 5, 6, 7 (wartość elementu)
// -1, 0, 1, 3, 2, 6, 4, 5 (wykładnik potęgi alfa)
// np. 3 (011) to alfa^3. 5 (101) to alfa^6.
const int ALPHA_TO_POWER[8] = {-1, 0, 1, 3, 2, 6, 4, 5};

// Potęgi alfa w GF(8) - używane do obliczania syndromu
// indeks = potęga i; wartość = element GF(8) (int 0..7)
// alfa^0, alfa^1, alfa^2, alfa^3, alfa^4, alfa^5, alfa^6
const int POWER_OF_ALPHA[7] = {1, 2, 4, 3, 6, 7, 5};


int gf8_multiply(int a, int b) {
    if (a == 0 || b == 0) return 0;

    int product = 0;
    while (b > 0) {
        if (b & 1) {
            product ^= a; // Dodawanie to XOR
        }
        a <<= 1; // Mnożenie przez x

        // Redukcja modulo x^3 + x + 1 (1011)
        if (a & 0b1000) {
            a ^= PRIMITIVE_POLYNOMIAL;
        }
        b >>= 1;
    }
    return product;
}
int calculate_syndrome(const std::vector<bool>& r) {
    int S1 = 0;
    // Potęgi alfa są liczone od najmniejszej (r0 * alfa^0)
    for (int i = 0; i < N_CODED; ++i) { // i = 0 do 6
        if (r[N_CODED - 1 - i]) { // r[0] to współczynnik x^0, r[6] to współczynnik x^6
            // Pobieramy potęgę alfa: alpha^i
            int alpha_power = POWER_OF_ALPHA[i]; // Wartość elementu GF(8)

            // Mnożymy r_i (które jest 1) przez alpha^i. Mnożenie przez 1 jest trivialne.
            // S1 = S1 + alpha^i (gdzie dodawanie to XOR)
            S1 ^= alpha_power;
        }
    }
    return S1;
}

std::vector<bool> decode_single_block(std::vector<bool>& received_codeword) {
    // 1. Obliczenie Syndromu
    int S1 = calculate_syndrome(received_codeword); // Działa na r[6]...r[0]

    // 2. Weryfikacja i Lokalizacja Błędu
    int error_pos = -1;
    if (S1 != 0) {
        int error_exponent = ALPHA_TO_POWER[S1];
        error_pos = error_exponent; // Lokalizacja błędu
    }

    // 3. Korekta Błędu
    if (error_pos != -1) {
        // received_codeword[i] to r_i. Odwracamy bit.
        received_codeword[error_pos] = !received_codeword[error_pos];
    }

    // 4. Ekstrakcja Wiadomości
    // Kod systematyczny [u2, u1, u0, p3, p2, p1, p0]. Wiadomość to pierwsze K=3 bity.
    std::vector<bool> decoded_message(K_MSG);

    // Kopiujemy pierwsze K_MSG bitów [0], [1], [2] (które są u2, u1, u0)
    for (int i = 0; i < K_MSG; ++i) {
        decoded_message[i] = received_codeword[i];
    }

    return decoded_message;
}

std::vector<std::vector<bool>> DekoderBCH::BCH_Dekoder(std::vector<std::vector<bool>>& ch) {
    std::vector<std::vector<bool>> decoded_messages;

    // Iteracja po każdym bloku w wejściowym wektorze wektorów
    for (size_t i = 0; i < ch.size(); ++i) {

        // Zabezpieczenie przed nieprawidłowym rozmiarem bloku
        if (ch[i].size() != N_CODED) {
            std::cerr << "Ostrzeżenie: Blok " << i << " ma nieprawidłowy rozmiar i zostanie pominięty." << std::endl;
            continue;
        }

        // Dekodowanie pojedynczego bloku
        // Używamy referencji do bloku, ponieważ decode_single_block modyfikuje wektor (korekta)
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
