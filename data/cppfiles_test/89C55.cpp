#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int N = 2e5 + 10;
vector<int> g[N];
int type[N];
bool noleaf = 1;
int cnt = 0;
void dfs(int v, int p) {
  for (auto u : g[v]) {
    if (u == p) continue;
    dfs(u, v);
    if (type[u] == 0) {
      type[v] = 1;
      if (v == 1) noleaf = 0;
    }
  }
  if (v != 1) cnt += type[v];
}
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    g[i].clear();
    cnt = 0;
    type[i] = 0;
    noleaf = 1;
  }
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(1, 0);
  cout << n - 2 * cnt - 1 + noleaf << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
