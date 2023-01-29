#!/bin/bash

lang=cpp #programming language
batch_size=128
beam_size=10
source_length=512
target_length=64
data_dir=./data/edit_distance
output_dir=model/$lang
dev_file=$data_dir/pair_code_edit_dist_valid.txt

test_file=$data_dir/pair_code_edit_dist_train.txt
#test_file=$data_dir/pair_code_edit_dist_valid.txt
#test_file=$data_dir/pair_code_edit_dist_test.txt

#test_model=$output_dir/checkpoint-best-bleu/pytorch_model.bin #checkpoint for test
#test_model=$output_dir/checkpoint-best-ppl/pytorch_model.bin #checkpoint for test
test_model=$output_dir/checkpoint-last/pytorch_model.bin #checkpoint for test

pretrained_model=microsoft/codebert-base #Roberta: roberta-base

python run.py --do_test --model_type roberta --model_name_or_path $pretrained_model --load_model_path $test_model --dev_filename $dev_file --test_filename $test_file --output_dir $output_dir --max_source_length $source_length --max_target_length $target_length --beam_size $beam_size --eval_batch_size $batch_size
