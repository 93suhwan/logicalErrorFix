#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 5;
int dis[maxn][maxn];
bool ins[maxn][maxn], vis[maxn][maxn];
char a[maxn][maxn];
int n, m;
void init() {
  for (int i = 1; i <= n + 1; ++i) {
    for (int j = 1; j <= m + 1; ++j) {
      vis[i][j] = false;
      dis[i][j] = 0;
      ins[i][j] = false;
    }
  }
}
bool out(int x, int y) {
  if (x < 1 || x > n || y < 1 || y > m) return true;
  return false;
}
stack<pair<int, int> > s;
void dfs(int x, int y) {
  s.push({x, y});
  ins[x][y] = true;
  while (s.size()) {
    int xx = s.top().first, yy = s.top().second;
    char cur = a[xx][yy];
    if (cur == 'D') xx++;
    if (cur == 'U') xx--;
    if (cur == 'L') yy--;
    if (cur == 'R') yy++;
    if (vis[xx][yy] || out(xx, yy)) {
      int now = dis[xx][yy];
      while (s.size()) {
        now++;
        dis[s.top().first][s.top().second] = now;
        vis[s.top().first][s.top().second] = true;
        ins[s.top().first][s.top().second] = false;
        s.pop();
      }
    } else if (ins[xx][yy]) {
      int flag = 1;
      int now = 0;
      stack<pair<int, int> > temp;
      while (s.size()) {
        now++;
        vis[s.top().first][s.top().second] = true;
        ins[s.top().first][s.top().second] = false;
        temp.push(s.top());
        if (s.top().first == xx && s.top().second == yy) flag = 0;
        s.pop();
        if (!flag) break;
      }
      while (temp.size()) {
        dis[temp.top().first][temp.top().second] = now;
        temp.pop();
      }
    } else {
      s.push({xx, yy});
      ins[xx][yy] = true;
    }
  }
}
void solve() {
  cin >> n >> m;
  init();
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] + 1;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (vis[i][j]) continue;
      dfs(i, j);
    }
  }
  int maxx = 0;
  pair<int, int> res;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (dis[i][j] > maxx) {
        maxx = dis[i][j];
        res = {i, j};
      }
    }
  }
  cout << res.first << ' ' << res.second << ' ' << maxx << '\n';
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
