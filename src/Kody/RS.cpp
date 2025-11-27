//
// Created by barto on 24.11.2025.
//

#include "RS.h"

#include <bitset>
#include <cstdint>

std::vector<std::vector<bool>> bytesToBools(const std::vector<uint8_t>& bytes) {
    std::vector<std::vector<bool>> result;
    for (uint8_t byte : bytes) {
        std::vector<bool> bits;
        for (int i = 7; i >= 0; --i) {
            bits.push_back((byte >> i) & 1);
        }
        result.push_back(bits);
    }
    return result;
}
std::vector<uint8_t> boolsToBytes(const std::vector<bool>& bits) {
    int n = (bits.size() + 7) / 8;
    std::vector<uint8_t> bytes(n, 0);

    for (int i = 0; i < n; ++i) {
        uint8_t byte = 0;
        for (int j = 0; j < 8; ++j) {
            int index = i * 8 + j;
            byte <<= 1;
            if (index < bits.size() && bits[index]) {
                byte |= 1;
            }
        }
        bytes[i] = byte;
    }
    return bytes;
}
std::vector<uint8_t> vectorBoolToBytes(const std::vector<std::vector<bool>>& vv) {
    std::vector<uint8_t> bytes(vv.size(), 0);
    for (size_t i = 0; i < vv.size(); ++i) {
        uint8_t byte = 0;
        for (size_t j = 0; j < vv[i].size(); ++j) {
            byte <<= 1;
            if (vv[i][j]) byte |= 1;
        }
        bytes[i] = byte;
    }
    return bytes;
}

RS::RS(){
}
//https://www.schifra.com/downloads.html
Wynik1 RS::run(std::vector<bool> data1) {
    std::vector<bool> data = {1,0,1,0,1,1,0,1};
    Wynik1 wynikRS;

    std::vector<uint8_t> dataBytes = boolsToBytes(data);
    wynikRS.original = dataBytes;
    std::cout << std::endl;
    std::vector<uint8_t> Koder = koderRS.RS_koder(dataBytes);
    std::vector<std::vector<bool>> temp = bytesToBools(Koder);

    std::vector<std::vector<bool>> dataBSC = Transmision::BSCchannel(temp);
    std::vector<std::vector<bool>> dataGE  = Transmision::GEchannel(temp);

    std::vector<uint8_t> dataBSC_bytes = vectorBoolToBytes(dataBSC);
    std::vector<uint8_t> dataGE_bytes  = vectorBoolToBytes(dataGE);

    std::vector<uint8_t> decodedBSC = dekoderRS.RS_Dekoder(dataBSC_bytes);
    std::vector<uint8_t> decodedGE  = dekoderRS.RS_Dekoder(dataGE_bytes);

    wynikRS.DekodedBSC = bytesToBools(decodedBSC);
    wynikRS.DekodedGE  = bytesToBools(decodedGE);
    std::cout << std::endl;
    return wynikRS;
}