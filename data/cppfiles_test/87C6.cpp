#include <bits/stdc++.h>
int n;
int length;
int num[1000];
int main() {
  scanf("%d", &n);
  while (n--) {
    int max = 0;
    int mark = 0;
    scanf("%d", &length);
    for (int i = 1; i <= length; i++) {
      scanf("%d", &num[i]);
      if (num[i] > (i + mark)) {
        mark += num[i] - i - mark;
      }
    }
    printf("%d\n", mark);
  }
  return 0;
}
