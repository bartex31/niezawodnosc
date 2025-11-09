//
// Created by barto on 15.10.2025.
//

#include "DekoderRC.h"

#include <cmath>
#include <vector>
DekoderRC::DekoderRC(){

}
//Repetition code
std::vector<bool> DekoderRC::RC_Dekoder(std::vector<bool> ch) {
    std::vector<bool> RC_dekoder;
    for (int i = 0; i+2 <= ch.size();i+=3) {

        int sum =ch[i] + ch[(i + 1)] + ch[i + 2];
        bool bit = (sum >= 2);
        RC_dekoder.push_back(bit);

    }
    return RC_dekoder;
}
