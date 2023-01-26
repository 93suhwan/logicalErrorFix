#include <bits/stdc++.h>
using namespace std;
string s[1000500];
string g[1005000];
vector<int> di = {-1, 1, 0, 0};
vector<int> dj = {0, 0, -1, 1};
void solve() {
  int n, m;
  cin >> n >> m;
  int x, y;
  list<pair<int, int> > Q;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 0; j < m; j++) {
      if (s[i][j] == 'L') {
        x = i;
        y = j;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    g[i] = string(m, 0);
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '#') continue;
      int fl = 0;
      for (int e = 0; e < 4; e++) {
        int ii = i + di[e];
        int jj = j + dj[e];
        if (ii >= 0 && ii < n && jj >= 0 && jj < m) {
          if (s[ii][jj] == '.' || s[ii][jj] == 'L') {
            ++g[i][j];
            if (s[ii][jj] == 'L') {
              fl = 1;
              --g[i][j];
            }
          }
        }
      }
      if (fl && g[i][j] <= 1) {
        Q.push_back({i, j});
      }
    }
  }
  while (Q.size()) {
    int i = Q.front().first;
    int j = Q.front().second;
    Q.pop_front();
    s[i][j] = '+';
    for (int e = 0; e < 4; e++) {
      int ii = i + di[e];
      int jj = j + dj[e];
      if (ii >= 0 && ii < n && jj >= 0 && jj < m) {
        if (s[ii][jj] == '.') {
          --g[ii][jj];
          if (g[ii][jj] <= 1) {
            Q.push_back({ii, jj});
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++) printf("%s\n", s[i].c_str());
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
