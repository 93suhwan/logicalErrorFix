import pandas as pd
import numpy as np
from tqdm import tqdm
from io import open

COLUMNS = ['PID', 'Correct', 'Incorrect', 'Editdist']
FILETYPE = ['train', 'valid', 'test']
THRESHOLD = 2

def load_code(dataFrame, data_loc=''):
  dataFrame['Correct_code'] = ''
  dataFrame['Incorrect_code'] = ''
  dataFrame['Statement'] = ''
  # dataFrame['Description'] = ''
  # dataFrame['Input'] = ''
  # dataFrame['Output'] = ''

  for idx, cont in tqdm(dataFrame.iterrows()):
    if dataFrame.at[idx, 'Editdist'] > THRESHOLD or dataFrame.at[idx, 'Editdist'] == 0:
      dataFrame = dataFrame.drop(idx)
    else:
      with open('./data/cppfiles_' + data_loc + '/' + str(cont[COLUMNS[0]]) + COLUMNS[1][0] + str(cont[COLUMNS[1]]) + '.cpp', 'r') as corr, open('./data/cppfiles_' + data_loc + '/' + str(cont[COLUMNS[0]]) + COLUMNS[2][0] + str(cont[COLUMNS[2]]) + '.cpp', 'r') as incorr:
        cLines = corr.readlines()
        iLines = incorr.readlines()

        cCodeWithLine = []
        iCodeWithLine = []
        stmt = None
        for idx in range(max(len(cLines), len(iLines))):
          if idx < len(cLines):
            cCodeWithLine.append(str(idx + 1) + ' ' + line)
          if idx < len(iLines):
            iCodeWithLine.append(str(idx + 1) + ' ' + line)
          if stmt is not None:
            continue
          else if cCodeWithLine[idx] != iCodeWithLine[idx]:
            if idx + 1 < len(iLines): # if a delete statement exists.
              if cCodeWithLine[idx] == iCodeWithLine[idx + 1]:
                stmt = ' '
            stmt = cCodeWithLine[idx]
        corr.colse()
        incorr.close()
        dataFrame.at[idx, 'Correct_code'] = cCodeWithLine
        dataFrame.at[idx, 'Incorrect_code'] = iCodeWithLine
        dataFrame.at[idx, 'Statement'] = stmt

  dataFrame.drop(columns=COLUMNS, inplace=True)

  return dataFrame
  
def main():
  DIR = './data/edit_distance/'
  for fileType in FILETYPE:
    pairedData = pd.read_csv(DIR + '/pair_solution_' + fileType + '.txt', sep='\t', names=COLUMNS)
    load_code(pairedDataTrain, fileType).to_csv(DIR + 'pair_code_edit_dist_' + fileType + '.txt', sep='\t', index=False)

if __name__ == "__main__":
  main()

