
<p align="center">
  <img src="../../../figs/logo-l2c.png" alt="L2C" width="240"/>
</p>

<h1> </h1>

# 🧪 Exemplo 04 – Sedimentação de uma esfera em baixo Reynolds

**Capítulo:** Capítulo 1 – Introdução, história, generalidades e motivação

**Propósito:** Resolver numericamente o problema de uma esfera sedimentando em um fluido viscoso em baixo Reynolds, comparando a solução numérica com a solução analítica.

---

## 📘 Fundamentos Teóricos

O problema modela a velocidade de uma partícula esférica caindo sob a ação da gravidade em um fluido viscoso, com arrasto dependente do número de Reynolds. A equação adimensionalizada da velocidade é:

$$
\frac{dv}{dt} = \frac{1 - v - \frac{3}{8} Re v^2}{St}
$$

Esse problema possui uma **solução analítica** (para casos com e sem arrasto inercial) e é resolvido aqui numericamente pelo método de **Runge-Kutta de quarta ordem (RK4)**.

---

## 💻 Implementações

Este exemplo está implementado em:

- [x] FORTRAN 90
- [x] C++
- [x] Python

Cada versão calcula a solução numérica e analítica da equação diferencial e gera uma visualização gráfica da velocidade da partícula ao longo do tempo.

---

## ▶️ Instruções de Execução

### 🔸 FORTRAN

```bash
./Allrun.sh
```

- Compila e executa o código
- Gera arquivos `.dat` com as soluções
- Produz gráfico `grafico_sedimentacao.pdf` via `gnuplot`
- Para limpeza dos arquivos da pasta:

```bash
./Allclean.sh
```
- O comando acima também limpa a pasta após a execução para a versão C++ do código
- Instale o `gnuplot` para poder visualizar o gráfico de saída. No Ubuntu, a instalação é feita via terminal por meio do comando
```bash
sudo apt install gnuplot
```


### 🔸 C++

```bash
./Allrun.sh
```

- Compila e executa o código C++
- Gera as mesmas saídas `.dat` e `grafico_sedimentacao.pdf` via `gnuplot`

### 🔸 Python

```bash
python3 main.py
```

- Executa a simulação e plota diretamente com `matplotlib`
- Salva gráfico como `grafico_sedimentacao.png` e o exibe automaticamente

---

## 🎨 Visualização e Pós-processamento

- As versões **FORTRAN** e **C++** utilizam o `gnuplot` como ferramenta externa de visualização. O pós-processamento é feito por meio de scripts, o que mostra que **não é necessário depender de Python ou `matplotlib` para gerar saídas gráficas bonitas e automatizadas**.
- A versão **Python** integra simulação e visualização em um único script, demonstrando uma abordagem mais interativa, útil para testes rápidos e exploração visual.

---

## 📎 Observações

- O número de Stokes (`St`) e de Reynolds (`Re`) são solicitados ao usuário ao iniciar o programa.
- As soluções são geradas para fins de comparação numérica e validação do método.
- Os scripts `Allrun.sh` e `Allclean.sh` estão disponíveis nas versões FORTRAN e C++ para facilitar execução e limpeza.

---

## 👨‍🏫 Autor

**Prof. Rafael Gabler Gontijo, PhD**  
[L2C – Soluções em Computação Científica](http://l2c.dev.br)  
Curso: *Do Cálculo à Simulação Computacional*  
[GitHub L2C](https://github.com/l2c-dev/manual-calculo-numerico)

---

✅ Este exemplo acompanha a apostila *“Do Cálculo à Simulação Computacional – Manual Prático”*, disponível como produto digital da L2C.

---