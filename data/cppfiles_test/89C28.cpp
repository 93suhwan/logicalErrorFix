#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e15;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1.0);
mt19937 rng((int)chrono::steady_clock::now().time_since_epoch().count());
int ans;
vector<vector<int>> G;
bool dfs(int u, int p = -1) {
  bool isleaf = true;
  for (int v : G[u]) {
    if (v == p) continue;
    isleaf &= !dfs(v, u);
  }
  if (u) {
    if (isleaf)
      ++ans;
    else
      --ans;
  } else
    ans += isleaf;
  return isleaf;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    ans = 0;
    G.assign(n, vector<int>());
    for (int i = 1; i < n; ++i) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    dfs(0);
    cout << ans << "\n";
  }
}
