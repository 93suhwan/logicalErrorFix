#include <bits/stdc++.h>
using namespace std;
const int64_t INF = 1e18 + 1;
const int64_t mod = 1e9 + 7;
void solve() {
  int64_t n, k;
  cin >> n >> k;
  vector<int64_t> x(n);
  for (int64_t i = 0; i < n; i++) {
    cin >> x[i];
  }
  sort(x.begin(), x.end());
  if (abs(x[0]) > abs(x[n - 1])) {
    for (int64_t i = 0; i < n; i++) {
      x[i] *= -1;
    }
    sort(x.begin(), x.end());
  }
  int64_t cur = k;
  int64_t cur_x = x[n - 1];
  int64_t ans = 0;
  for (int64_t i = n - 1; i >= 0; i--) {
    if (x[i - 1] * x[i] <= 0) {
      cur = k;
    }
    ans += abs(cur_x - x[i]);
    cur_x = x[i];
    if (cur == 0) {
      ans += 2 * abs(x[i]);
      cur = k;
    }
    cur--;
  }
  ans += abs(x[0]);
  cout << ans << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int64_t t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
