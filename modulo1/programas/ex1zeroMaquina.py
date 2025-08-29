eps = 1.0
while 1.0 + eps != 1.0:
    eps = eps / 2.0

eps = eps * 2.0
print(f"Zero de máquina aproximado: {eps:.20e}")
