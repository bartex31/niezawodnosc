//
// Created by barto on 09.11.2025.
//

#include "Transmision.h"

#include <random>
float BSCchange = 0.0001;
float GECchange = 0.0001;
float GECchangeReturn = 0.9;

std::vector<std::vector<bool>> Transmision::BSCchannel(std::vector<std::vector<bool>>& content) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution dis(BSCchange);
    for (int i = 0; i < content.size(); i++) {
        for (int j = 0; j < content[i].size(); j++) {
            if (dis(gen)){
                content[i][j] = !content[i][j] ;
            }
        }
    }
    return content;
}

std::vector<std::vector<bool>> Transmision::GEchannel(std::vector<std::vector<bool>>& content) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution dis(GECchange);
    std::bernoulli_distribution dis2(GECchangeReturn);
    bool change = false;
    for (int i = 0; i < content.size(); i++) {
        for (int j = 0; j < content[i].size(); j++) {
            if (!change) {
                if (dis(gen)) {
                    change = true;
                    content[i][j] = !content[i][j];
                }
            }else {
                if (dis2(gen)) {
                    change = false;
                }else {
                    content[i][j] = !content[i][j] ;
                }
            }
        }
    }

    return content;
}
