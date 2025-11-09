//
// Created by barto on 09.11.2025.
//

#ifndef RC_H
#define RC_H

#include "Transmision.h"
#include "Kodery/KoderRC.h"
#include "Dekodery/DeKoderRC.h"


class RC {
    public:
    RC();
    KoderRC koderRC;
    DekoderRC dekoderRC;
    Transmision transmision;
    void run(std::vector<bool> data);
};



#endif //RC_H
