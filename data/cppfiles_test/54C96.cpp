#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
const int mod = 1e9 + 7;
int col[maxn], ans, n, m, cnt;
bool vis[maxn], dor;
vector<pair<int, int> > g[maxn];
vector<int> ver;
void dfs(int v) {
  cnt = cnt + 1;
  ver.push_back(v);
  vis[v] = 1;
  for (auto i : g[v]) {
    if (!vis[i.first]) {
      col[i.first] = col[v] ^ i.second;
      dfs(i.first);
    } else {
      if (col[i.first] != col[v] ^ i.second) dor = 1;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
      int v, u;
      string s;
      cin >> v >> u >> s;
      bool x = (s == "imposter");
      g[v].push_back(make_pair(u, x));
      g[u].push_back(make_pair(v, x));
    }
    ans = 0;
    for (int i = 1; i <= n; i++)
      if (!vis[i]) {
        cnt = 0;
        ver.clear();
        dfs(i);
        int imp = 0;
        for (int i = 0; i < ver.size(); i++) imp = imp + col[ver[i]];
        ans = ans + max(imp, cnt - imp);
      }
    cout << ((dor) ? -1 : ans) << '\n';
    dor = 0;
    for (int i = 1; i <= n; i++) {
      col[i] = vis[i] = 0;
      g[i].clear();
    }
  }
}
