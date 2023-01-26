#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
void solve() {
  long long m, n, mx = 0, mn = 1e10;
  cin >> m >> n;
  vector<vector<long long>> grid(m, vector<long long>(n));
  for (long long i = 0; i < m; i++)
    for (long long j = 0; j < n; j++) {
      cin >> grid[i][j];
      mx = max(mx, grid[i][j]);
      mn = min(mn, grid[i][j]);
    }
  auto isPossible = [&](long long val) {
    vector<set<long long>> pos(m);
    for (long long i = 0; i < m; i++)
      for (long long j = 0; j < n; j++) {
        if (grid[i][j] >= val) {
          pos[i].insert(j);
        }
        if (pos[i].size() > 1) {
          return true;
        }
      }
    return false;
  };
  long long s = mn, e = mx, res = s;
  while (s <= e) {
    long long mid = s + (e - s) / 2;
    if (isPossible(mid)) {
      res = mid;
      s = mid + 1;
    } else {
      e = mid - 1;
    }
  }
  cout << res << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
