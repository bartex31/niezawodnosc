//
// Created by barto on 24.11.2025.
//

#include "KoderBCH.h"

#include <iostream>

KoderBCH::KoderBCH() {

}
int N =7;
int K= 3;
int R= 4;
const std::vector<bool> G_X = {true, true, true, false, true};


std::vector<bool> encode(std::vector<bool> inp) {

    // Tworzymy KOPIĘ roboczą (working_vector)
    std::vector<bool> working_vector = inp;

    working_vector.resize(N,false); // przesunięcie u(x) o R=4 pozycje

    // Dzielenie: operujemy na working_vector
    for (int i = 0; i <= working_vector.size()-G_X.size(); i++) {
        if (working_vector[i] == true) {
            for (int j = 0; j < G_X.size(); j++) {
                working_vector[i+j]= working_vector[i+j]^G_X[j];
            }
        }
    }

    // Zwracamy resztę (ostatnie R bitów)
    std::vector<bool> out(working_vector.end()-R,working_vector.end());
    return out;
}

std::vector<std::vector<bool>> KoderBCH::BCH_koder(std::vector<bool> ch) {
    std::vector<std::vector<bool>> messages;
    for (int i = 0; i < ch.size(); i+=K) {
        std::vector<bool> temp;
        for (int j = 0; j < K; j++) {
            if (i+j<ch.size()) {
               temp.push_back(ch[i+j]);
            }else {
                temp.push_back(false);
            }

        }
        std::vector<bool> par= encode(temp);
        std::vector<bool>  full(N);

        for (int j = 0; j < K; j++) {
            full[j] =temp[j];
        }
        for (int j = 0; j < R; j++) {
            full[j+K] = par[j];
        }
        messages.push_back(full);
    }






    // for (int i = 0; i < messages.size(); i++) {
    //     for (int j = 0; j < messages[i].size(); j++) {
    //         std::cout << messages[i][j];
    //     }
    //     std::cout << std::endl;
    // }
    return messages;
}

