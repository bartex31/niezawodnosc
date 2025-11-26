//
// Created by barto on 11.11.2025.
//

#ifndef WYNIK_H
#define WYNIK_H
#include <vector>
class Wynik{

    public:
        std::vector<std::vector<bool>> original;
        std::vector<std::vector<bool>> Koder;
        std::vector<std::vector<bool>> BSC;
        std::vector<std::vector<bool>> GE;
        std::vector<std::vector<bool>> DekodedBSC;
        std::vector<std::vector<bool>> DekodedGE;

        Wynik();
};

#endif //WYNIK_H
