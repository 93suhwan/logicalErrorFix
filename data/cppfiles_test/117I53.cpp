#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int n, m;
vector<string> g;
void bfs(queue<PII> &q) {
  vector<vector<bool>> st(n, vector<bool>(m));
  while (!q.empty()) {
    auto t = q.front();
    q.pop();
    int x = t.first, y = t.second;
    st[x][y] = true;
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
      int a = x + dx[i], b = y + dy[i];
      if (a < 0 || a == n || b < 0 || b == m) continue;
      if (g[a][b] == '.') {
        cnt++;
        if (!st[a][b]) q.push({a, b});
      }
    }
    if (g[x][y] == '.' && cnt <= 1) g[x][y] = '+';
  }
  for (auto &s : g) cout << s << endl;
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
        q.push({i, j});
        bfs(q);
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
