#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n = 1000000;
    double soma_prog = 0.0, soma_regr = 0.0;
    double exato = 1.6449340668482264;
    for (int i = 1; i <= n; ++i) {
        double ii = static_cast<double>(i);
        soma_prog += 1.0 / (ii * ii);
    }

    for (int i = n; i >= 1; --i) {
        double ii = static_cast<double>(i);
        soma_regr += 1.0 / (ii * ii);
    }

    cout << fixed << setprecision(15);
    cout << "Soma progressiva: " << soma_prog << endl;
    cout << "Soma regressiva: " << soma_regr << endl;
    cout << "Erro progressivo: " << fabs(soma_prog - exato) << endl;
    cout << "Erro regressivo: " << fabs(soma_regr - exato) << endl;

    return 0;
}
