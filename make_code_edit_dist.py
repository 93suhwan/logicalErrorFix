import pandas as pd
import numpy as np
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

  for idx, cont in dataFrame.iterrows():
    if idx % 5000 == 0:
      print('Current index = ', idx)
    if dataFrame.at[idx, 'Editdist'] > THRESHOLD or dataFrame.at[idx, 'Editdist'] == 0:
      dataFrame = dataFrame.drop(idx)
    else:
      with open('./data/cppfiles_' + data_loc + '/' + str(cont[COLUMNS[0]]) + COLUMNS[1][0] + str(cont[COLUMNS[1]]) + '.cpp', 'r') as corr, open('./data/cppfiles_' + data_loc + '/' + str(cont[COLUMNS[0]]) + COLUMNS[2][0] + str(cont[COLUMNS[2]]) + '.cpp', 'r') as incorr:
        cLines = corr.readlines()
        iLines = incorr.readlines()

        cCodeWithLine = []
        iCodeWithLine = []
        stmt = None
        for lIdx in range(max(len(cLines), len(iLines))):
          if lIdx < len(cLines):
            cCodeWithLine.append(str(lIdx + 1) + ' ' + cLines[lIdx])
          if lIdx < len(iLines):
            iCodeWithLine.append(str(lIdx + 1) + ' ' + iLines[lIdx])
          print()
          print('./data/cppfiles_' + data_loc + '/' + str(cont[COLUMNS[0]]) + COLUMNS[1][0] + str(cont[COLUMNS[1]]) + '.cpp')
          print('./data/cppfiles_' + data_loc + '/' + str(cont[COLUMNS[0]]) + COLUMNS[2][0] + str(cont[COLUMNS[2]]) + '.cpp')
          if stmt is not None:
            continue
          elif cLines[lIdx] != iLines[lIdx]:
            if lIdx + 1 < len(iLines): # if a delete statement exists.
              if cLines[lIdx] == iLines[lIdx + 1]:
                stmt = ' '
            stmt = cLines[lIdx]
        corr.close()
        incorr.close()
        dataFrame.at[idx, 'Correct_code'] = cCodeWithLine
        dataFrame.at[idx, 'Incorrect_code'] = iCodeWithLine
        dataFrame.at[idx, 'Statement'] = stmt

  dataFrame.drop(columns=COLUMNS, inplace=True)

  return dataFrame
  
def main():
  DIR = './data/edit_distance/'
  for fileType in FILETYPE:
    print('Creating ' + fileType + ' pairs.')
    pairedData = pd.read_csv(DIR + '/pair_solution_' + fileType + '.txt', sep='\t', names=COLUMNS)
    print('Data length = ', len(pairedData))
    load_code(pairedData, fileType).to_csv(DIR + 'pair_code_edit_dist_' + fileType + '.txt', sep='\t', index=False)

if __name__ == "__main__":
  main()

