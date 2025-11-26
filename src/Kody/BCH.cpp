//
// Created by barto on 24.11.2025.
//

#include "BCH.h"
BCH::BCH(){
}

Wynik BCH::run(std::vector<bool> data){
    Wynik BCH;
    std::vector<std::vector<bool>> dataBSC;
    std::vector<std::vector<bool>> dataGE;
    int K =3;
    int N= 7;
    std::vector<std::vector<bool>> original;
    for (int i = 0; i < data.size(); i+=K) {
        std::vector<bool> temp;
        for (int j = 0; j < K; j++) {
            if (i+j<data.size()) {
                temp.push_back(data[i+j]);
            }else {
                temp.push_back(false);
            }
        }
        original.push_back(temp);
    }
    BCH.original = original;

    std::vector<std::vector<bool> > koderout = koderBCH.BCH_koder(data);
    BCH.Koder = koderout;

    dataBSC = Transmision::BSCchannel(koderout);
    BCH.BSC = dataBSC;
    dataGE = Transmision::GEchannel(koderout);
    BCH.GE = dataGE;

    BCH.DekodedBSC = dekoderBCH.BCH_Dekoder(dataBSC);
    BCH.DekodedGE = dekoderBCH.BCH_Dekoder(dataGE);
    return BCH;
}
