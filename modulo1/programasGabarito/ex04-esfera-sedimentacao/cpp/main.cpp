#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib> // para system()
using namespace std;

// Função da EDO
double dvdt(double v, double St, double Re) {
    return (1.0 - v - (3.0 / 8.0) * Re * v * v) / St;
}

// Runge-Kutta de 4ª ordem
void rk4(double &v, double t, double dt, double St, double Re) {
    double k1 = dt * dvdt(v, St, Re);
    double k2 = dt * dvdt(v + 0.5 * k1, St, Re);
    double k3 = dt * dvdt(v + 0.5 * k2, St, Re);
    double k4 = dt * dvdt(v + k3, St, Re);

    v += (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
}

int main() {
    // Parâmetros
    double St, Re;
    cout << "Qual o valor do número de Stokes? ";
    cin >> St;
    cout << "Qual o valor do número de Reynolds? ";
    cin >> Re;

    int npast = 1000 * St;
    double dt = St / 10.0;
    double eps = 3.0 * Re / 8.0;
    double t = 0.0, v = 0.0, ve = 0.0;

    // Arquivos de saída
    ofstream ana("solucao_analitica.dat");
    ofstream num("solucao_numerica.dat");

    ana << "Variables=\"U\",\"t\"\n";
    ana << "zone t=\"Solução Analítica\"\n";

    num << "Variables=\"U\",\"t\"\n";
    num << "zone t=\"Solução Numérica\"\n";

    for (int k = 0; k < npast; ++k) {
        // Solução analítica
        if (Re == 0.0) {
            ve = 1.0 - exp(-t / St);
        } else {
            double v_star = (-1.0 + sqrt(1.0 + (3.0 / 2.0) * Re)) / (0.75 * Re);
            double P = -(0.75 / St) * Re * v_star - 1.0 / St;
            double Q = (3.0 / 8.0) * (Re / St);
            ve = v_star + 1.0 / (Q / P + (-1.0 / v_star - Q / P) * exp(-P * t));
        }

        ana << ve << " " << t << endl;

        // Solução numérica
        rk4(v, t, dt, St, Re);
        num << v << " " << t << endl;

        t += dt;
    }

    ana.close();
    num.close();

    // Pós-processamento
    system("gnuplot plot.gnu");
    system("xdg-open grafico_sedimentacao.pdf");

    return 0;
}
