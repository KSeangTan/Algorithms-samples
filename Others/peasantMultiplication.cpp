#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int peasantMultiplication(int x, int y) {
    if (x == 0) {
        return 0;
    }
    //If odd number
    if (x % 2 != 0) {
        return y + peasantMultiplication(floor(x/2), y*2);
    } 
    return peasantMultiplication(floor(x/2), y*2);
}

