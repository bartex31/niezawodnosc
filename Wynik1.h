//
// Created by barto on 27.11.2025.
//

#ifndef WYNIK1_H
#define WYNIK1_H
#include <cstdint>
#include <vector>

class Wynik1{

public:
    std::vector<uint8_t> original;
     std::vector<uint8_t> Koder;
     std::vector<std::vector<bool>> BSC;
     std::vector<std::vector<bool>> GE;
     std::vector<uint8_t> DekodedBSC;
     std::vector<uint8_t> DekodedGE;

    Wynik1();
};



#endif //WYNIK1_H
