//
// Created by barto on 15.10.2025.
//

#include "DekoderRC.h"

#include <cmath>
#include <iostream>
#include <ostream>
#include <vector>
DekoderRC::DekoderRC(){

}
//Repetition code
std::vector<std::vector<bool>> DekoderRC::RC_Dekoder(std::vector<std::vector<bool>> ch, int size) {
    std::vector<std::vector<bool>> full;
    for (std::vector ch2 : ch) {
        int sum = 0;
        for (bool ch3 : ch2) {
            std::cout << ch3 ;
            sum += ch3;
        }
        std::cout<<std::endl;
        int wiekszosc = (size/2)+1;
        bool bo = (sum >= wiekszosc);

        full.push_back({bo});
    }
    return full;
}
