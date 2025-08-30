#include <iostream>
using namespace std;

int main() {
    double eps = 1.0;
    while (1.0 + eps != 1.0) {
        eps /= 2.0;
    }
    eps *= 2.0;
    cout.precision(20);
    cout << "Zero de máquina aproximado: " << eps << endl;
    return 0;
}
