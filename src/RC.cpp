//
// Created by barto on 09.11.2025.
//

#include "RC.h"

#include "Transmision.h"
#include "Kodery/KoderRC.h"
#include "Dekodery/DekoderRC.h"
RC::RC(){
}

void RC::run(std::vector<bool> data){
    data = koderRC.RC_koder(data);
    data = transmision.BSCchannel(data);
    data = dekoderRC.RC_Dekoder(data);

}