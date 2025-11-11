//
// Created by barto on 09.11.2025.
//

#ifndef TRANSMISION_H
#define TRANSMISION_H
#include <vector>


class Transmision {
    public:
    std::vector<bool> static BSCchannel(std::vector<bool> content);
    std::vector<bool> static GEchannel(std::vector<bool> content);
};



#endif //TRANSMISION_H
