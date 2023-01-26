#include <bits/stdc++.h>
int main() {
  int t, i, j, k;
  scanf("%d", &t);
  int ranges[t][2000];
  int len[t];
  for (i = 0; i < t; ++i) {
    scanf("%d", &len[i]);
    for (j = 0; j < (2 * len[i]); j += 2) {
      scanf("%d %d", &ranges[i][j], &ranges[i][j + 1]);
    }
  }
  for (i = 0; i < t; ++i) {
    int num[len[i]];
    for (j = 0; j < len[i]; ++j) {
      num[j] = j + 1;
    }
    int sort[2 * len[i]];
    int c = 0, diff = 0;
    while (c < 2 * len[i]) {
      for (j = 0; j < (2 * len[i]); j += 2) {
        if (ranges[i][j + 1] - ranges[i][j] == diff) {
          sort[c] = ranges[i][j];
          sort[c + 1] = ranges[i][j + 1];
          c += 2;
        }
      }
      diff += 1;
    }
    for (j = 0; j < (2 * len[i]); j += 2) {
      int d;
      diff = sort[j + 1] - sort[j];
      if (diff == 0) {
        d = sort[j];
        num[d - 1] = 0;
        printf("%d %d %d\n", sort[j], sort[j + 1], d);
      } else {
        c = sort[j + 1];
        while (c >= sort[j]) {
          if (num[c - 1] != 0) {
            d = c;
            num[c - 1] = 0;
            printf("%d %d %d\n", sort[j], sort[j + 1], d);
            break;
          }
          c -= 1;
        }
      }
    }
    printf("\n");
  }
  return 0;
}
