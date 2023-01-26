#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int n, m;
vector<string> g;
void bfs(queue<PII> &q) {
  while (!q.empty()) {
    auto t = q.front();
    q.pop();
    int x = t.first, y = t.second;
    g[x][y] = '+';
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx < 0 || nx == n || ny < 0 || ny == m) continue;
      if (g[nx][ny] != '.') continue;
      int cnt = 0;
      for (int it = 0; it < 4; it++) {
        int a = nx + dx[it], b = ny + dy[it];
        if (a < 0 || a == n || b < 0 || b == m) continue;
        if (g[a][b] == '.') cnt++;
      }
      if (cnt <= 1) q.push({nx, ny});
    }
  }
}
void solve() {
  g.clear();
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    g.push_back(s);
  }
  queue<PII> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] == 'L') {
        for (int idx = 0; idx < 4; idx++) {
          int x = i + dx[idx], y = j + dy[idx];
          if (x < 0 || x == n || y < 0 || y == m || g[x][y] != '.') continue;
          int cnt = 0;
          for (int it = 0; it < 4; it++) {
            int a = x + dx[it], b = y + dy[it];
            if (a < 0 || a == n || b < 0 || b == m) continue;
            if (g[a][b] == '.') cnt++;
          }
          if (cnt <= 1) q.push({x, y});
        }
        bfs(q);
        for (int i = 0; i < n; i++) cout << g[i] << '\n';
        return;
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int testcases;
  cin >> testcases;
  while (testcases--) solve();
  return 0;
}
