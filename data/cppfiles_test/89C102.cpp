#include <bits/stdc++.h>
using namespace std;
const int oo = 1e9;
const int Mod = 1e9 + 7;
const long long OO = 1e18;
const int N = 2e5 + 5;
void file() {
  if (fopen("trash.inp", "r"))
    freopen("trash.inp", "r", stdin), freopen("trash.out", "w", stdout);
}
int n, col[N], cnt;
vector<int> ad[N];
void dfs(int u, int par) {
  int leaf = 1, col1 = 0, col2 = 0;
  for (int v : ad[u]) {
    if (v == par) continue;
    leaf = 0;
    dfs(v, u);
    if (col[v] == 1)
      col1 = 1;
    else if (col[v] == 2)
      col2 = 2;
    col[u] = 3 - col[v];
  }
  if (leaf)
    col[u] = 1;
  else if (col1 && col2)
    col[u] = 2;
  if (col[u] == 2) cnt++;
}
void in() {
  cin >> n;
  for (int i = 1; i <= n; i++) ad[i].clear();
  cnt = 0;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    ad[u].push_back(v);
    ad[v].push_back(u);
  }
  dfs(1, 0);
  int ans = n - 2 * cnt + (col[1] == 2);
  for (int u : ad[1])
    if (ad[u].size() == 1) ans - 1;
  cout << ans << '\n';
}
int main() {
  file();
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int test;
  cin >> test;
  while (test--) {
    in();
  }
}
