def soma_progressiva(n):
    s = 0.0
    for i in range(1, n+1):
        s += 1.0 / (i * i)
    return s

def soma_regressiva(n):
    s = 0.0
    for i in reversed(range(1, n+1)):
        s += 1.0 / (i * i)
    return s

n = 1000000
exato = 1.6449340668482264

prog = soma_progressiva(n)
regr = soma_regressiva(n)

print(f"Soma progressiva: {prog:.15f}")
print(f"Soma regressiva: {regr:.15f}")
print(f"Erro progressivo: {abs(prog - exato):.3e}")
print(f"Erro regressivo: {abs(regr - exato):.3e}")
