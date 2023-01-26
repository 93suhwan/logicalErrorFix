#include <bits/stdc++.h>
int in() {
  int x = 0;
  char c = getchar();
  bool f = 0;
  while (c < '0' && c > '9') f |= c == '-', c = getchar();
  while (c >= '0' && c <= '9')
    x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  return f ? -x : x;
}
long long lin() {
  long long x = 0;
  char c = getchar();
  bool f = 0;
  while (c < '0' && c > '9') f |= c == '-', c = getchar();
  while (c >= '0' && c <= '9')
    x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  return f ? -x : x;
}
const int N = 4e6 + 5;
int f[N], pre[N], n, mod;
int main() {
  n = in(), mod = in();
  f[1] = pre[1] = 1;
  for (int i = 2; i <= n; ++i) {
    for (int l = 2, r; l <= i; l = r + 1) {
      r = i / (i / l);
      (f[i] += 1ll * (r - l + 1) * f[i / l] % mod) %= mod;
    }
    (f[i] += pre[i - 1]) %= mod;
    pre[i] = (pre[i - 1] + f[i]) % mod;
  }
  printf("%d\n", f[n]);
  return 0;
}
