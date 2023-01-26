#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 50;
const int inf = 1e9 + 50;
char st[N][N];
int cnt0 = 0;
int n, m;
int to[N * N], d[N * N];
pair<int, int> p[N * N];
void init() {
  cin >> n >> m;
  cnt0 = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> st[i][j];
      cnt0++;
      p[cnt0] = {i, j}, d[cnt0] = 0, to[cnt0] = 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (st[i][j] == 'L')
        if (j - 1 >= 1)
          to[(i - 1) * n + j] = (i - 1) * n + j - 1, d[(i - 1) * n + j - 1]++;
      if (st[i][j] == 'R')
        if (j + 1 <= m)
          to[(i - 1) * n + j] = (i - 1) * n + j + 1, d[(i - 1) * n + j + 1]++;
      if (st[i][j] == 'U')
        if (i - 1 >= 1)
          to[(i - 1) * n + j] = (i - 2) * n + j, d[(i - 2) * n + j]++;
      if (st[i][j] == 'D')
        if (i + 1 <= n) to[(i - 1) * n + j] = i * n + j, d[i * n + j]++;
    }
  }
}
int f[N * N];
void dfs(int u) {
  if (f[u]) return;
  f[u] = 1;
  if (to[u] == 0) return;
  dfs(to[u]);
  f[u] += f[to[u]];
}
void solve() {
  queue<int> que;
  for (int i = 1; i <= cnt0; i++) {
    f[i] = 0;
    if (d[i] == 0) que.push(i);
  }
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    if (to[u] == 0) continue;
    d[to[u]]--;
    if (d[to[u]] == 0) que.push(to[u]);
  }
  queue<int> q;
  for (int i = 1; i <= cnt0; i++) {
    if (d[i] == 1) {
      int x = i;
      while (d[x]) {
        d[x]--, q.push(x);
        x = to[x];
      }
      int cnt = q.size();
      while (!q.empty()) {
        f[q.front()] = cnt;
        q.pop();
      }
    }
  }
  for (int i = 1; i <= cnt0; i++) dfs(i);
  int x, ans = -1;
  for (int i = 1; i <= cnt0; i++) {
    if (f[i] >= ans) {
      x = i, ans = f[i];
    }
  }
  cout << p[x].first << ' ' << p[x].second << ' ' << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    init();
    solve();
  }
  return 0;
}
