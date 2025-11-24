//
// Created by barto on 09.11.2025.
//

#include "RC.h"

#include "../Transmision.h"
#include "../Kodery/KoderRC.h"
#include "../Dekodery/DekoderRC.h"
RC::RC(){
}

Wynik RC::run(std::vector<bool> data){
    Wynik RC;

    data = koderRC.RC_koder(data);
    RC.original = data;
    data = transmision.BSCchannel(data);
    RC.BSC = data;
    data = transmision.GEchannel(data);
    RC.GE = data;
    data = dekoderRC.RC_Dekoder(data);
    RC.Dekoded = data;
    return RC;
}