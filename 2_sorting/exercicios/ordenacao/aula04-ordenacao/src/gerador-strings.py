import random
import string

strings = []
for i in range(10000000):
    tamanho = random.randint(5, 10)  # tamanho da string aleatória
    s = ''.join(random.choices(string.ascii_lowercase, k=tamanho))
    strings.append(s)

strings.sort()

with open('../data/input.txt', 'w') as f:
    for s in strings:
        f.write(s + ' ')
