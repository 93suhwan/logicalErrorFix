#include <bits/stdc++.h>
using namespace std;
const int N = 4010;
const int inf = 2147483647;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10ll + ch - '0', ch = getchar();
  return x * f;
}
int n, m, sz[N];
long long a[N], f[N][N];
int solve(int l, int r) {
  if (l > r) return 0;
  int p = l;
  for (int i = l + 1; i <= r; i++)
    if (a[i] < a[p]) p = i;
  sz[p] = r - l + 1;
  int L = solve(l, p - 1), R = solve(p + 1, r);
  for (int i = 0; i <= sz[L]; i++)
    for (int j = 0; j <= sz[R]; j++)
      f[p][i + j] = max(f[p][i + j], f[L][i] + f[R][j] - 2ll * i * j * a[p]),
               f[p][i + j + 1] = max(f[p][i + j + 1],
                                     f[L][i] + f[R][j] + (long long)m * a[p] -
                                         2ll * (i + 1) * (j + 1) * a[p] + a[p]);
  return p;
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  printf("%lld\n", f[solve(1, n)][m]);
  return 0;
}
