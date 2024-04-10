import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import math
import PDF

def to_bin(num, decimal_max_len = 10, fixed = False):
    l_num = int(math.floor(num))
    r_num = num - l_num
    if r_num == 0:
        result = '{0:b}'.format(num)
        if fixed:
            result = result + '.' + '0' * decimal_max_len
        return result
    r = ''
    while r_num != 0 and len(r) < decimal_max_len:
        r_num *= 2
        if r_num > 1:
            r = r + '1'
            r_num -= 1
        else:
            r = r + '0'
    while fixed and len(r) < decimal_max_len:
        r = r + '0'
    return '{0:b}'.format(l_num) + '.' + r

def Plot(label, P, L, F, encoder):
    bin_form = [to_bin(f, 20, True) for f in F]
    table = pd.DataFrame(zip(label, P, L, F, bin_form, [encoder[i] for i in label]), columns=['Information', 'Probability', 'Length', 'F', 'Binary form', 'Code word'])
    
    fig, ax = plt.subplots()
    fig.set_size_inches(12, 8)
    
    # hide axes
    fig.patch.set_visible(False)
    ax.axis('off')
    ax.axis('tight')
    ax.table(cellText=table.values, colLabels=table.columns, loc='center')

    fig.tight_layout()

    plt.show()

def MakeShannonEncoder(label, P, output_csv = True):
    _label, _P = PDF.Sort_pdf(label, P)
    PDF.Plot_pdf(_label, _P)
    
    # Calcalate length and F
    L = []
    F = [0]
    for p in _P:
        L.append(math.ceil(-math.log2(p)))
        F.append(F[-1] + p)
    F.pop()
    # Making encoder
    encoder = dict()
    for i in range(len(_P)):
        encoder[_label[i]] = to_bin(F[i], L[i], fixed=True).split('.')[-1]
        
    Plot(_label, _P, L, F, encoder)
    if output_csv:
        with open('output.csv', 'w+', encoding='utf-8') as f:
            content = []
            content.append(','.join(label))
            content.append(','.join([str(p) for p in P]))
            content.append('')
            content.append(','.join(_label))
            content.append(','.join([str(p) for p in _P]))
            content.append('')
            content.append(','.join(['Information', 'Probability', 'Length', 'F', 'Binary form', 'Code word']))
            for e in zip(_label, _P, L, F, [to_bin(f, 20, True) for f in F], [encoder[i] for i in _label]):
                content.append('="' + '",="'.join(str(_e) for _e in e) + '"')
            for line in content:
                f.write(line + '\n')
            # f.writelines(content)
    return encoder

def Convert(s, converter):
    convert_s = ''
    for c in s:
        convert_s = convert_s + converter[c]
    return convert_s

if __name__ == '__main__':
    l, p = [], []
    n = int(input('Input size of symbols list (0 for random generate): '))
    if n > 0:
        print('Input labels list\n')
        for i in range(n):
            label = input(f'Label[{i + 1}] = ')
            l.append(label)
        print('Input probabilities list\n')
        for i in range(n):
            label = float(input(f'P[{i + 1}] = '))
            p.append(label)
    else:
        l, p = PDF.Create_random_pdf(26)
    PDF.Plot_pdf(l, p)

    encoder = MakeShannonEncoder(l, p)
    
    s = input("Input string to convert: ")
    print(Convert(s, encoder))