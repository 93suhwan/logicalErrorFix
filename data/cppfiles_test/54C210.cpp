#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 5;
int tt, tr;
int vs[maxn];
int n, m, now;
vector<int> cl;
vector<pair<int, int>> E[maxn];
void dfs(int nd, int tp) {
  if (tp) now++;
  vs[nd] = tp;
  cl.push_back(nd);
  for (auto i : E[nd]) {
    if (vs[i.first] != -1 and vs[i.first] != i.second ^ tp) tr = 0;
    if (vs[i.first] == -1) dfs(i.first, tp ^ i.second);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> tt;
  while (tt--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) E[i].clear(), vs[i] = -1;
    for (int i = 1; i <= m; i++) {
      int x, y;
      string c;
      cin >> x >> y >> c;
      int val = 1;
      if (c == "crewmate") val = 0;
      E[x].push_back({y, val});
      E[y].push_back({x, val});
    }
    bool jg = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (vs[i] != -1) continue;
      cl.clear();
      int mx = 0;
      tr = 1;
      now = 0;
      dfs(i, 0);
      if (!tr) {
        jg = 0;
        break;
      }
      mx = now;
      for (auto j : cl) vs[j] = -1;
      cl.clear();
      tr = 1;
      now = 0;
      dfs(i, 1);
      mx = max(mx, now);
      ans += mx;
    }
    if (!jg) {
      cout << "-1\n";
      continue;
    }
    cout << ans << '\n';
  }
}
