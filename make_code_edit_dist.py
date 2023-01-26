import pandas as pd
import numpy as np
from tqdm import tqdm
from io import open

COLUMNS = ['PID', 'Correct', 'Incorrect', 'Editdist']
THRESHOLD = 2

def load_code(dataFrame, data_loc=''):
  dataFrame['Correct_code'] = ''
  dataFrame['Incorrect_code'] = ''
  dataFrame['Statement'] = ''
  dataFrame['Description'] = ''
  dataFrame['Input'] = ''
  dataFrame['Output'] = ''

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
          if stmth # 수정중..

        for num, line in enumerate(lines):
          codeWithLine.append(str(num + 1) + ' ' + line)
        f.close()
      C_code = codeWithLine

      codeWithLine = []
      with open('./data/cppfiles_' + data_loc + '/' + str(cont[COLUMNS[0]]) + COLUMNS[2][0] + str(cont[COLUMNS[2]]) + '.cpp', 'r') as f:
        lines = f.readlines()
        for num, line in enumerate(lines):
          codeWithLine.append(str(num + 1) + ' ' + line)
        f.close()
      I_code = codeWithLine

      num = 0
      stmt = ''
      while True:
        if num == len(C_code):
          stmt = I_code[num]
          break
        elif num == len(I_code):
          stmt = C_code[num]
          break
        else:
          if C_code[num] != I_code[num]:
            stmt = C_code[num]
            break
        num += 1 
      dataFrame.at[idx, 'Correct_code'] = C_code
      dataFrame.at[idx, 'Incorrect_code'] = I_code
      dataFrame.at[idx, 'Statement'] = stmt

  dataFrame.drop(columns=COLUMNS, inplace=True)

  return dataFrame
  
def main():
  pairedDataTrain = pd.read_csv("./data/edit_distance/pair_solution_train.txt", sep='\t', names=COLUMNS)
  pairedDataValid = pd.read_csv("./data/edit_distance/pair_solution_valid.txt", sep='\t', names=COLUMNS)
  pairedDataTest  = pd.read_csv("./data/edit_distance/pair_solution_test.txt", sep='\t', names=COLUMNS)

  pairedDataTrain = load_code(pairedDataTrain, 'train')
  pairedDataValid = load_code(pairedDataValid, 'valid')
  pairedDataTest  = load_code(pairedDataTest,  'test')

  pairedDataTrain.to_csv("./data/edit_distance/pair_code_edit_dist_train.txt", sep='\t', index=False)
  pairedDataValid.to_csv("./data/edit_distance/pair_code_edit_dist_valid.txt", sep='\t', index=False)
  pairedDataTest.to_csv("./data/edit_distance/pair_code_edit_dist_test.txt", sep='\t', index=False)

if __name__ == "__main__":
  main()

