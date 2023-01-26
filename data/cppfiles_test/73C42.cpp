#include <bits/stdc++.h>
int check(int ak[], int n) {
  int fl = 0;
  for (int i = 0; i < n - 1; i++) {
    if (ak[i] > ak[i + 1]) return 1;
  }
  return 0;
}
void me() {
  long long int n;
  scanf("%lld", &n);
  int ak[n];
  for (int i = 0; i < n; i++) scanf("%d", &ak[i]);
  int co = 0, fl = 0;
  while (1) {
    int j = check(ak, n);
    if (j == 0) {
      printf("%d\n", co);
      return;
    }
    if (fl == 0) {
      for (int i = 0; i < n - 2; i = i + 2) {
        if (ak[i] > ak[i + 1]) {
          int swap = ak[i];
          ak[i] = ak[i + 1];
          ak[i + 1] = swap;
        }
      }
      fl = 1;
      co++;
    } else {
      for (int i = 1; i < n - 1; i = i + 2) {
        if (ak[i] > ak[i + 1]) {
          int swap = ak[i];
          ak[i] = ak[i + 1];
          ak[i + 1] = swap;
        }
      }
      fl = 0;
      co++;
    }
  }
}
int main() {
  long long int t;
  scanf("%lld", &t);
  for (long long int i = 0; i < t; i++) me();
  return 0;
}
