#include <bits/stdc++.h>
using namespace std;
const long long N = 4e3 + 5;
long long n, m, top, a[N], f[N][N], ls[N], rs[N], stk[N], siz[N];
void dfs(long long x) {
  siz[x] = 1;
  if (ls[x]) dfs(ls[x]), siz[x] += siz[ls[x]];
  if (rs[x]) dfs(rs[x]), siz[x] += siz[rs[x]];
}
void solve(long long p) {
  if (!p) return;
  solve(ls[p]), solve(rs[p]);
  memset(f[p], -0x3f, sizeof(f[p]));
  for (long long i = 0; i <= siz[ls[p]]; i++)
    for (long long j = 0; j <= siz[rs[p]]; j++) {
      f[p][i + j] =
          max(f[p][i + j], f[ls[p]][i] + f[rs[p]][j] - 2 * i * j * a[p]);
      f[p][i + j + 1] =
          max(f[p][i + j + 1], f[ls[p]][i] + f[rs[p]][j] - 2 * i * j * a[p] -
                                   2 * (i + j) * a[p] + (m - 1) * a[p]);
    }
}
signed main() {
  cin >> n >> m;
  a[0] = 1e18;
  long long p = 0;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] < a[p]) p = i;
  }
  for (long long i = 1; i <= n; i++) {
    long long k = top;
    while (k && a[stk[k]] > a[i]) k--;
    if (k) rs[stk[k]] = i;
    if (k < top) ls[i] = stk[k + 1];
    stk[++k] = i;
    top = k;
  }
  dfs(p);
  solve(p);
  cout << f[p][m] << endl;
}
