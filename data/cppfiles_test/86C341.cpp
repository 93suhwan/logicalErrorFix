#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d ", &t);
  char *a, *b;
  for (int i = 0; i < t; i++) {
    int n;
    int max = 0;
    scanf("%d ", &n);
    a = (char *)malloc(sizeof(char) * n);
    b = (char *)malloc(sizeof(char) * n);
    for (int j = 0; j < n; j++) {
      if (j == n - 1) {
        scanf("%c ", &a[j]);
      } else {
        scanf("%c", &a[j]);
      }
    }
    for (int j = 0; j < n; j++) {
      scanf("%c", &b[j]);
    }
    int pre, cur;
    if (a[0] == '1') {
      if (b[0] == '1') {
        cur = 3;
      } else {
        cur = 2;
      }
    } else {
      if (b[0] == '1') {
        cur = 1;
      } else {
        cur = 0;
      }
    }
    for (int j = 1; j < n; j++) {
      pre = cur;
      if (a[j] == '1') {
        if (b[j] == '1') {
          cur = 3;
        } else {
          cur = 2;
        }
      } else {
        if (b[j] == '1') {
          cur = 1;
        } else {
          cur = 0;
        }
      }
      if ((pre == 1) || (pre == 2)) {
        max += 2;
      } else if (pre == 0) {
        if (cur == 3) {
          cur = 1;
        } else {
          max += 1;
        }
      } else {
        if (cur == 0) {
          cur = 1;
        }
      }
    }
    if ((cur == 1) || (cur == 2)) {
      max += 2;
    } else if (cur == 0) {
      max += 1;
    }
    printf("%d\n", max);
  }
  return 0;
}
