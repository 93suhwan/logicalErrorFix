#!/bin/bash

lang=cpp #programming language
lr=5e-5
batch_size=60
beam_size=10
source_length=512
target_length=64
data_dir=./data/edit_distance
output_dir=model/$lang
train_file=$data_dir/pair_code_edit_dist_train.txt
dev_file=$data_dir/pair_code_edit_dist_valid.txt
eval_steps=1000 #400 for ruby, 600 for javascript, 1000 for others
train_steps=50000 #20000 for ruby, 30000 for javascript, 50000 for others
pretrained_model=microsoft/codebert-base #Roberta: roberta-base

python run.py --do_train --do_eval --model_type roberta --model_name_or_path $pretrained_model --train_filename $train_file --dev_filename $dev_file --output_dir $output_dir --max_source_length $source_length --max_target_length $target_length --beam_size $beam_size --train_batch_size $batch_size --eval_batch_size $batch_size --learning_rate $lr --train_steps $train_steps --eval_steps $eval_steps 
