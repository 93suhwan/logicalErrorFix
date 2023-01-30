# logicalErrorFix
![LEFix](./figure/LEFix.png?row=true)

# Download and make a dataset
참고: https://github.com/deepmind/code_contests

Install [bazel](https://docs.bazel.build/versions/main/install.html) and [Cloud SDK](https://cloud.google.com/sdk/docs/quickstart) for gsutil and clone [Riegeli](https://github.com/google/riegeli).

```bash
>> clone https://github.com/deepmind/code_contests

>> cp covert_riegeli2cpp.py code_contests

>> cd code_contests

>> clone https://github.com/google/riegeli

# bazel build 중 'logical_config_python' 관련 에러 발생 시 
# export PYTHON2_BIN_PATH="python3"

>> bazel build -c opt :print_names_and_sources

>> gsutil -m cp -r gs://dm-code_contests /tmp

>> bazel run -c opt \
  :convert_riegeli2cpp /tmp/dm-code_contests/*

>> cd ..

>> python make_code_edit_dist.py
```

# Train & eval model

```bash
>> ./train.sh

# test_file 변수를 바꿔서 데이터 변경
# test_model 변수를 바꿔서 모델 변경
>> ./eval.sh

>> python --FILE test_0
# total = ???, fault = ???, same == ???
# total = ???, fault = fault/total, same/total
```

  # Process
  1. Single(이하 S) CodeBERT + Transformer(6 Layers, 이하 6L) *curr.
  2. S BERT + S CodeBERT + Transformer (6L)              
  3. 2 BERT + S CodeBERT + Transformer(6L)              
  4. N BERT + N CodeBERT + Transformer(6L)
