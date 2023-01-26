#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, i, j, k, m, x;
  long long int check = 0, check1 = 0;
  cin >> m >> n;
  vector<vector<long long int>> a(m, vector<long long int>(n, 0));
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) cin >> a[i][j];
  }
  long long int ans = 0;
  long long int st = 0, ed = 1e9, mid;
  while (st <= ed) {
    mid = (st + ed) / 2;
    check = 0;
    vector<long long int> b(n, 0);
    for (i = 0; i < m; i++) {
      check1 = 0;
      for (j = 0; j < n; j++) {
        if (a[i][j] >= mid) {
          if (check1 == 1) check = 1;
          check1 = 1;
          b[j] = 1;
        }
      }
    }
    if (check) {
      ans = max(ans, mid);
      st = mid + 1;
    } else {
      ed = mid - 1;
    }
  }
  cout << ans << endl;
}
int main() {
  long long int t, i;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
