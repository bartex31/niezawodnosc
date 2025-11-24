//
// Created by barto on 24.11.2025.
//

#include "RS.h"


RS::RS(){
}

Wynik RS::run(std::vector<bool> data){
    Wynik RS;

    data = koderRS.RS_koder(data);
    RS.original = data;
    data = transmision.BSCchannel(data);
    RS.BSC = data;
    data = transmision.GEchannel(data);
    RS.GE = data;
    data = dekoderRS.RS_Dekoder(data);
    RS.Dekoded = data;
    return RS;
}