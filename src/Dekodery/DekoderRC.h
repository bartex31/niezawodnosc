//
// Created by barto on 15.10.2025.
//

#ifndef DEKODERRC_H
#define DEKODERRC_H

#include <vector>

class DekoderRC {
public:
      DekoderRC();
      std::vector<std::vector<bool>> RC_Dekoder(std::vector<std::vector<bool>> ch, int size);
};



#endif //DEKODERRC_H
