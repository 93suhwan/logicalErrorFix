#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
void solve() {
  int n, m, rb, cb, rd, cd;
  cin >> n >> m >> rb >> cb >> rd >> cd;
  if (rb == rd || cb == cd) {
    cout << "0\n";
    return;
  }
  if (rb < rd && cb < cd) {
    cout << min(rd - rb, cd - cb) << '\n';
    return;
  }
  if (rb < rd) {
    cout << rd - rb << '\n';
    return;
  }
  if (cb < cd) {
    cout << cd - cb << '\n';
    return;
  }
  n += (n - rd);
  m += (m - cd);
  cout << min(n - rb, m - cb) << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
