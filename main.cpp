#include <algorithm>
#include <iostream>
#include <bitset>
#include <vector>
#include <random>

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




//Gilberta-Elliotta https://en.wikipedia.org/wiki/Burst_error
// std::vector<bool> GEchannel(std::vector<char> ch){
// return ;
// }

void display(std::vector<bool> ch) {
    int x=0, y=0;
    for (int i = 0; i < ch.size(); i++) {

        std::cout << ch[i];
        x++;
        if (x==8) {
            x=0;
            std::cout << " ";
            y++;
        }
        if (y==8) {
            y=0;
            std::cout <<std::endl;
        }
    }
    std::cout << std::endl;
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
std::vector<std::vector<bool>> group(std::vector<bool> original, int groupSize) {
    std::vector<std::vector<bool>> groups;
    std::vector<bool> converted;
    for (int i = 0; i < original.size(); i+=groupSize) {
        for (int j = 0; j < groupSize; j++) {
            converted.emplace_back(original[i+j]);
        }
        groups.emplace_back(converted);
        converted.clear();
    }
    return groups;
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
void Rc(std::vector<bool> input) {
    std::vector<std::vector<bool>> grouped = group(input, 8);
    for (std::vector<bool> ch : grouped) {
        for (bool c : ch) {
            std::cout << c;
        }
        std::cout << std::endl;
    }
}

#include "src/RC.h"
int main() {
    std::vector<bool> gen =ASCIConverter(data);
    display(gen);

    RC rc;
    rc.run(gen);
        
    //ECCcoder(gen);
    return 0;
}


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