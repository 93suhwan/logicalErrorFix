#include <bits/stdc++.h>
using namespace std;
const int M = 1000000007;
const int MM = 998244353;
template <typename T, typename U>
static inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
static inline void amax(T &x, U y) {
  if (x < y) x = y;
}
int _runtimeTerror_() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= k; ++i) {
    int c;
    cin >> c;
    pair<int, int> cur = {1, c};
    while (cur.first <= n) {
      auto [x, y] = cur;
      if (a[x][y] == 2) {
        ++cur.first;
        continue;
      }
      if (a[x][y] == 3) {
        --cur.second;
      } else {
        ++cur.second;
      }
      a[x][y] = 2;
    }
    cout << cur.second << " ";
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  while (TESTS--) _runtimeTerror_();
  return 0;
}
