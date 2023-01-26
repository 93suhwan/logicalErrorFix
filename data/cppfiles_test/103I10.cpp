#include <bits/stdc++.h>
using namespace std;
const int max_k = 2000;
vector<pair<int, int> > go = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int a[max_k][max_k];
int used[max_k][max_k];
int ans[max_k][max_k];
int tin[max_k][max_k];
signed main() {
  cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  map<char, int> mp;
  mp['R'] = 0, mp['D'] = 1, mp['U'] = 2, mp['L'] = 3;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < m; j++) a[i][j] = mp[s[j]];
    }
    auto f = [n, m](int X, int Y) {
      return X >= 0 && Y >= 0 && X < n && Y < m;
    };
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (used[i][j] != 0) continue;
        int x = i, y = j;
        int loccnt = 0;
        vector<pair<int, int> > da;
        while (f(x, y) && used[x][y] == 0) {
          da.emplace_back(x, y);
          used[x][y]++;
          tin[x][y] = loccnt++;
          pair<int, int> &p = go[a[x][y]];
          x += p.first;
          y += p.second;
        }
        if (!f(x, y)) {
          ans[da.back().first][da.back().second] = 1;
          used[da.back().first][da.back().second]++;
          da.pop_back();
        }
        if (da.empty()) continue;
        if (used[x][y] == 1) {
          bool chg = false;
          int sz = tin[da.back().first][da.back().second] - tin[x][y] + 1;
          while (da.size()) {
            pair<int, int> &p = da.back();
            pair<int, int> &pp = go[a[p.first][p.second]];
            if (chg)
              ans[p.first][p.second] =
                  ans[p.first + pp.first][p.second + pp.second] + 1;
            else
              ans[p.first][p.second] = sz;
            used[p.first][p.second]++;
            if (x == p.first && y == p.second) chg = true;
            da.pop_back();
          }
          continue;
        }
        while (da.size()) {
          pair<int, int> &p = da.back();
          pair<int, int> &pp = go[a[p.first][p.second]];
          ans[p.first][p.second] =
              ans[p.first + pp.first][p.second + pp.second] + 1;
          used[p.first][p.second]++;
          da.pop_back();
        }
      }
    }
    pair<int, pair<int, int> > mx = {0, {0, 0}};
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) mx = max(mx, {ans[i][j], {i, j}});
    }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) ans[i][j] = 0, tin[i][j] = 0, used[i][j] = 0;
    cout << mx.second.first + 1 << " " << mx.second.second + 1 << " "
         << mx.first << '\n';
  }
}
