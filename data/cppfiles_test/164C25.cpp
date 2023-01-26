#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
const int MOD = 1e9 + 7;
void Add(int &a, int b) {
  a += b;
  a -= a >= MOD ? MOD : 0;
}
int Mul(int a, int b) { return 1ll * a * b % MOD; }
string out, st;
int n, k, Left[N], Right[N], f[N], TIME, tin[N], p[N], flag[N];
void dfs1(int u) {
  if (Left[u]) dfs1(Left[u]);
  tin[u] = ++TIME;
  p[TIME] = u;
  out += st[u];
  if (Right[u]) dfs1(Right[u]);
}
bool dfs2(int u, int d, bool ok = true) {
  if (Left[u]) flag[u] = dfs2(Left[u], d + 1, ok);
  if (ok && !flag[u] && f[tin[u]] && k >= d) {
    k -= d;
    flag[u] = true;
  }
  if (ok && flag[u])
    cout << st[u] << st[u];
  else
    cout << st[u];
  if (Right[u]) dfs2(Right[u], 1, flag[u] && ok);
  return flag[u];
}
void Solve() {
  cin >> n >> k;
  cin >> st;
  st = '~' + st;
  for (int i = 1; i <= n; ++i) {
    cin >> Left[i] >> Right[i];
  }
  out = '~';
  dfs1(1);
  f[n] = 0;
  for (int i = n - 1; i >= 1; --i)
    if ((out[i] < out[i + 1]) || (out[i] == out[i + 1] && f[i + 1])) f[i] = 1;
  dfs2(1, 1);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int test = 1;
  while (test--) Solve();
}
