//
// Created by barto on 15.10.2025.
//

#include "KoderRC.h"

KoderRC::KoderRC(){

}
int Size = 4;
//Repetition code
std::vector<std::vector<bool>> KoderRC::RC_koder(std::vector<std::vector<bool>> ch, int size) {
    std::vector<std::vector<bool>> RC_koder;
    for(int i = 0; i < ch.size(); i++) {
        if (ch[i].empty()) continue;
        std::vector<bool> temp;
        for(int j = 0; j < size; j++) {
            temp.push_back(ch[i][0]);
        }
        RC_koder.push_back(temp);
    }
    return RC_koder;
}
