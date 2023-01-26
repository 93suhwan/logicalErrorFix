#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
const int INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
int n, m;
char a[2005][2005];
int f[2005][2005];
void bfs(int pu, int pv) {
  set<pair<int, int> > s;
  vector<pair<int, int> > temp;
  temp.push_back(make_pair(pu, pv));
  int U = pu, V = pv;
  int val = 0;
  while (temp.size()) {
    int u = temp.back().first, v = temp.back().second;
    s.insert(make_pair(u, v));
    int x = u, y = v;
    if (a[u][v] == 'L') {
      y = v - 1;
    }
    if (a[u][v] == 'R') {
      y = v + 1;
    }
    if (a[u][v] == 'U') {
      x = u - 1;
    }
    if (a[u][v] == 'D') {
      x = u + 1;
    }
    if (x < 1 || x > n || y < 1 || y > m) {
      val = 0;
      break;
    }
    if (f[x][y] != -1) {
      val = f[x][y];
      break;
    }
    if (s.count(make_pair(x, y))) {
      vector<pair<int, int> > cc;
      while (1) {
        cc.push_back(temp.back());
        if (temp.back() == make_pair(x, y)) {
          temp.pop_back();
          break;
        }
        temp.pop_back();
      }
      for (auto [i, j] : cc) {
        f[i][j] = cc.size();
      }
      val = cc.size();
      break;
    }
    temp.push_back(make_pair(x, y));
  }
  while (temp.size()) {
    int u = temp.back().first, v = temp.back().second;
    temp.pop_back();
    f[u][v] = val + 1;
    val = f[u][v];
  }
}
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      f[i][j] = -1;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  int res = 0;
  pair<int, int> ans = {1, 1};
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (f[i][j] != -1) {
        continue;
      }
      bfs(i, j);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (res < f[i][j]) {
        res = f[i][j];
        ans = make_pair(i, j);
      }
    }
  }
  cout << ans.first << " " << ans.second << " " << res << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) solve();
}
