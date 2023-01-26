#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
long long mod = 1e9 + 7;
int n, k;
vector<int> e[maxn];
int f[102][102], num[102][102];
void dfs(int u, int p, int len, int fa) {
  num[fa][len]++;
  for (int v : e[u]) {
    if (v == p) continue;
    dfs(v, u, len + 1, fa);
  }
}
int cal(vector<int> v) {
  memset(f, 0, sizeof(f));
  int res = 0;
  int m = v.size();
  f[0][0] = 1;
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j <= i; j++) {
      if (j)
        f[i][j] = (f[i - 1][j] + 1ll * f[i - 1][j - 1] * v[i - 1]) % mod;
      else
        f[i][j] = f[i - 1][j];
    }
  }
  res = f[m][k] % mod;
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int _;
  cin >> _;
  while (_--) {
    cin >> n >> k;
    for (int i = (1); i <= (n - 1); ++i) {
      int u, v;
      cin >> u >> v;
      e[u].push_back(v), e[v].push_back(u);
    }
    if (k == 2) {
      cout << (n * (n - 1) / 2ll) % mod << endl;
      for (int i = (1); i <= (n); ++i) e[i].clear();
      continue;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      memset(num, 0, sizeof(num));
      for (int v : e[i]) dfs(v, i, 1, v);
      for (int d = 1; d <= n; d++) {
        vector<int> vv;
        for (int v : e[i]) vv.push_back(num[v][d]);
        ans = (ans + cal(vv)) % mod;
      }
    }
    cout << ans << endl;
    for (int i = (1); i <= (n); ++i) e[i].clear();
  }
  return 0;
}
