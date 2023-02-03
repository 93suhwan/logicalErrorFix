import logging
import argparse
from io import open

logger = logging.getLogger(__name__)

DIR='model/'
LANG='cpp'

def main():
  parser = argparse.ArgumentParser()

  parser.add_argument("--file", default=None, type=str, required=True,
                      help="File name: dev, test_0, ...")
  parser.add_argument("--trainType", default=None, type=str, required=True,
                      help="Train type: line, line_desc, line_desc_sample, ...")
  parser.add_argument("--model", default=None, type=str, required=True,
                      help="Train type: best-bleu, best-ppl, last")
  args = parser.parse_args()
  logger.info(args)

  src = './' + DIR + LANG + '_' + args.trainType + '/checkpoint-' + args.model + '/'  + args.file
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

