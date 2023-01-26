#include <bits/stdc++.h>
using namespace std;
const int SIZE = 2e3 + 10;
const int mod = 1e9 + 7;
int n, t, m;
int posx, posy;
char mp[SIZE][SIZE];
int vis[SIZE][SIZE];
int sz;
int val[SIZE][SIZE];
void init() {
  for (int i = 0; i <= n + 1; i++) {
    for (int j = 0; j <= m + 1; j++) {
      vis[i][j] = 0;
      val[i][j] = 0;
    }
  }
  posx = posy = 0;
  sz = 0;
}
int dfs(int i, int j) {
  vector<pair<int, int>> save;
  int x = i, y = j, dfn = 1, v = 0;
  while (1) {
    if (val[i][j]) {
      v = val[i][j];
      break;
    }
    if (i == 0 || j == 0 || i > n || j > m) break;
    if (vis[i][j]) {
      posx = i, posy = j;
      sz = dfn - vis[i][j];
      break;
    }
    vis[i][j] = dfn++;
    save.push_back({i, j});
    if (mp[i][j] == 'L')
      j--;
    else if (mp[i][j] == 'R')
      j++;
    else if (mp[i][j] == 'U')
      i--;
    else if (mp[i][j] == 'D')
      i++;
  }
  while (save.size()) {
    auto it = save.back();
    int i = it.first, j = it.second;
    if (posx && posy)
      val[i][j] = sz;
    else
      val[i][j] = v + 1;
    if (posx == i && posy == j) {
      sz = 0;
      posx = 0, posy = 0;
    }
    v = val[i][j];
    save.pop_back();
  }
  return val[x][y];
}
void solve() {
  cin >> n >> m;
  init();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> mp[i][j];
    }
  }
  int tarx = 0, tary = 0;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!vis[i][j]) {
        if (ans < dfs(i, j)) {
          tarx = i, tary = j;
          ans = val[i][j];
        }
      }
    }
  }
  cout << tarx << " " << tary << " " << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
