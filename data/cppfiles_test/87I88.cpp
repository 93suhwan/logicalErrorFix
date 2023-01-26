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
      if (num[i] > max) {
        max = num[i];
        mark = i;
      }
    }
    if (max - mark < 0)
      printf("0\n");
    else
      printf("%d\n", max - mark);
  }
  return 0;
}
