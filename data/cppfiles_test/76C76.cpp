#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
vector<int> g[maxn];
int ans[6];
bool bis[maxn];
bool vis[maxn];
int ris[maxn];
int n, m;
void dfs(int x, int step) {
  ans[step] = x;
  for (int i = 1; i < step; i++) {
    bool flag = 0;
    for (int j = 0; j < g[ans[i]].size(); j++) {
      int v = g[ans[i]][j];
      if (v == x) {
        flag = 1;
      }
    }
    if (!flag) {
      return;
    }
  }
  if (step >= 5) {
    for (int i = 1; i <= 5; i++) cout << ans[i] << " ";
    cout << "\n";
    ;
    exit(0);
  }
  bis[x] = 1;
  for (int i = 0; i < g[x].size(); i++) {
    int v = g[x][i];
    if (bis[v] || vis[v]) continue;
    dfs(v, step + 1);
  }
  bis[x] = 0;
}
void undfs(int x, int step) {
  if (vis[x]) return;
  ris[x]++;
  for (int i = 0; i < g[x].size(); i++) {
    int v = g[x][i];
    ris[v]++;
  }
  ans[step] = x;
  if (step >= 5) {
    for (int i = 1; i <= 5; i++) cout << ans[i] << " ";
    cout << "\n";
    ;
    exit(0);
  }
  for (int i = 1; i <= n; i++) {
    if (!ris[i]) undfs(i, step + 1);
  }
  for (int i = 0; i < g[x].size(); i++) {
    int v = g[x][i];
    ris[v]--;
  }
  ris[x]--;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  memset(bis, 0, sizeof(bis));
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    dfs(i, 1);
    vis[i] = 1;
  }
  memset(ris, 0, sizeof(vis));
  memset(vis, 0, sizeof(bis));
  for (int i = 1; i <= n; i++) {
    undfs(i, 1);
    vis[i] = 1;
  }
  cout << "-1\n";
  return 0;
}
