from io import open
import argparse

import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import seaborn as sns

sns.set_theme()
sns.set_color_codes()
sns.set_palette('deep')
sns.set_style("whitegrid")

plt.rc('font', family='serif')
plt.rcParams['font.weight'] = 'bold'
plt.rcParams['axes.labelweight'] = 'bold'
#plt.rcParams['text.latex.preamble']=[r"\usepackage{amsmath}"]

COLUMNS = ['Correct_code', 'Incorrect_code', 'Statement']
FILETYPE = ['train', 'valid', 'test']

def draw_histogram(dataFrame, gIdx, dataType='', scale=None):
  length = len(dataFrame)
  cAvgLen, iAvgLen = [], []

  for idx, cont in dataFrame.iterrows():
    cAvgLen.append(int(cont[COLUMNS[0]].split('||| ')[-2].split()[0]))
    iAvgLen.append(int(cont[COLUMNS[1]].split('||| ')[-2].split()[0]))
  plt.subplot(int('32' + str((1 + gIdx) * 2 - 1)))
  plt.title(dataType + ' corr')
  plt.xlabel('number of lines')
  plt.ylabel('number of files')
  if scale == 'log':
    plt.yscale('log')
  plt.xlim([0, 250])
  plt.hist(cAvgLen)
  plt.subplot(int('32' + str((1 + gIdx) * 2)))
  plt.title(dataType + ' incorr')
  plt.xlabel('number of lines')
  plt.ylabel('number of files')
  if scale == 'log':
    plt.yscale('log')
  plt.xlim([0, 250])
  plt.hist(iAvgLen)

def main():
  parser = argparse.ArgumentParser()
  parser.add_argument("--scale", default=None, type=str)
  args = parser.parse_args()
  scale = ''
  
  DIR = './data/edit_distance/'

  fig = plt.figure(figsize=(10,20))
  plt.grid(True)

  for idx, fileType in enumerate(FILETYPE):
    print('Drawing histogram of the {} data'.format(fileType))

    pairedData = pd.read_csv(DIR + 'pair_code_edit_dist_' + fileType + '.txt', sep='\t', header=[0]).drop(columns=COLUMNS[2])

    draw_histogram(pairedData, idx, fileType, args.scale)
  
  if args.scale is not None:
    scale = '_' + args.scale

  fig.savefig('./figure/data_dist' + scale + '.png', bbox_inches='tight', dpi=600)

if __name__ == "__main__":
  main()

