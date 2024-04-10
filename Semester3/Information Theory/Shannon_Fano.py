import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from statistics import median
import math
import PDF


def GetShanonFanoConverter(label, p, mark=''):
    if len(label) == 0:
        return {}
    if len(label) == 1:
        return {label[-1]: mark}
    mid = 0

    s = 0
    while s < sum(p) / 2:
        s += p[mid]
        mid += 1

    return GetShanonFanoConverter(label[0:mid], p[0:mid], mark + '0') | GetShanonFanoConverter(label[mid:], p[mid:], mark + '1')


def Convert(s, converter):
    convert_s = ''
    for c in s:
        convert_s = convert_s + converter[c]
    return convert_s


l, p = PDF.Create_random_pdf(26)
PDF.Plot_pdf(l, p)

l, p = PDF.Sort_pdf(l, p)
PDF.Plot_pdf(l, p)

li = [1, 3, 4, 5]

converter = GetShanonFanoConverter(l, p)
s = input("Input string to convert: ")
print(Convert(s, converter))
