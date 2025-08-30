import numpy as np
import matplotlib.pyplot as plt

#==================== Entrada do usuário ======================#
St = float(input("Qual o valor do número de Stokes? "))
Re = float(input("Qual o valor do número de Reynolds? "))

#==================== Parâmetros iniciais =====================#
npast = int(1000 * St)
dt = St / 10
t = 0.0
v = 0.0
eps = 3.0 * Re / 8.0

tempo = [t]
v_num = [v]
v_exato = []

#==================== Função da EDO ===========================#
def dvdt(v, St, Re):
    return (1.0 - v - (3.0 / 8.0) * Re * v**2) / St

#==================== Loop de tempo ===========================#
for k in range(npast):
    # Solução analítica
    if Re == 0.0:
        ve = 1.0 - np.exp(-t / St)
    else:
        v_star = (-1.0 + np.sqrt(1.0 + (3.0 / 2.0) * Re)) / (0.75 * Re)
        P = -(0.75 / St) * Re * v_star - 1.0 / St
        Q = (3.0 / 8.0) * (Re / St)
        ve = v_star + 1.0 / (Q / P + (-1.0 / v_star - Q / P) * np.exp(-P * t))
    v_exato.append(ve)

    # Solução numérica (RK4)
    k1 = dt * dvdt(v, St, Re)
    k2 = dt * dvdt(v + 0.5 * k1, St, Re)
    k3 = dt * dvdt(v + 0.5 * k2, St, Re)
    k4 = dt * dvdt(v + k3, St, Re)
    v += (k1 + 2 * k2 + 2 * k3 + k4) / 6.0

    t += dt
    tempo.append(t)
    v_num.append(v)

#==================== Gráfico com Matplotlib ==================#
plt.figure(figsize=(8, 6))
plt.plot(tempo[:-1], v_exato, 'k-', label='Solução Analítica', linewidth=2)
plt.plot(tempo[:-1:5], v_num[:-1:5], 'ko', label='Solução Numérica', markersize=4)

plt.title("Sedimentação de partícula em baixo Reynolds")
plt.xlabel("t (s)")
plt.ylabel("v(t) (m/s)")
plt.grid(True)
plt.legend(loc="lower right")
plt.tight_layout()
plt.savefig("grafico_sedimentacao.png", dpi=300)
plt.show()
