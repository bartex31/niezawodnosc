#include <algorithm>
#include <iostream>
#include <bitset>
#include <vector>

std::string data = "cccccccccc";

std::vector<char> ASCIConverter(std::string s) {
    int convert;
    std::vector<char> v;
    std::string result;
    for (char c : s) {
        std::bitset<8> bitset(c);
        result = bitset.to_string();
        std::cout << result << std::endl;
        for (char c : result) {
            v.push_back(c);
        }
        result.erase(std::remove(result.begin(), result.end(), ' '), result.end());
    }

    return v;
}


//Binary symmetric channel https://en.wikipedia.org/wiki/Binary_symmetric_channel
std::vector<bool> BSCchannel(std::vector<char> ch) {

}

//Gilberta-Elliotta https://en.wikipedia.org/wiki/Burst_error
std::vector<bool> GEchannel(std::vector<char> ch) {

}


int main() {
    std::vector<char> out =ASCIConverter(data);
    int x=0, y=0;
    for (int i = 0; i < out.size(); i++) {

        std::cout << out[i];
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
    return 0;
}