#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, M = 510;
int h[N], ne[N], w[N], e[N], idx;
int st[N];
int dp[N][2];
vector<int> tmp;
bool f;
void add(int a, int b, int c) {
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
void dfs(int u, int state) {
  if (f) return;
  tmp.push_back(u);
  st[u] = state;
  for (int i = h[u]; ~i; i = ne[i]) {
    int j = e[i];
    if (st[j] != -1) {
      if (state == 0 && st[j] == 1 && w[i] == 1) f = 1;
      if (state == 0 && st[j] == 0 && w[i] == 0) f = 1;
      if (state == 1 && st[j] == 0 && w[i] == 1) f = 1;
      if (state == 1 && st[j] == 1 && w[i] == 0) f = 1;
    } else {
      if (state == 0 && w[i] == 0) {
        dfs(j, 1);
        dp[u][0] += dp[j][1];
      } else if (state == 0 && w[i] == 1) {
        dfs(j, 0);
        dp[u][0] += dp[j][0];
      } else if (state == 1 && w[i] == 1) {
        dfs(j, 1);
        dp[u][1] += dp[j][1];
      } else {
        dfs(j, 0);
        dp[u][1] += dp[j][0];
      }
    }
  }
}
int main() {
  int _ = 1;
  scanf("%d", &_);
  while (_--) {
    f = 0;
    int n, m;
    scanf("%d%d", &n, &m);
    idx = 0;
    for (int i = 0; i <= n; i++)
      st[i] = -1, h[i] = -1, dp[i][0] = 0, dp[i][1] = 1;
    for (int i = 1; i <= m; i++) {
      int u, v;
      char x[10];
      scanf("%d%d%s", &u, &v, x);
      if (x[0] == 'i')
        add(u, v, 0), add(v, u, 0);
      else
        add(u, v, 1), add(v, u, 1);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (st[i] == -1) {
        tmp.clear();
        dfs(i, 1);
        if (f) break;
        for (auto &x : tmp) st[x] = -1;
        dfs(i, 0);
        if (f) break;
        ans += max(dp[i][0], dp[i][1]);
      }
    }
    if (f)
      cout << -1 << '\n';
    else
      cout << ans << '\n';
  }
  return 0;
}
