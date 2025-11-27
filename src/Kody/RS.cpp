//
// Created by barto on 24.11.2025.
//

#include "RS.h"

#include <cstdint>


RS::RS(){
}
//https://www.schifra.com/downloads.html
Wynik1 RS::run(std::vector<bool> data){
    Wynik1 wynikRS;
    std::vector<std::vector<bool>> dataBSC;
    std::vector<std::vector<bool>> dataGE;
    std::cout<<"dataBSC"<<std::endl;
    for (bool i : data) {
        std::cout<<i;
    }

    std::cout<<std::endl;
    // --- 1. Konwersja Bity -> Bajty ---
    std::vector<uint8_t> data1;
    int ammoutBytes = (data.size()+7)/8;
    data1.resize(ammoutBytes);

    for(int i = 0; i < ammoutBytes; i++) {
        uint8_t byte = 0;
        for(int j = 0; j < 8; j++) {
            int bit = i*8+j;
            byte <<= 1;
            if (bit < data.size() && data[bit]) {
                byte |= 1;
            }
        }
        data1[i] = byte;
    }
    wynikRS.original = data1;
    for (uint8_t i : wynikRS.original) {
        std::cout<<i;
    }
    std::cout<<std::endl;
    // --- 2. Kodowanie ---
    // Wynik to 255 bajtów (CODE_LENGTH)
    std::vector<uint8_t> Koder = koderRS.RS_koder(data1);

    // --- 3. Bajty -> Bity (dla kanału) ---
    // Musimy przekonwertować CAŁY blok zakodowany (255 bajtów), a nie data1!
    std::vector<std::vector<bool>> temp;
    for (uint8_t byte : Koder) { // Iterujemy po 'Koder' (255), nie 'data1'
        std::vector<bool> bits;
        for (int i = 7; i >= 0; --i) {
            bits.push_back((byte >> i) & 1);
        }
        temp.push_back(bits);
    }
    for (std::vector<bool> bits : temp) {
        for (bool i : bits) {
            std::cout<<i;
        }
    }
    std::cout<<std::endl;
    // --- 4. Symulacja kanału ---
    dataBSC = Transmision::BSCchannel(temp); // Zwraca 255 wektorów bitów
    // wynikRS.BSC = ... (opcjonalne mapowanie jeśli potrzebne)

    dataGE = Transmision::GEchannel(temp);   // Zwraca 255 wektorów bitów
    // wynikRS.GE = ...
    for (std::vector<bool> bits : dataBSC) {
        for (bool i : bits) {
            std::cout<<i;
        }
    }
    // --- 5. Bity -> Bajty (Odbiór) ---
    // Tu był błąd "Invalid block size". Musimy odebrać 255 bajtów.

    // Odbiór BSC
    std::vector<uint8_t> dataBSC_bytes(CODE_LENGTH, 0); // Rozmiar CODE_LENGTH!
    for (int i = 0; i < CODE_LENGTH; i++) {
        uint8_t byte = 0;
        for (int j = 0; j < 8; j++) {
            // Zakładam, że kanał nie zmienia długości wektora bitów (zawsze 8)
            // Jeśli kanał gubi bity, trzeba dodać sprawdzenie size()
            if (j < dataBSC[i].size() && dataBSC[i][j]) { // Prosta konwersja
                 // Uwaga: Twoja logika pakowania bitów (powyżej) była:
                 // MSB (i=7) -> push_back. Więc bit 0 w wektorze to MSB.
                 // Tutaj musimy to odtworzyć odwrotnie:
                 byte |= (1 << (7 - j));
            }
        }
        dataBSC_bytes[i] = byte;
    }

    // Odbiór GE (to samo - CODE_LENGTH)
    std::vector<uint8_t> dataGE_bytes(CODE_LENGTH, 0);
    for (int i = 0; i < CODE_LENGTH; i++) {
        uint8_t byte = 0;
        for (int j = 0; j < 8; j++) {
             if (j < dataGE[i].size() && dataGE[i][j]) {
                 byte |= (1 << (7 - j));
             }
        }
        dataGE_bytes[i] = byte;
    }
    std::cout<<"dataBSC"<<std::endl;
    for (uint8_t byte : dataBSC_bytes) {
        std::cout<<byte;
    }

    // --- 6. Dekodowanie ---
    wynikRS.DekodedGE = dekoderRS.RS_Dekoder(dataGE_bytes);
    wynikRS.DekodedBSC = dekoderRS.RS_Dekoder(dataBSC_bytes);

    return wynikRS;
}