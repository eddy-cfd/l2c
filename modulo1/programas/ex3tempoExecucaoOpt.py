import time
import os
from numba import njit, prange


@njit(parallel=True, fastmath=True)
def soma_harmonica(n):
    s = 0.0
    for i in prange(1, n + 1):
        s += 1.0 / i
    return s


soma_harmonica(1)

start = time.time()

s = soma_harmonica(100_000_000)

end = time.time()

print(f"Resultado da soma: {s:.6f}")
print(f"Tempo de execução: {end - start:.3f} segundos")
