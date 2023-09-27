//
#include <cmath>

int countBits(int number) {
    int count = 0;
    while (number) {
        count += number & 1;
        number >>= 1;
    }
    return count;
}

bool setBit(int &number, int order) {
    if (order > 31) {
        return false;
    }
    number |= 1 << order;
    return true;
}

double mean(double array[], int numElements) {
    if (numElements == 0) {
        return NAN;
    } else {
        double sum = 0;
        for (int i = 0; i < numElements; ++i) {
            sum += array[i];
        }
        return sum / numElements;
    }
}