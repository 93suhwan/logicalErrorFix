#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
bool dead[210000] = {0};
int ls[210000] = {0}, fs[210000] = {0};
set<int> g[210000];
void dfs(int i) {
  if (i == 0) return;
  if (fs[i] < 1) return;
  if (ls[i]) return;
  if (!dead[i]) ans--, dead[i] = 1;
  for (int x : g[i]) {
    if (!fs[i]) continue;
    fs[x]--, ls[x]--;
    dfs(x);
    x = 0;
  }
  fs[i] = 0;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  int o, u, v, q;
  while (m--) {
    cin >> u >> v;
    if (u > v) swap(u, v);
    g[u].insert(v);
    fs[u]++, fs[v]++;
    ls[v]++;
  }
  ans = n;
  for (int i = 0; i <= n; i++) dfs(i);
  cin >> q;
  while (q--) {
    cin >> o;
    if (o == 1) {
      cin >> u >> v;
      if (u > v) swap(u, v);
      g[u].insert(v);
      fs[u]++, fs[v]++;
      ls[v]++;
      if (!dead[u] && ls[u] == 0) dfs(u);
    }
    if (o == 2) {
      cin >> u >> v;
      if (u > v) swap(u, v);
      g[u].erase(v);
      fs[u]--, fs[v]--;
      ls[v]--;
      if (ls[v] == 0) dfs(v);
    }
    if (o == 3) cout << ans << endl;
  }
  return 0;
}
