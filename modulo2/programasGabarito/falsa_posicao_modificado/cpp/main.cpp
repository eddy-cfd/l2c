#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

int main() {
    using std::cout;
    using std::cin;
    using std::endl;

    // Variáveis (float para reproduzir o "real" simples do Fortran)
    float xi = 0.0f, xs = 0.0f;     // intervalo inferior e superior
    float xi1 = 0.0f, xs1 = 0.0f;   // intervalos na iteração anterior
    float xm = 0.0f, xm1 = 0.0f;    // ponto médio atual e anterior
    float f1 = 0.0f, f2 = 0.0f, f3 = 0.0f; // valores da função
    float produto = 0.0f;
    float erro = 0.0f;
    float tol = 0.0f;
    float delta = 0.0f;             // kick usado para desprender extremidades
    int iter = 0;
    int opcao = 0;
    int contador1 = 0, contador2 = 0;

    cout << "================================================================================" << endl;
    cout << "*                                                                              *" << endl;
    cout << "*                   L2C : SOLUÇÕES EM COMPUTAÇÃO CIENTÍFICA                    *" << endl;
    cout << "*                                                                              *" << endl;
    cout << "================================================================================" << endl;
    cout << "* Programa: RAÍZES DE EQUAÇÕES – FALSA POSIÇÃO MODIFICADO                      *" << endl;
    cout << "* Capítulo: 02 | Exemplo: 02                                                   *" << endl;
    cout << "*                                                                              *" << endl;
    cout << "* Repositório: Manual de Cálculo Numérico – Códigos de Apoio (L2C)             *" << endl;
    cout << "* Curso: Do Cálculo à Simulação Computacional                                  *" << endl;
    cout << "*                                                                              *" << endl;
    cout << "*        https://github.com/l2c-dev/manual-calculo-numerico.git                *" << endl;
    cout << "================================================================================" << endl;
    cout << "" << endl;
    cout << "================================================================================" << endl;
    cout << "*                                                                              *" << endl;
    cout << "* Esse programa resolve a equação algébrica x**10 - 1.0.                       *" << endl;
    cout << "* Nesse caso, a solução exata é dada por x = 1.                                *" << endl;
    cout << "* A ideia é mostrar como o método da falsa posição pode ficar preso em uma das *" << endl;
    cout << "* extremidades dependendo da cara da função, cujo zero estamos buscando.       *" << endl;
    cout << "* Teste usar o seguinte intervalo de busca inicial=[0,1.8].                    *" << endl;
    cout << "* Compare o desempenho do método da bissecção com o método da falsa posição.   *" << endl;
    cout << "* Em seguida, teste o método da falsa posição modificado com um kick = 0.06    *" << endl;
    cout << "*                                                                              *" << endl;
    cout << "* Quais são suas conclusões?                                                   *" << endl;
    cout << "================================================================================" << endl;
    cout << "" << endl;
    cout << "================================================================================" << endl;
    cout << "*                           SELEÇÃO DE MÉTODO                                  *" << endl;
    cout << "================================================================================" << endl;
    cout << "* Escolha agora o método a ser utilizado:                                      *" << endl;
    cout << "*                                                                              *" << endl;
    cout << "*   [1] Método da bissecção                                                    *" << endl;
    cout << "*   [2] Método da falsa posição                                                *" << endl;
    cout << "*   [3] Método da falsa posição modificado                                     *" << endl;
    cout << "*                                                                              *" << endl;
    cout << "================================================================================" << endl;
    cout << "Digite o número do método desejado: " << endl;
    cin  >> opcao;
    cout << "" << endl;
    cout << "================================================================================" << endl;
    cout << "*                 INTERVALO INICIAL DE BUSCA                                   *" << endl;
    cout << "================================================================================" << endl;
    cout << "Digite agora o extremo inferior do intervalo inicial de busca (xi):" << endl;
    cin  >> xi;
    cout << "Digite agora o extremo superior do intervalo inicial de busca (xs):" << endl;
    cin  >> xs;
    cout << "*                                                                              *" << endl;
    if (opcao == 3) {
        cout << "*Digite a intensidade do kick utilizado para desprender extremidades:        *" << endl;
        cin  >> delta;
    }
    cout << "================================================================================" << endl;
    cout << "" << endl;

    switch (opcao) {
        case 1:
            cout << "O método escolhido é o método da bisecção" << endl;
            break;
        case 2:
            cout << "O método escolhido é o método da falsa posição" << endl;
            break;
        case 3:
            cout << "O método escolhido é o método da falsa posição modificado" << endl;
            break;
        default:
            cout << "Opção inválida." << endl;
            break;
    }

    cout << "" << endl;
    cout << "================================================================================" << endl;
    cout << "*         IMPRIMINDO VARIÁVEIS DE MONITORAMENTO: iter, xi, xs, xr, erro        *" << endl;
    cout << "================================================================================" << endl;

    erro = std::fabs(xi - xs);
    tol  = 1.0e-06f;
    iter = 0;
    contador1 = 1;
    contador2 = 1;

    while (erro > tol) {
        // Formato: (I4,5X,F13.9,5X,F13.9,5X,F13.9,5X,F13.9)
        cout << std::setw(4) << iter
             << std::string(5, ' ')
             << std::setw(13) << std::fixed << std::setprecision(9) << xi
             << std::string(5, ' ')
             << std::setw(13) << std::fixed << std::setprecision(9) << xs
             << std::string(5, ' ')
             << std::setw(13) << std::fixed << std::setprecision(9) << xm
             << std::string(5, ' ')
             << std::setw(13) << std::fixed << std::setprecision(9) << erro
             << endl;

        xm1 = xm;

        // f(x) = x**10 - 1.0
        f1 = std::pow(xi, 10.0f) - 1.0f; // f(xi)
        f2 = std::pow(xs, 10.0f) - 1.0f; // f(xs)

        // Produto f(xi)*f(xs)
        produto = f1 * f2;

        // Checando mudança de sinal
        if (produto < 0.0f) {
            if (opcao == 1) {
                // Bissecção
                xm = (xi + xs) * 0.5f;
            }

            if (opcao == 2) {
                // Falsa posição
                xm = xs - (f2 * (xi - xs) / (f1 - f2));
            }

            if (opcao == 3) {
                // Falsa posição modificada
                xi1 = xi;
                xs1 = xs;

                // Verificando extremidade presa
                if (contador1 == 2) {
                    xi += delta;
                    contador1 = 1;
                }
                if (contador2 == 2) {
                    xs -= delta;
                    contador2 = 1;
                }

                // Falsa posição
                xm = xs - (f2 * (xi - xs) / (f1 - f2));
            }

            // f(xm)
            f3 = std::pow(xm, 10.0f) - 1.0f;

            // Novo produto para atualizar o intervalo
            produto = f1 * f3;

            if (produto < 0.0f) {
                xs = xm;
            } else {
                xi = xm;
            }
        }

        if (opcao == 3) {
            // Atualizando contadores de repetição das extremidades
            if (xi1 == xi) {
                contador1 = contador1 + 1;
            }
            if (xs1 == xs) {
                contador2 = contador2 + 1;
            }
        }

        erro = std::fabs(xm1 - xm);
        iter = iter + 1;
    }

    return 0;
}
