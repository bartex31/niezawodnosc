#include <algorithm>
#include <iostream>
#include <bitset>
#include <fstream>
#include <vector>
#include <random>
#include "Wynik.h"

std::vector<bool> generate_random_bits(int n) {
    std::vector<bool> bits(n, false);
    for (int i = 0; i < n; i++) {
        bits[i] = rand() % 2;
    }
    return bits;
}

double compare(std::vector<std::vector<bool>> &original, const std::vector<std::vector<bool>>& converted) {
   // std::vector<std::string> convertedStrings;
    int k = 0;
    int counter = 0;
    for (int i = 0; i < original.size(); i++) {

        for (int j = 0; j < original[i].size(); j++) {

            if (original[i][j] != converted[i][j]) {
            }else {
                k+=1;
            }
            counter+=1;
        }
    }


    std::cout <<  original.size() <<std::endl;
    double j = k/static_cast<double>(counter);
    std::cout << j << std::endl;
    return j;
}



void displayWynik(Wynik wynik) {

    for (std::vector<bool> b : wynik.original) {
        for (bool v : b) {
            std::cout << v;
        }
    }
    std::cout << std::endl;
    for (std::vector<bool> b : wynik.Koder) {
        for (bool v : b) {
            std::cout << v;
        }
    }
    std::cout << std::endl;
    for (std::vector<bool> b : wynik.GE) {
        for (bool v : b) {
            std::cout << v;
        }
    }
    std::cout << std::endl;
    for (std::vector<bool> b : wynik.BSC) {
        for (bool v : b) {
            std::cout << v;
        }
    }
    std::cout << std::endl;
    for (std::vector<bool> b : wynik.DekodedGE) {
        for (bool v : b) {
            std::cout << v;
        }
    }
    std::cout << std::endl;
    for (std::vector<bool> b : wynik.DekodedBSC) {
        for (bool v : b) {
            std::cout << v;
        }
    }
    std::cout << std::endl;
}
#include "src/Kody/RC.h"

void RCrun(){
    RC rc;

    Wynik wynikRC;

    std::ofstream outfile("wyniki_RC.csv");
    outfile << "N_Repetition;L_Message_Length;BSC_Reliability;GE_Reliability\n";
    int i=0,j=1;
    for (i = 4; i<5; i++) {
        for ( j = 20; j < 21; j++) {
            std::vector<bool> gen =generate_random_bits(j);
            std::cout<<"wynik dla n:"<<i<<std::endl;
            wynikRC = rc.run(gen,i);

            std::cout<<"BSC ";
            //displayWynik(wynikRC);
            compare(wynikRC.original,wynikRC.DekodedBSC);
            std::cout<<"GE ";
            compare(wynikRC.original,wynikRC.DekodedGE);
            std::cout<<std::endl;

            outfile << i << ";"
                    << j<< ";"
                    << compare(wynikRC.original,wynikRC.DekodedBSC) << ";"
                    << compare(wynikRC.original,wynikRC.DekodedGE) << "\n";
        }
    }
    outfile.close();
}
#include "src/Kody/BCH.h"
void BCHRun() {
    BCH bch;
    std::vector<bool> gen =generate_random_bits(20);
    Wynik Bchwynik = bch.run(gen);
    std::cout<<"BSC ";
    //displayWynik(wynikRC);
    compare(Bchwynik.original,Bchwynik.DekodedBSC);
    std::cout<<"GE ";
    compare(Bchwynik.original,Bchwynik.DekodedGE);
    std::cout<<std::endl;
    displayWynik(Bchwynik);
}
#include "src/Kody/RS.h"
#include "Wynik1.h"
void RSrun() {
    RS rs;
    Wynik1 wynikRS;
    std::vector<bool> gen =generate_random_bits(13);
    wynikRS = rs.run(gen);


}

int main() {
    //RCrun();
    //BCHRun();
    RSrun();
    return 0;
}

//
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