<p align="center">
  <img src="../../../figs/logo-l2c.png" alt="L2C" width="240"/>
</p>

<h1> </h1>

# 🧪 Exemplo 02 – Problema clássico do método da falsa posição e sua versão modificada

**Capítulo:** Capítulo 2 – Raízes de equações

**Propósito:** Demonstrar um caso típico em que o **método da falsa posição (regula falsi)** apresenta desempenho inferior ao método da bissecção devido à natureza da função e, em seguida, apresentar uma **versão modificada do método**, aplicando um deslocamento (*kick*) para corrigir o problema.

---

# 📘 O que esse exemplo explora?

Este exemplo aborda a localização de raízes para a função:

$$
f(x) = x^{10} - 1
$$

Embora a solução exata seja $x = 1$, a função apresenta derivadas muito intensas próximas à raiz, o que pode **prender uma das extremidades do intervalo** durante a aplicação do método da falsa posição. Isso leva a uma convergência lenta ou estagnação, enquanto o **método da bissecção** continua avançando regularmente.

Para contornar esse problema, propomos uma variação simples do método da falsa posição: quando detectamos que uma extremidade não se move por duas iterações consecutivas, aplicamos um **pequeno deslocamento forçado (kick)** nessa extremidade, forçando a atualização do intervalo e melhorando o desempenho do método.

---

## ⚙️ Scripts e sua função

- **`main.f90` / `main.cpp` / `main.py`**  
  Implementações do exemplo em **FORTRAN**, **C++** e **Python**, respectivamente.  
  Todos apresentam:
  - Menu para seleção do método: bissecção, falsa posição tradicional ou falsa posição modificada;
  - Entrada interativa do intervalo inicial `[xi, xs]` (sugestão inicial: `[0, 1.8]`);
  - Entrada do valor do deslocamento (*kick*) quando escolhido o método modificado (sugestão: `0.08`);
  - Impressão no terminal das variáveis de monitoramento por iteração:
    ```
    iter    xi          xs          xr          erro
    ```
    no formato `(I4,5X,F13.9,5X,F13.9,5X,F13.9,5X,F13.9)`.

---

## 🧠 Aspectos Teóricos

- **Método da Bissecção:**  
  Divide o intervalo ao meio a cada iteração. Convergência linear, robusto, garantido para funções contínuas com mudança de sinal.

- **Método da Falsa Posição:**  
  Usa interpolação linear para estimar a raiz, geralmente mais rápido que a bissecção.  
  Porém, pode estagnar quando uma extremidade do intervalo se torna pouco influente (como em `x^{10}-1` perto de `x=1`).

- **Método da Falsa Posição Modificado:**  
  Introduz um deslocamento manual (*kick*) numa extremidade que permanece fixa por duas iterações consecutivas. Isso força a atualização da estimativa e acelera a convergência para certos problemas.

---

## 📂 Características do exemplo

- Este exemplo é **compilado e executado diretamente** (por exemplo, `gfortran main.f90 -o main && ./main`) sem uso de scripts auxiliares de limpeza ou execução.
- **Não gera arquivos de saída nem gráficos** automaticamente, pois o foco é o entendimento do comportamento dos métodos diretamente no terminal.
- O usuário é incentivado a:
  - **Testar diferentes intervalos de busca**, observando o desempenho relativo dos métodos;
  - **Experimentar diferentes intensidades de kick** (sugestão inicial: `0.08`) e analisar como isso afeta a convergência;
  - **Comparar o número de iterações** entre bissecção, falsa posição e falsa posição modificada.

---

## 💡 Desafios propostos

Como exercício, tente modificar o código para:

1. **Varredura automática** de intervalos de busca para cada método, coletando número de iterações e erros.
2. **Armazenar resultados em arquivos `.dat`**, permitindo posterior análise quantitativa.
3. **Criar gráficos** (por exemplo, em Gnuplot ou Python/Matplotlib) comparando a performance dos três métodos para diferentes intervalos e kicks aplicados.
4. Explorar funções alternativas com comportamento semelhante ao de $x^{10}-1$ para reforçar o aprendizado.

---

## 👨‍🏫 Autor

**Prof. Rafael Gabler Gontijo, PhD**  
[L2C – Soluções em Computação Científica](http://l2c.dev.br)  
Curso: *Do Cálculo à Simulação Computacional*  
[GitHub L2C](https://github.com/l2c-dev/manual-calculo-numerico)

---

✅ Este exemplo acompanha a apostila *“Do Cálculo à Simulação Computacional – Manual Prático”*, produto digital da L2C.

---
