#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a = 0, b, c, m;
  cin >> a >> b >> c >> m;
  if ((a - 1) + (b - 1) + (c - 1) < m) {
    cout << "NO"
         << "\n";
    ;
    return;
  }
  int x, y, z;
  if (a >= b && a >= c) {
    x = a;
    if (b <= c) {
      y = c;
      z = b;
    } else {
      y = b;
      z = c;
    }
  } else if (b >= a && b >= c) {
    x = b;
    if (a <= c) {
      y = c;
      z = a;
    } else {
      y = a;
      z = c;
    }
  } else if (c >= b && c >= a) {
    x = c;
    if (b <= a) {
      y = a;
      z = b;
    } else {
      y = b;
      z = a;
    }
  }
  if (m == 0) {
    if (x > (y + z + 1)) {
      cout << "NO"
           << "\n";
      ;
    } else
      cout << "YES"
           << "\n";
    ;
    return;
  }
  if (x - 1 > m) {
    x = x - m;
    x--;
    if (x > (y + z + 1)) {
      cout << "NO"
           << "\n";
      ;
    } else
      cout << "YES"
           << "\n";
    ;
  } else
    cout << "YES"
         << "\n";
  ;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms"
       << '\n';
  return 0;
}
