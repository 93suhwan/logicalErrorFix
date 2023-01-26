#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e6 + 10;
int n, p;
int inc(int a, int b) {
  a += b;
  return a >= p ? a - p : a;
}
int dec(int a, int b) {
  a -= b;
  return a < 0 ? a + p : a;
}
int mul(int a, int b) { return 1ll * a * b % p; }
int f[maxn], c[maxn];
void add(int l, int r, int x) {
  if (r > n) r = n + 1;
  c[l] = inc(c[l], x);
  c[r + 1] = dec(c[r + 1], x);
}
int main() {
  scanf("%d%d", &n, &p);
  f[1] = 1;
  int cur = 0;
  for (int i = 1; i <= n; ++i) {
    cur = inc(cur, c[i]);
    f[i] = inc(f[i], cur);
    f[i] = inc(f[i], f[i - 1]);
    for (int j = 2; 1ll * j * i <= n; ++j) {
      add(i * j, i * j + j - 1, f[i]);
    }
    f[i] = inc(f[i], f[i - 1]);
  }
  printf("%d\n", dec(f[n], f[n - 1]));
  return 0;
}
