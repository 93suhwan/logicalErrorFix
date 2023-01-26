#include <bits/stdc++.h>
using namespace std;
long long n, k, dis[102][102], ans, tmm, mod = 1e9 + 7, vis[102][102],
                                         dp[102][102];
vector<int> gr[102];
vector<long long> v;
void dfs(int x, int p) {
  dis[x][0]++;
  for (int i = 0; i < gr[x].size(); i++) {
    int u = gr[x][i];
    if (u == p) continue;
    dfs(u, x);
    for (int j = 0; j <= n; j++) dis[x][j] += dis[u][j - 1];
  }
}
long long f(int x, int nm) {
  if (nm == k) return 1;
  if (x == v.size()) return 0;
  if (vis[x][nm] == tmm) return dp[x][nm];
  long long ans = 0;
  vis[x][nm] = tmm;
  ans = (ans + f(x + 1, nm)) % mod;
  ans = (ans + f(x + 1, nm + 1) * v[x]) % mod;
  return dp[x][nm] = ans;
}
void root(int x, int p) {
  for (int j = 1; j <= n; j++) {
    for (int z = 0; z < gr[x].size(); z++) {
      int u = gr[x][z];
      if (dis[u][j - 1] > 0) v.push_back(dis[u][j - 1]);
    }
    if (v.size() >= k) {
      tmm++;
      ans = (ans + f(0, 0)) % mod;
    }
    v.clear();
  }
  for (int i = 0; i < gr[x].size(); i++) {
    int u = gr[x][i];
    if (u == p) continue;
    for (int j = 1; j <= n; j++) dis[x][j] -= dis[u][j - 1];
    for (int j = 1; j <= n; j++) dis[u][j] += dis[x][j - 1];
    root(u, x);
    for (int j = 1; j <= n; j++) dis[u][j] -= dis[x][j - 1];
    for (int j = 1; j <= n; j++) dis[x][j] += dis[u][j - 1];
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    ans = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= 100; j++) dis[i][j] = 0;
      gr[i].clear();
    }
    for (int i = 0; i < n - 1; i++) {
      int x, y;
      cin >> x >> y;
      gr[x].push_back(y);
      gr[y].push_back(x);
    }
    if (k == 2) {
      cout << (n * (n - 1)) / 2 << endl;
      continue;
    }
    dfs(1, 0);
    root(1, 0);
    cout << ans << endl;
  }
}
