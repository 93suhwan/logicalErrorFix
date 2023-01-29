import io
import sys

import riegeli

DIR='./data/'
FILETYPE=['train', 'valid', 'test']

def _all_problems(filenames):
  """Iterates through all ContestProblems in filenames."""
  for filename in filenames:
    reader = riegeli.RecordReader(io.FileIO(filename, mode='rb'),)
    for problem in reader.read_messages(contest_problem_pb2.ContestProblem):
      yield problem

def make_cpp_files(filenames):
  for fileType in FILETYPE:
    if not os.path.exists(DIR + 'cppfiles_' + fileType):
      os.makedirs(DIR + 'cppfiles_' + fileType)

    for program_id, problem in enumerate(_all_problems(filenames)):
      for correct_id, correct in enumerate(problem.solutions):
        if correct.language==2:
          corrFile = open(DIR + 'cppfiles_' + fileType + '/' + str(program_id) + 'C' + str(correct_id)+'.cpp', 'w')
          corrFile.write(correct.solution)
                 
      for incorrect_id, incorrect in enumerate(problem.incorrect_solutions):
        if incorrect.language==2:                    
          incorrFile = open(DIR + 'cppfiles_' + fileType + '/' + str(program_id) + 'I' + str(incorrect_id)+'.cpp', 'w')
          incorrFile.write(incorrect.solution)

def main():
  make_cpp_files(sys.argv[1:])

if __name__ == '__main__':
  main()
