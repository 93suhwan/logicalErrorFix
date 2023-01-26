#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1);
set<int> eg[200005];
vector<int> clr[200005], eg0[200005];
int fa[200005], bud[200005], ans, sum = 0;
void pre1(int x) {
  for (int i : eg0[x]) {
    if (i == fa[x]) continue;
    fa[i] = x;
    eg[x].insert(i);
    pre1(i);
  }
}
void dfs(int x) {
  bud[x] = 1;
  if (x == 1) bud[x] = 0;
  if (eg[x].empty()) bud[x] = 0;
  for (int i : eg[x]) {
    dfs(i);
  }
  for (int i : clr[x]) eg[x].erase(i);
  clr[x].clear();
  if (eg[x].empty()) bud[x] = 0;
  for (int i : eg[x]) {
    if (eg[i].size() > 0) bud[x] = 0;
  }
  if (bud[x]) {
    clr[fa[x]].push_back(x);
    ans += eg[x].size() - 1;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      eg[i].clear();
      eg0[i].clear();
      bud[i] = 0;
      fa[i] = i;
    }
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      eg0[u].push_back(v);
      eg0[v].push_back(u);
    }
    pre1(1);
    ans = 0;
    dfs(1);
    bud[1] = 0;
    ans += max(1, (int)eg[1].size());
    cout << ans << '\n';
  }
}
