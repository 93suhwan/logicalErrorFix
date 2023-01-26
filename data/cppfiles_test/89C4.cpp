#include <bits/stdc++.h>
using namespace std;
const int N = 200002;
const long long M = 1000000007;
int ans;
vector<int> g[N];
int dfs(int u, int p = 0) {
  int res = 0;
  for (auto v : g[u]) {
    if (v == p) continue;
    res += dfs(v, u);
  }
  if (res == 0) return 1;
  if (u == 1) return res;
  ans += res - 1;
  return 0;
}
void solve() {
  ans = 0;
  int n, u, v;
  cin >> n;
  for (int i = 1; i <= n; i++) g[i].clear();
  for (int i = 1; i < n; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int l = dfs(1);
  cout << l + ans << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  cin >> tc;
  for (int qq = 1; qq <= tc; qq++) {
    solve();
  }
  return 0;
}
