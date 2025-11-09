//
// Created by barto on 15.10.2025.
//

#include "KoderRC.h"

KoderRC::KoderRC(){

}

//Repetition code
std::vector<bool> KoderRC::RC_koder(std::vector<bool> ch) {
    std::vector<bool> out;
    for (int i = 0; i < ch.size(); i++) {
        for (int j = 0; j < 3; j++) {
            out.push_back(ch[i]);
        }
    }
    return out;
}
