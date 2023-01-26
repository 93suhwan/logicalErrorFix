#include <bits/stdc++.h>
using namespace std;
const long long N = 810000;
vector<tuple<int, int, int>> G[210000];
vector<int> vis;
vector<int> mem;
vector<int> states;
int gadd;
int fk;
void dfs(int p, int st) {
  if (vis[p]) {
    if (states[p] != st) fk = 1, gadd = -1000000;
    return;
  }
  vis[p] = 1;
  mem.push_back(p);
  states[p] = st;
  if (st == 0) gadd++;
  for (auto [adj, state, end_p] : G[p]) {
    if (st == 0) {
      if (end_p) {
        dfs(adj, state ^ 1);
      } else {
        dfs(adj, state == st ? 1 : 0);
      }
    } else {
      if (end_p) {
        dfs(adj, state);
      } else {
        dfs(adj, state == st ? 1 : 0);
      }
    }
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  long long kase = 1;
  cin >> kase;
  for (long long ka = 1; ka <= kase; ka++) {
    int n, m;
    cin >> n >> m;
    vis.assign(n + 1, 0);
    states.assign(n + 1, 0);
    mem.clear();
    for (int i = 1; i <= n; i++) G[i].clear();
    for (int i = 0; i < m; i++) {
      int a, b;
      string st;
      cin >> a >> b >> st;
      int state = 0;
      if (st == "imposter")
        state = 0;
      else
        state = 1;
      G[a].push_back({b, state, 1});
      G[b].push_back({a, state, 0});
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (vis[i]) continue;
      int iadd;
      int ifk;
      gadd = 0;
      mem.clear();
      fk = 0;
      dfs(i, 1);
      iadd = gadd;
      ifk = fk;
      for (auto vp : mem) vis[vp] = 0;
      fk = 0;
      gadd = 0;
      dfs(i, 0);
      ans += max(gadd, iadd);
      if (ifk and fk) break;
      fk = 0;
    }
    if (fk)
      cout << -1 << endl;
    else
      cout << ans << endl;
  }
}
