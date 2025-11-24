//
// Created by barto on 24.11.2025.
//

#include "Turbo.h"
Turbo::Turbo(){
}

Wynik Turbo::run(std::vector<bool> data){
    Wynik Turbo;

    data = koderTurbo.Turbo_koder(data);
    Turbo.original = data;
    data = transmision.BSCchannel(data);
    Turbo.BSC = data;
    data = transmision.GEchannel(data);
    Turbo.GE = data;
    data = dekoderTurbo.Turbo_Dekoder(data);
    Turbo.Dekoded = data;
    return Turbo;
}