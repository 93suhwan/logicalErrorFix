#include <bits/stdc++.h>
const int N = 10000;
int a[N];
int check(int n) {
  for (int i = 1; i <= n; ++i)
    if (a[i] != i) return 0;
  return 1;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    if (check(n)) {
      printf("%d\n", 0);
      continue;
    }
    for (int i = 1;; ++i) {
      int k;
      if (i & 1)
        k = 1;
      else
        k = 2;
      for (int j = k; j < n; j += 2) {
        if (a[j] > a[j + 1]) std::swap(a[j], a[j + 1]);
      }
      if (check(n)) {
        printf("%d\n", i);
        break;
      }
    }
  }
  return 0;
}
