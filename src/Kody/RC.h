//
// Created by barto on 09.11.2025.
//

#ifndef RC_H
#define RC_H

#include "../Transmision.h"
#include "../Kodery/KoderRC.h"
#include "../Dekodery/DeKoderRC.h"
#include "../../Wynik.h"

class RC {
    public:
    RC();
    KoderRC koderRC;
    DekoderRC dekoderRC;
    Transmision transmision;
    Wynik run(std::vector<bool> data,int n);
};



#endif //RC_H
