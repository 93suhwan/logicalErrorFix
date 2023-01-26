#include <bits/stdc++.h>
using namespace std;
int main() {
  char w[50], alp[26];
  int t, len, a, b, sum = 0;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    sum = 0;
    scanf("%s", alp);
    scanf("%s", w);
    len = strlen(w);
    for (int j = 0; j < len - 1; j++) {
      if (w[j] == w[j + 1]) {
        continue;
      }
      for (int m = 1; m <= 26; m++) {
        if (w[j] == alp[m]) {
          a = m;
        }
        if (w[j + 1] == alp[m]) {
          b = m;
        }
      }
      sum += abs(a - b);
    }
    printf("%d\n", sum);
  }
  return 0;
}
