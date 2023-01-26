#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  int rb, cb;
  cin >> rb >> cb;
  int rd, cd;
  cin >> rd >> cd;
  int ans = INT_MAX;
  if (rd >= rb) {
    ans = min(ans, rd - rb);
  } else {
    ans = min(ans, 2 * (n - rb) + rb - rd);
  }
  if (cd >= cb) {
    ans = min(ans, cd - cb);
  } else {
    ans = min(ans, 2 * (m - cb) + cb - cd);
  }
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
}
