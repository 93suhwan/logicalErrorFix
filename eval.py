import logging
import argparse
from io import open

logger = logging.getLogger(__name__)

DIR='model/'
LANG='cpp/'

def main():
  parser = argparse.ArgumentParser()

  parser.add_argument("--FILE", default=None, type=str, required=True,
                      help="File name: dev, test_0, ...")
  args = parser.parse_args()
  logger.info(args)

  src = './' + DIR + LANG + args.FILE
  total, fault, same = 0, 0, 0
  
  with open(src + '.gold', 'r') as gold, open(src + '.output', 'r') as out:
    for gold_line, out_line in zip(gold, out):
      gold_list = gold_line.split(' ')
      out_list = out_line.split(' ')
      total += 1  
  
      if len(out_list) < 2 or len(gold_list) < 2:
        continue
      if gold_list[1] == out_list[1]:
        fault += 1
        if ' '.join(gold_list[0:]).strip() == ' '.join(out_list[0:]).strip():
          same += 1
  
  
  print("total = {}, fault = {}, same = {}".format(total, fault, same))
  print("total = {}, fault = {:.2f}, same = {:.2f}".format(total, float(fault)/total, float(same)/total))

if __name__== "__main__":
  main()

