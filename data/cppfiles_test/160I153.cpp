#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, rb, cb, rd, cd;
  cin >> n >> m >> rb >> cb >> rd >> cd;
  if (rb == rd || cb == cd) {
    cout << 0 << endl;
    return;
  }
  if (rd > rb && cd > cb) {
    cout << min(rd - rb, cd - cb) << endl;
    return;
  }
  if (rd < rb && cd < cb) {
    cout << min(n - rb + n - rd, m - cb + m - cd) << endl;
    return;
  }
  if (rd < rb && cd > cb) {
    cout << cd - cb << endl;
    return;
  }
  if (rd > rb && cd < cb) {
    cout << rd - rb << endl;
    return;
  }
  assert(false);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
