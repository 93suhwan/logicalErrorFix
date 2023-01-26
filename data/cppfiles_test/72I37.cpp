#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int i, j, k, l, m, n, t, r, p = 0, x, y, q;
  cout << "? 1 1\n" << flush;
  cin >> k;
  l = 1;
  r = 1e9;
  while (l <= r && p <= 31) {
    p++;
    m = (l + r) / 2;
    cout << "? 1 " << m << endl << flush;
    cin >> t;
    if (t + 1 < m + k) {
      r = m - 1;
    } else {
      l = m;
    }
  }
  x = (l + r) / 2;
  y = k - 1 - 1 - x;
  cout << "? 1 " << (int)1e9 << endl << flush;
  cin >> t;
  q = 1e9 + x - 1 - t;
  cout << "? " << (int)1e9 << " 1" << endl << flush;
  cin >> t;
  p = 1e9 + y - 1 - t;
  cout << "! " << x << ' ' << y << ' ' << p << ' ' << q << endl << flush;
  return 0;
}
