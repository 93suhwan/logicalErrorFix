#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
vector<vector<int>> g;
int n;
int leaves = 0;
int flag;
int sz[200005];
int can[200005];
int bud;
void dfs(int nn, int pp) {
  sz[nn] = 1;
  can[nn] = 1;
  int curr = 0;
  for (auto u : g[nn]) {
    if (u == pp) continue;
    dfs(u, nn);
    sz[nn] += sz[u];
    if (sz[u] == 1) {
      curr = 1;
    }
  }
  if (curr and nn != 1) bud++;
  if (curr and nn == 1) flag = 1;
  if (sz[nn] == 1) leaves++;
}
void solve() {
  cin >> n;
  g.clear();
  g.resize(n + 1);
  memset(sz, 0, sizeof(sz));
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  leaves = 0;
  flag = 0;
  bud = 0;
  int ans;
  dfs(1, -1);
  ans = leaves - bud;
  if (flag == 0) ans += 1;
  cout << ans << '\n';
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long tc = 1;
  cin >> tc;
  for (long long i = 1; i <= tc; i++) {
    solve();
  }
}
