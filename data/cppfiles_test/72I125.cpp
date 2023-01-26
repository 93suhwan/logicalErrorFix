#include <bits/stdc++.h>
using namespace std;
int query(int x, int y) {
  int t;
  cout << '?' << ' ' << x << ' ' << y << endl, cout.flush();
  cin >> t;
  return t;
}
int midx, midy;
int main() {
  int k = query(1, 1);
  midx = (k - query(1e9, 1) + 1e9 + 1) / 2,
  midy = (k - query(1, 1e9) + 1e9 + 1) / 2;
  cout << '!' << ' ' << query(1, midy) + 1 << ' ' << query(midx, 1) + 1 << ' '
       << 1e9 - query(1e9, midy) << ' ' << 1e9 - query(midx, 1e9) << endl,
      cout.flush();
  return 0;
}
