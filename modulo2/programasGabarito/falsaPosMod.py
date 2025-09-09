# -*- coding: utf-8 -*-
import numpy as np

def main():
    # Variáveis (float32 para emular 'real' simples do Fortran)
    xi  = np.float32(0.0)   # intervalo inferior
    xs  = np.float32(0.0)   # intervalo superior
    xi1 = np.float32(0.0)   # xi na iteração anterior
    xs1 = np.float32(0.0)   # xs na iteração anterior
    xm  = np.float32(0.0)   # ponto médio/estimativa atual
    xm1 = np.float32(0.0)   # ponto médio anterior

    f1 = np.float32(0.0)
    f2 = np.float32(0.0)
    f3 = np.float32(0.0)
    produto = np.float32(0.0)
    erro = np.float32(0.0)
    tol  = np.float32(0.0)
    delta = np.float32(0.0)

    iter = 0
    opcao = 0
    contador1 = 0
    contador2 = 0

    print('================================================================================')
    print('*                                                                              *')
    print('*                   L2C : SOLUÇÕES EM COMPUTAÇÃO CIENTÍFICA                    *')
    print('*                                                                              *')
    print('================================================================================')
    print('* Programa: RAÍZES DE EQUAÇÕES – FALSA POSIÇÃO MODIFICADO                      *')
    print('* Capítulo: 02 | Exemplo: 02                                                   *')
    print('*                                                                              *')
    print('* Repositório: Manual de Cálculo Numérico – Códigos de Apoio (L2C)             *')
    print('* Curso: Do Cálculo à Simulação Computacional                                  *')
    print('*                                                                              *')
    print('*        https://github.com/l2c-dev/manual-calculo-numerico.git                *')
    print('================================================================================')
    print('')
    print('================================================================================')
    print('*                                                                              *')
    print('* Esse programa resolve a equação algébrica x**10 - 1.0.                       *')
    print('* Nesse caso, a solução exata é dada por x = 1.                                *')
    print('* A ideia é mostrar como o método da falsa posição pode ficar preso em uma das *')
    print('* extremidades dependendo da cara da função, cujo zero estamos buscando.       *')
    print('* Teste usar o seguinte intervalo de busca inicial=[0,1.8].                    *')
    print('* Compare o desempenho do método da bissecção com o método da falsa posição.   *')
    print('* Em seguida, teste o método da falsa posição modificado com um kick = 0.06    *')
    print('*                                                                              *')
    print('* Quais são suas conclusões?                                                   *')
    print('================================================================================')
    print('')
    print('================================================================================')
    print('*                           SELEÇÃO DE MÉTODO                                  *')
    print('================================================================================')
    print('* Escolha agora o método a ser utilizado:                                      *')
    print('*                                                                              *')
    print('*   [1] Método da bissecção                                                    *')
    print('*   [2] Método da falsa posição                                                *')
    print('*   [3] Método da falsa posição modificado                                     *')
    print('*                                                                              *')
    print('================================================================================')
    print('Digite o número do método desejado: ')
    opcao = int(input().strip())
    print('')
    print('================================================================================')
    print('*                 INTERVALO INICIAL DE BUSCA                                   *')
    print('================================================================================')
    print('Digite agora o extremo inferior do intervalo inicial de busca (xi):')
    xi = np.float32(input().strip())
    print('Digite agora o extremo superior do intervalo inicial de busca (xs):')
    xs = np.float32(input().strip())
    print('*                                                                              *')
    if opcao == 3:
        print('*Digite a intensidade do kick utilizado para desprender extremidades:        *')
        delta = np.float32(input().strip())
    print('================================================================================')
    print('')

    if   opcao == 1:
        print('O método escolhido é o método da bisecção')
    elif opcao == 2:
        print('O método escolhido é o método da falsa posição')
    elif opcao == 3:
        print('O método escolhido é o método da falsa posição modificado')
    else:
        print('Opção inválida.')
    print('')
    print('================================================================================')
    print('*         IMPRIMINDO VARIÁVEIS DE MONITORAMENTO: iter, xi, xs, xr, erro        *')
    print('================================================================================')

    erro = np.float32(np.abs(xi - xs))
    tol  = np.float32(1.0e-06)
    iter = 0
    contador1 = 1
    contador2 = 1

    # Função utilitária para imprimir na formatação do Fortran:
    # (I4,5X,F13.9,5X,F13.9,5X,F13.9,5X,F13.9)
    def imprime_linha(iter_, xi_, xs_, xm_, erro_):
        # Inteiro largura 4
        s = f"{int(iter_):4d}"
        # 5 espaços + F13.9
        s += " " * 5 + f"{float(xi_):13.9f}"
        s += " " * 5 + f"{float(xs_):13.9f}"
        s += " " * 5 + f"{float(xm_):13.9f}"
        s += " " * 5 + f"{float(erro_):13.9f}"
        print(s)

    while erro > tol:
        imprime_linha(iter, xi, xs, xm, erro)

        xm1 = xm

        # f(x) = x**10 - 1.0 (em float32)
        f1 = np.float32(xi ** np.float32(10.0)) - np.float32(1.0)  # f(xi)
        f2 = np.float32(xs ** np.float32(10.0)) - np.float32(1.0)  # f(xs)

        # Produto nas extremidades
        produto = np.float32(f1 * f2)

        # Checando mudança de sinal
        if produto < np.float32(0.0):
            if opcao == 1:
                # Bissecção
                xm = np.float32((xi + xs) * np.float32(0.5))
            if opcao == 2:
                # Falsa posição
                xm = np.float32(xs - (f2 * (xi - xs) / (f1 - f2)))
            if opcao == 3:
                # Falsa posição modificada
                xi1 = xi
                xs1 = xs

                # Verificando extremidade presa
                if contador1 == 2:
                    xi = np.float32(xi + delta)
                    contador1 = 1
                if contador2 == 2:
                    xs = np.float32(xs - delta)
                    contador2 = 1

                # Falsa posição
                xm = np.float32(xs - (f2 * (xi - xs) / (f1 - f2)))

            # f(xm)
            f3 = np.float32(xm ** np.float32(10.0)) - np.float32(1.0)

            # Atualiza intervalo
            produto = np.float32(f1 * f3)
            if produto < np.float32(0.0):
                xs = xm
            else:
                xi = xm

        if opcao == 3:
            # Atualizando contadores de repetição
            if xi1 == xi:
                contador1 = contador1 + 1
            if xs1 == xs:
                contador2 = contador2 + 1

        erro = np.float32(np.abs(xm1 - xm))
        iter = iter + 1

if __name__ == "__main__":
    main()
