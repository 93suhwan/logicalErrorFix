#include <bits/stdc++.h>
int sol(int n, int p);
int main() {
  int count, i, n, m;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    count = 0;
    scanf("%d", &m);
    count = sol(m, 2) + sol(m, 3) - sol(m, 6);
    printf("%d\n", count);
  }
}
int sol(int n, int p) {
  int i;
  for (i = 1; pow(i, p) <= n; i++) {
    continue;
  }
  return i - 1;
}
