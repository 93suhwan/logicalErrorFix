#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m, k, skc, f[N][N][N], C[N][N], fac[N];
bool vis[N][N][N];
void upd(int &x, int y) {
  x = x + y;
  if (x >= skc) x -= skc;
}
int solve(int len, int ot, int tk) {
  if (ot + len < m || ot >= m) return (tk == 0) * fac[len];
  if (tk + (m - ot - 1) > len || (len + 1) / 2 < tk) return 0;
  if (!len) return tk == 0;
  if (vis[len][ot][tk]) return f[len][ot][tk];
  vis[len][ot][tk] = 1;
  for (register int i = (1); i <= (len); ++i)
    for (register int j = (0); j <= (tk - (ot + 1 == m)); ++j)
      upd(f[len][ot][tk], 1ll * solve(i - 1, ot + 1, j) *
                              solve(len - i, ot + 1, tk - j - (ot + 1 == m)) %
                              skc * C[i - 1][len - 1] % skc);
  return f[len][ot][tk];
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> k >> skc;
  fac[0] = 1;
  for (register int i = (1); i <= (n); ++i) fac[i] = 1ll * fac[i - 1] * i % skc;
  C[0][0] = 1;
  for (register int j = (1); j <= (n); ++j) {
    C[0][j] = 1;
    for (register int i = (1); i <= (j); ++i)
      C[i][j] = (C[i][j - 1] + C[i - 1][j - 1]) % skc;
  }
  cout << solve(n, 0, k) << '\n';
  return 0;
}
