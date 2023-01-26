#include <bits/stdc++.h>
using namespace std;
long long n, k, dis[102][102], ans, mod = 1e9 + 7, fact[202];
vector<int> gr[102];
void dfs(int x, int p, int pr, int l) {
  dis[pr][l]++;
  for (int i = 0; i < gr[x].size(); i++) {
    int u = gr[x][i];
    if (u == p) continue;
    dfs(u, x, pr, l + 1);
  }
}
long long pw(long long x, long long y) {
  if (y == 0) return 1;
  long long ans = pw(x, y / 2);
  ans = (ans * ans) % mod;
  if (y % 2) ans = (ans * x) % mod;
  return ans;
}
long long c(long long x, long long y) {
  if (x > y) return 0;
  long long ans = (fact[x] * pw((fact[y] * fact[x - y]) % mod, mod - 2)) % mod;
  return ans;
}
int main() {
  int t;
  cin >> t;
  fact[0] = 1;
  for (int i = 1; i <= 200; i++) fact[i] = (fact[i - 1] * i) % mod;
  while (t--) {
    ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= 100; j++) dis[i][j] = 0;
      gr[i].clear();
    }
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
      int x, y;
      cin >> x >> y;
      gr[x].push_back(y);
      gr[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) dfs(i, 0, i, 0);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) ans = (ans + c(dis[i][j], k)) % mod;
    }
    if (k == 2) ans = (ans + n - 1) % mod;
    cout << ans << endl;
  }
}
