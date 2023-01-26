#include <bits/stdc++.h>
using namespace std;
constexpr int64_t mod = 1000000007;
void solve() {
  int64_t n, m, rr, cr, rd, cd;
  cin >> n >> m >> rr >> cr >> rd >> cd;
  int64_t cway = 0, rway = 0;
  if (rd >= rr) {
    rway = rd - rr;
  } else {
    rway = abs(rd - rr) + 2 * (n - rr);
  }
  if (cd >= cr) {
    cway = cd - cr;
  } else {
    cway = abs(cd - cr) + 2 * (m - cr);
  }
  cout << min(cway, rway) << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int64_t t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
