#include <bits/stdc++.h>
using namespace std;
void solve() {
  int c, d;
  cin >> c >> d;
  c = abs(c);
  d = abs(d);
  int k = 0;
  if (c > d) swap(c, d);
  if (c == d) {
    k++;
  }
  if (c == d && c == 0) {
    cout << 0 << endl;
  }
  d -= c;
  c = 0;
  if (d % 2 != 0) {
    cout << -1 << endl;
    return;
  }
  if (d == 0) {
    cout << k << endl;
    return;
  }
  cout << k + 2 << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t_;
  cin >> t_;
  while (t_--) solve();
  return 0;
}
