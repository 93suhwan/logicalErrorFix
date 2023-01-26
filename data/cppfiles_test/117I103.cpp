#include <bits/stdc++.h>
using namespace std;
const int nmax = 1e6;
const int dirs = 4;
vector<char> v[nmax + 2];
queue<pair<int, int> > q;
int dl[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int blocked(pair<int, int> cel) {
  int cate = 0;
  for (int dir = 0; dir < dirs; dir++)
    cate += (v[cel.first + dl[dir]][cel.second + dc[dir]] == '#');
  return cate;
}
void solve() {
  int n, m;
  cin >> n >> m;
  v[0].resize(m + 2);
  for (int i = 0; i <= m + 1; i++) v[0][i] = '#';
  for (int i = 1; i <= n; i++) {
    v[i].resize(m + 2);
    v[i][0] = v[i][m + 1] = '#';
    for (int j = 1; j <= m; j++) {
      cin >> v[i][j];
      if (v[i][j] == 'L') q.push({i, j});
    }
  }
  v[n + 1].resize(m + 2);
  for (int i = 0; i <= m + 1; i++) v[n + 1][i] = '#';
  while (!q.empty()) {
    pair<int, int> x = q.front();
    q.pop();
    for (int dir = 0; dir < dirs; dir++) {
      pair<int, int> vec = {x.first + dl[dir], x.second + dc[dir]};
      if (v[vec.first][vec.second] == '.' && blocked(vec) >= 2) {
        v[vec.first][vec.second] = '+';
        q.push(vec);
      }
    }
  }
  for (int i = 1; i <= n; i++, cout << '\n')
    for (int j = 1; j <= m; j++) cout << v[i][j] << ' ';
  for (int i = 0; i <= n + 1; i++) v[i].clear();
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
