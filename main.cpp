#include <algorithm>
#include <iostream>
#include <bitset>
#include <vector>
#include <random>
#include "Wynik.h"
std::string data = "test";

std::vector<bool> ASCIConverter(std::string s) {
    std::vector<bool> converted;
    for (char c : s) {
        std::bitset<8> bits(c);
        for (int i = 7; i >=0; i--) {
            converted.push_back(bits.test(i));
        }
    }
    return converted;
}

void compare(std::vector<bool> &original, const std::vector<bool>& converted) {
   // std::vector<std::string> convertedStrings;
    for (int i = 0; i < original.size(); i++) {
        if (original[i] != converted[i]) {
            std::cout<<"F";
            //convertedStrings.push_back(converted[i-1]+(converted[i]+(converted[i+1])
        }else std::cout<<"T";

    }
}



void displayWynik(Wynik wynik) {
    for (int i =0; i < wynik.original.size(); i++) {
        std::cout << wynik.original[i];
    }
    std::cout << std::endl;
    for (int i =0; i < wynik.GE.size(); i++) {
        std::cout << wynik.GE[i];
    }
    std::cout << std::endl;
    for (int i =0; i < wynik.BSC.size(); i++) {
        std::cout << wynik.BSC[i];
    }
}

#include "src/Kody/RC.h"
int main() {
    RC rc;

    Wynik wynikRC;
    std::vector<bool> gen =ASCIConverter(data);
    wynikRC = rc.run(gen);




    displayWynik(wynikRC);

    //ECCcoder(gen);
    return 0;
}

// void ECCcoder(std::vector<bool> gen) {
//     std::vector<bool> ECC;
//     std::vector<bool> ECCDek;
//     std::vector<bool> out;
//     std::cout << "dane:" << std::endl;
//     std::vector<std::vector<bool>> dane8;
//     display(gen);
//
//     // for (bool ch : gen) {
//     //     ECC.emplace_back(koder.RC_koder(ch));
//     // }
//     ECC = koder.RC_koder(gen);
//
//
//     out.reserve(gen.size());
//     for (bool c : ECC) {
//         out.push_back(BSCchannel(c));
//     }
//     std::cout << "dane na odbiorze:" << std::endl;
//     display(out);
//
//     ECCDek = dekoder.RC_dekoder(out);
//     std::cout << "dane po dekoderze:" << std::endl;
//     display(ECCDek);
//
//     compare(gen, ECCDek);
// }
//
// std::vector<char> BCH_dekoder(std::vector<char> ch) {
//
// }
//
// std::vector<char> RS_dekoder(std::vector<char> ch) {
//
// }
//
// std::vector<char> LDP_dekoder(std::vector<char> ch) {
//
// }
//
// std::vector<char> Turbo_dekoder(std::vector<char> ch) {
//
// }
//
// std::vector<char> Fountain_dekoder(std::vector<char> ch) {
//
// }


// std::vector<char> BCH_koder(std::vector<char> ch) {
//
// }
//
// std::vector<char> RS_koder(std::vector<char> ch) {
//
// }
//
// std::vector<char> LDP_koder(std::vector<char> ch) {
//
// }
//
// std::vector<char> Turbo_koder(std::vector<char> ch) {
//
// }
//
// std::vector<char> Fountain_koder(std::vector<char> ch) {
//
// }