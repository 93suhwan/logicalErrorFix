#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long long LINF = LLONG_MAX;
long long n, m;
vector<string> grid;
vector<pair<long long, long long>> moves = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
bool isVal(long long i, long long j) {
  if (i < 0 || j < 0 || i >= n || j >= m) return false;
  if (grid[i][j] == '.') return true;
  return false;
}
void dfs(long long i, long long j) {
  long long cnt = 0;
  for (auto p : moves) {
    if (isVal(i + p.first, j + p.second)) {
      cnt++;
    }
  }
  if (cnt == 1 || cnt == 0) {
    grid[i][j] = '+';
    for (auto p : moves) {
      if (isVal(i + p.first, j + p.second)) {
        dfs(i + p.first, j + p.second);
      }
    }
  }
}
void solve() {
  cin >> n >> m;
  grid.clear();
  grid.resize(n);
  for (long long i = 0; i < n; i++) cin >> grid[i];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (grid[i][j] == 'L') {
        for (auto p : moves) {
          if (isVal(i + p.first, j + p.second)) {
            dfs(i + p.first, j + p.second);
          }
        }
      }
    }
  }
  for (long long i = 0; i < n; i++) {
    cout << grid[i] << ("\n");
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t = 1, count = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
