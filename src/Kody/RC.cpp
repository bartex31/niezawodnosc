//
// Created by barto on 09.11.2025.
//

#include "RC.h"

#include "../Transmision.h"
#include "../Kodery/KoderRC.h"
#include "../Dekodery/DekoderRC.h"
RC::RC(){
}

Wynik RC::run(std::vector<bool> data, int n){
    std::vector<std::vector<bool>> dataBSC;
    std::vector<std::vector<bool>> dataGE;
    std::vector<std::vector<bool>> origin;

    Wynik RC;

    int size =n;
    for(int i=0;i<data.size();i++) {
        std::vector<bool> temp;
        temp.push_back(data[i]);
        origin.push_back(temp);
    }
    RC.original = origin;

    std::vector<std::vector<bool>> koder;
    koder = koderRC.RC_koder(origin,size);
    RC.Koder = koder;

    dataBSC = Transmision::BSCchannel(koder);
    RC.BSC = dataBSC;
    dataGE = Transmision::GEchannel(koder);
    RC.GE = dataGE;

    RC.DekodedBSC = dekoderRC.RC_Dekoder(dataBSC,size);


    RC.DekodedGE = dekoderRC.RC_Dekoder(dataGE,size);
    return RC;
}