#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, P = 1e9 + 7;
int n, m, p, f[N][20], a[N], q[N], s[20], b[N];
inline void add(int &x, int y) {
  x = (x + y) % P;
  if (x < 0) x += P;
}
int main() {
  scanf("%d%d%d", &n, &m, &p);
  for (int i = (1); i <= (n); i++) scanf("%d", &a[i]);
  for (int i = (1); i <= (n); i++) q[i] = (q[i - 1] + a[i]) % p;
  for (int i = (0); i <= (n - 1); i++) f[q[i]][0]++;
  int d = q[n], ans = 0;
  s[0] = d;
  for (int j = (1); j <= (17); j++) {
    for (int i = (0); i <= (p - 1); i++) {
      add(f[i][j], f[i][j - 1]);
      add(f[(i + d) % p][j], f[i][j - 1]);
    }
    d = d * 2 % p, s[j] = d;
  }
  d = 0;
  for (int j = (17); j >= (0); j--)
    if (m & (1 << j)) {
      for (int i = (0); i <= (p - 1); i++) add(b[(i + d) % p], f[i][j]);
      d = (d + s[j]) % p;
    }
  for (int i = (0); i <= (n - 1); i++) {
    add(b[q[i]], -1), add(ans, b[q[i]]);
    add(b[(d + q[i]) % p], 1);
  }
  ans = 1ll * ans * m % P;
  printf("%d", (ans + (d == 0)) % P);
  return 0;
}
