//
// Created by barto on 26.11.2025.
//


//https://arxiv.org/pdf/1504.03916
#include "KoderPolar.h"

#include <iostream>

void polarKernel(int& x,int& y) {
    x = x ^ y;

}
void polarRecursiveKernel(std::vector<int>& x, int n, int start) {
    if (n ==1) {
        return;
    }
    int halfn = n/2;
    polarRecursiveKernel(x, halfn, start);
    polarRecursiveKernel(x, halfn, start+halfn);

    for (int i = 0; i < halfn; i++) {
        int u =x[start+i];
        int u2 = x[start+i+halfn];

        x[start+i] = u^u2;
    }
}

KoderPolar::KoderPolar() {

}


