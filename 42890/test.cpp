#include <iostream>
using namespace std;

int main(void) {
    int n = 1111;

    for (int i = 0; (1 << i) < 16; i++) {
        cout << i << ' ' << (1 << i) << endl;
    }
    return 0;
}