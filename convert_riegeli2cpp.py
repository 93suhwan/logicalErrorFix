import io
import os
import sys

import riegeli

import contest_problem_pb2

DIR='/'.join(os.path.realpath(__file__).split('/')[0:-2]) + '/data/'
FILETYPE=['_train', '_valid', '_test']

def _all_problems(filenames):
  """Iterates through all ContestProblems in filenames."""
  for filename in filenames:
    reader = riegeli.RecordReader(io.FileIO(filename, mode='rb'),)
    for problem in reader.read_messages(contest_problem_pb2.ContestProblem):
      yield problem

def make_cpp_files(filenames, fileType):
  if not os.path.exists(DIR + 'cppfiles' + fileType):
    os.makedirs(DIR + 'cppfiles' + fileType)

  if not os.path.exists(DIR + 'descriptions' + fileType):
    os.makedirs(DIR + 'descriptions' + fileType)

  if not os.path.exists(DIR + 'samples' + fileType):
    os.makedirs(DIR + 'samples' + fileType)

  for program_id, problem in enumerate(_all_problems(filenames)):
    for correct_id, correct in enumerate(problem.solutions):
      if correct.language==2:
        with open(DIR + 'cppfiles' + fileType + '/' + str(program_id) + 'C' + str(correct_id) + '.cpp', 'w') as corrFile:
        corrFile.write(correct.solution)

    for incorrect_id, incorrect in enumerate(problem.incorrect_solutions):
      if incorrect.language==2:
        with open(DIR + 'cppfiles' + fileType + '/' + str(program_id) + 'I' + str(incorrect_id) + '.cpp', 'w') as incorrFile:
        incorrFile.write(incorrect.solution)

    with open(DIR + 'descriptions' + fileType + '/' + str(program_id) + '.txt', 'w') as descFile:
      descFile.write(problem.description)
    with open(DIR + 'samples' + fileType + '/' + str(program_id) + '.txt', 'w') as sampleFile:
      sampleFile.write(str(problem.public_tests))

def main():
  for fileType in FILETYPE:
    print('Creating cppfiles' + fileType + '...')
    filenames = [name for name in sys.argv[1:] if fileType in name]
    make_cpp_files(filenames, fileType)

if __name__ == '__main__':
 main()

