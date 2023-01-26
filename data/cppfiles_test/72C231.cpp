#include <bits/stdc++.h>
int funcK(int v) {
  int num[10];
  for (int i = 0; i < 10; ++i) num[i] = 0;
  while (v > 0) {
    num[v % 10] = 1;
    v /= 10;
  }
  int x = 0;
  for (int i = 0; i < 10; ++i) x += num[i];
  return x;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d%d", &n, &k);
    while (funcK(n) > k) {
      int o = n;
      while (funcK(o) > k) o /= 10;
      int p = 1;
      while (n / p != o) p *= 10;
      p /= 10;
      n = (n / p) * p + p;
    }
    printf("%d\n", n);
  }
}
