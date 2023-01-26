#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const ll N = 2111;
ll st[N][N];
pair<ll, ll> endAt[N][N];
int dfs(int i, int j, vector<string>& maze) {
  if (st[i][j] == -2) return 1;
  if (st[i][j] > 0) return st[i][j];
  st[i][j] = 1;
  endAt[i][j] = make_pair(i, j);
  int di = 0, dj = 0;
  if (maze[i][j] == 'L') dj = -1;
  if (maze[i][j] == 'R') dj = 1;
  if (maze[i][j] == 'U') di = -1;
  if (maze[i][j] == 'D') di = 1;
  int ni = i + di, nj = j + dj;
  if (0 <= ni && ni < maze.size() && 0 <= nj && nj < maze[0].size()) {
    dfs(ni, nj, maze);
    st[i][j] = 1 + st[ni][nj];
    endAt[i][j] = endAt[ni][nj];
    if (endAt[i][j].first == i && endAt[i][j].second == j) {
      st[i][j]--;
    }
  } else {
    st[i][j] = 1;
    endAt[i][j] = make_pair(ni, nj);
  };
  return st[i][j];
}
void solve() {
  ll n, m;
  cin >> n >> m;
  vector<string> maze(n);
  for (int i = 0; i < n; i++) {
    cin >> maze[i];
    for (int j = 0; j < m; j++) st[i][j] = 0;
  }
  ll ans = 1, l, r;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ll t = dfs(i, j, maze);
      if (t >= ans) {
        ans = t;
        l = i + 1;
        r = j + 1;
      }
    }
  }
  cout << l << " " << r << " " << ans << endl;
}
int main() {
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}
