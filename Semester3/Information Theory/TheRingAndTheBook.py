import string
import numpy as np
import Shannon

char_pdf = dict()

with open('TheRingAndTheBook.txt', 'r', encoding='utf-8') as f:
    data = f.readlines()
    for line in data:
        line = line.lower()
        for c in line:
            if c not in string.ascii_lowercase:
                continue
            if c in char_pdf:
                char_pdf[c] += 1
            else:
                char_pdf[c] = 0
label = [k for k in char_pdf]
p = np.array([float(char_pdf[v]) for v in char_pdf])

p /= sum(p)
print(label, p)

encoder = Shannon.MakeShannonEncoder(label, p)
s = input("Input string to convert: ")
print(Shannon.Convert(s, encoder))