//
// Created by barto on 24.11.2025.
//

#include "BCH.h"
BCH::BCH(){
}

Wynik BCH::run(std::vector<bool> data){
    Wynik BCH;

    data = koderBCH.BCH_koder(data);
    BCH.original = data;
    data = transmision.BSCchannel(data);
    BCH.BSC = data;
    data = transmision.GEchannel(data);
    BCH.GE = data;
    data = dekoderBCH.BCH_Dekoder(data);
    BCH.Dekoded = data;
    return BCH;
}