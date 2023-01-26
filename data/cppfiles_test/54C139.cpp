#include <bits/stdc++.h>
using namespace std;
const int N = (int)3e5 + 10;
const int lg = 22;
const int mod = (int)1e9 + 7;
int c[N];
vector<vector<pair<int, int>>> g;
bool ok;
int r, b;
bool used[N];
void dfs(int v) {
  if (c[v] == 0)
    r++;
  else
    b++;
  used[v] = 1;
  for (pair<int, int> to : g[v]) {
    if (used[to.first]) {
      if (c[to.first] ^ c[v] != to.second) {
        ok = 0;
      }
    } else {
      c[to.first] = c[v] ^ to.second;
      dfs(to.first);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int n, m;
    cin >> n >> m;
    g.clear();
    g.resize(n);
    for (int i = 0; i <= n; i++) used[i] = 0;
    for (int i = 1; i <= m; i++) {
      int u, v;
      string s;
      cin >> u >> v >> s;
      --u, --v;
      if (s == "crewmate") {
        g[u].push_back({v, 0});
        g[v].push_back({u, 0});
      } else {
        g[u].push_back({v, 1});
        g[v].push_back({u, 1});
      }
    }
    ok = 1;
    int res = 0;
    for (int i = 0; i < n; i++) {
      if (used[i] == 0) {
        b = 0;
        r = 0;
        c[i] = 1;
        dfs(i);
        res += max(r, b);
      }
    }
    if (!ok) {
      cout << -1 << '\n';
      continue;
    }
    cout << res << '\n';
  }
  return 0;
}
