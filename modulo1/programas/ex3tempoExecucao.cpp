#include <iostream>
#include <iomanip>
#include <chrono>
using namespace std;
using namespace chrono;

int main() {
    double s = 0.0;

    auto start = high_resolution_clock::now();

    for (int i = 1; i <= 100000000; ++i)
        s += 1.0 / i;

    auto end = high_resolution_clock::now();
    duration<double> elapsed = end - start;

    cout << fixed << setprecision(6);
    cout << "Resultado da soma: " << s << endl;
    cout << "Tempo de execução: " << elapsed.count() << " segundos" << endl;

    return 0;
}

