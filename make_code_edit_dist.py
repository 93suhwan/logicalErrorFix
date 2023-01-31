import pandas as pd
from io import open

COLUMNS = ['PID', 'Correct', 'Incorrect', 'Editdist']
FILETYPE = ['train', 'valid', 'test']
THRESHOLD = 2

def load_code(dataFrame, dataType=''):
  dataFrame['Correct_code'] = ''
  dataFrame['Incorrect_code'] = ''
  dataFrame['Statement'] = ''
  # dataFrame['Description'] = ''
  # dataFrame['Input'] = ''
  # dataFrame['Output'] = ''

  for idx, cont in dataFrame.iterrows():
    if idx % 5000 == 0:
      print('Current index = {}'.format(idx))
    if dataFrame.at[idx, 'Editdist'] > THRESHOLD or dataFrame.at[idx, 'Editdist'] == 0:
      dataFrame = dataFrame.drop(idx)
    else:
      with open('./data/cppfiles_' + dataType + '/' + str(cont[COLUMNS[0]]) + COLUMNS[1][0] + str(cont[COLUMNS[1]]) + '.cpp', 'r') as corr, open('./data/cppfiles_' + dataType + '/' + str(cont[COLUMNS[0]]) + COLUMNS[2][0] + str(cont[COLUMNS[2]]) + '.cpp', 'r') as incorr:
        cLines = corr.readlines()
        iLines = incorr.readlines()

        cCodeWithLine = ''
        iCodeWithLine = ''
        stmt = None
        for lIdx in range(max(len(cLines), len(iLines))):
          if lIdx < len(cLines):
            cCodeWithLine += (str(lIdx + 1) + ' ' + cLines[lIdx].strip() + '||| ')
          if lIdx < len(iLines):
            iCodeWithLine += (str(lIdx + 1) + ' ' + iLines[lIdx].strip() + '||| ')
          if stmt is not None:
            continue
          elif lIdx < len(cLines) and lIdx >= len(iLines):
            stmt = str(lIdx + 1) + ' ' + cLines[lIdx].strip()
          elif lIdx < len(iLines) and lIdx >= len(cLines):
            stmt = str(lIdx + 1) + ' '
          elif cLines[lIdx] != iLines[lIdx]:
            stmt = str(lIdx + 1) + ' ' + cLines[lIdx].strip()
            if lIdx + 1 < len(iLines): # if a delete statement exists.
              if cLines[lIdx] == iLines[lIdx + 1]:
                stmt = str(lIdx + 1) + ' '
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
    print('Creating {} data pairs'.format(fileType))
    pairedData = pd.read_csv(DIR + 'pair_solution_' + fileType + '.txt', sep='\t', names=COLUMNS)
    print('Data length   = {}'.format(len(pairedData)))
    load_code(pairedData, fileType).to_csv(DIR + 'pair_code_edit_dist_' + fileType + '.txt', sep='\t', index=False)

if __name__ == "__main__":
  main()

