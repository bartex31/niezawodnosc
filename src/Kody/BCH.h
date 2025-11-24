//
// Created by barto on 24.11.2025.
//

#ifndef BCH_H
#define BCH_H

#include "../Transmision.h"
#include "../Kodery/KoderBCH.h"
#include "../Dekodery/DeKoderBCH.h"
#include "../../Wynik.h"

class BCH {
public:
    BCH();
    KoderBCH koderBCH;
    DekoderBCH dekoderBCH;
    Transmision transmision;
    Wynik run(std::vector<bool> data);
};



#endif //BCH_H
