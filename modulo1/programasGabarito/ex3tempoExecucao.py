import time

start = time.time()

s = 0.0
for i in range(1, 100_000_001):
    s += 1.0 / i

end = time.time()

print(f"Resultado da soma: {s:.6f}")
print(f"Tempo de execução: {end - start:.3f} segundos")
