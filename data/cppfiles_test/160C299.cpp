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
  if (rb > rd) rd = n + (n - rd);
  if (cb > cd) cd = m + (m - cd);
  cout << min(rd - rb, cd - cb) << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
