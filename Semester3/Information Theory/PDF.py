import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import math

def Plot_pdf(label, p):
    fig, ax = plt.subplots(1, 2, gridspec_kw={'width_ratios': [1, 2]})
    fig.set_size_inches(12, 8)
    fig.patch.set_visible(False)
    ax[0].axis('off')
    
    pdf_table = pd.DataFrame(zip(label, p), columns=['Information', 'Probability'])
    plot_pdf_table = ax[0].table(cellText=pdf_table.values, colLabels=pdf_table.columns, loc='center', cellLoc='center', colWidths=[0.3, 0.35])
    if len(label) <= 15:
        plot_pdf_table.scale(1.5, 3)
    else:
        plot_pdf_table.scale(1.2, 1.5)
    plot_pdf_table.set_fontsize(14)

    ax[1].bar(label, p, width=0.4)
    ax[1].text(1, -0.024, 'H = ' + str(sum([i * math.log2(1/i) for i in p])), fontsize=11)
    plt.show()

def Create_random_pdf(n = 10, label_type = 'alphabelt'):
    p = np.random.rand(n)
    p = p / sum(p)
    if label_type == 'alphabelt' and n <= 26:
        l = [chr(i) for i in range(97, 97 + n)]
    else:
        l = [str(i) for i in range(n)]
    
    return l, list(p)

def Sort_pdf(label, p):
    l = list(zip(label, p))
    l.sort(key=lambda e: e[1], reverse=True)
    
    return [i[0] for i in l], [i[1] for i in l]