//
// Created by barto on 24.11.2025.
//

#ifndef RS_H
#define RS_H

#include "../Transmision.h"
#include "../Kodery/KoderRS.h"
#include "../Dekodery/DeKoderRS.h"
#include "../../Wynik1.h"

class RS {
public:
    RS();
    KoderRS koderRS;
    DekoderRS dekoderRS;
    Transmision transmision;
    Wynik1 run(std::vector<bool> data1);
};


#endif //RS_H
