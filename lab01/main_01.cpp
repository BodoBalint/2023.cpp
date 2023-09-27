#include <iostream>
#include "functions.h"


int main() {

    for (int i = 0; i < 128; ++i) {
        std::cout << i << ": " << countBits(i) << std::endl;
    }

    for (int i = 0; i < 35; ++i) {
        int n = 0;
        if (setBit(n, i)) {
            std::cout << i << " ---> " << n << std::endl;
        } else {
            std::cout << "Impossible operation!" << std::endl;
        }
    }

    double arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << "atlag: " << mean(arr, 10) << std::endl;

    return 0;
}