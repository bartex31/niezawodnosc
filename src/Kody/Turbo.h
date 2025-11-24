//
// Created by barto on 24.11.2025.
//

#ifndef TURBO_H
#define TURBO_H


#include "../Transmision.h"
#include "../Kodery/KoderTurbo.h"
#include "../Dekodery/DeKoderTurbo.h"
#include "../../Wynik.h"

class Turbo {
public:
    Turbo();
    KoderTurbo koderTurbo;
    DekoderTurbo dekoderTurbo;
    Transmision transmision;
    Wynik run(std::vector<bool> data);
};


#endif //TURBO_H
