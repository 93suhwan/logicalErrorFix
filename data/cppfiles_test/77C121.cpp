#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int maxn = 1e3 + 10;
int n, m, mp[maxn][maxn], cnt, dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};
bool vis[maxn][maxn];
vector<int> ans;
void dfs(int x, int y) {
  if (vis[x][y] || x <= 0 || x > n || y <= 0 || y > m) return;
  vis[x][y] = 1, ++cnt;
  for (int i = 0; i < 4; ++i)
    if (!(mp[x][y] & (1 << i))) dfs(x + dx[i], y + dy[i]);
}
void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) scanf("%d", &mp[i][j]);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (!vis[i][j]) cnt = 0, dfs(i, j), ans.push_back(cnt);
  sort(ans.begin(), ans.end());
  for (int i = ans.size() - 1; ~i; --i) printf("%d ", ans[i]);
}
int main() {
  solve();
  return 0;
}
