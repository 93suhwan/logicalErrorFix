#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
char a[N][N];
int T, n, m, id[N][N];
int head[N * N], ver[N * N << 1], Next[N * N << 1], tot;
int deg[N * N], dp[N * N];
pair<int, int> sta[N * N];
queue<int> q;
inline void add(int x, int y) {
  deg[y]++;
  ver[++tot] = y;
  Next[tot] = head[x];
  head[x] = tot;
}
inline void topsort() {
  while (!q.empty()) q.pop();
  for (int i = 1; i <= n * m; i++)
    if (!deg[i]) q.push(i), dp[i] = 1;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = head[x], y; i; i = Next[i]) {
      y = ver[i];
      if (dp[y] < dp[x] + 1) dp[y] = dp[x] + 1, sta[y] = sta[x];
      if (!--deg[y]) q.push(y);
    }
  }
}
inline pair<int, pair<int, int>> bfs(int a, int b) {
  int s = id[a][b];
  int mx = 0, siz = 0;
  pair<int, int> ss;
  while (!q.empty()) q.pop();
  q.push(s);
  while (!q.empty()) {
    int x = q.front();
    q.pop(), deg[x] = 0;
    siz++;
    if (dp[x] > mx) mx = dp[x], ss = sta[x];
    for (int i = head[x], y; i; i = Next[i]) {
      if (!deg[y = ver[i]]) continue;
      q.push(y);
    }
  }
  if (!mx) return {siz, {a, b}};
  return {mx + siz - 1, ss};
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> T;
  while (T--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> (a[i] + 1);
    for (int i = 1, k = 0; i <= n; i++)
      for (int j = 1; j <= m; j++) id[i][j] = ++k, sta[k] = {i, j};
    memset(head + 1, 0, sizeof(int) * n * m), tot = 0;
    memset(deg + 1, 0, sizeof(int) * n * m);
    memset(dp + 1, 0, sizeof(int) * n * m);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        if (a[i][j] == 'U' && i > 1) add(id[i][j], id[i - 1][j]);
        if (a[i][j] == 'D' && i < n) add(id[i][j], id[i + 1][j]);
        if (a[i][j] == 'L' && j > 1) add(id[i][j], id[i][j - 1]);
        if (a[i][j] == 'R' && j < m) add(id[i][j], id[i][j + 1]);
      }
    topsort();
    int x = 0, y = 0, ans = -1;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        if (deg[id[i][j]]) {
          auto res = bfs(i, j);
          if (res.first > ans) {
            ans = res.first;
            x = res.second.first, y = res.second.second;
          }
        } else {
          if (dp[id[i][j]] > ans) {
            ans = dp[id[i][j]];
            x = sta[id[i][j]].first, y = sta[id[i][j]].second;
          }
        }
      }
    cout << x << " " << y << " " << ans << "\n";
  }
  return 0;
}
