#include <bits/stdc++.h>
int main(void) {
  int case_num = 0;
  int temp_num = 0;
  int i = 0;
  scanf("%d", &case_num);
  for (i = 0; i < case_num; i++) {
    scanf("%d", &temp_num);
    if (temp_num == 1) {
      printf("0\n");
    } else if (temp_num <= 10) {
      printf("1\n");
    } else {
      printf("%d\n", temp_num / 10);
    }
  }
  return 0;
}
