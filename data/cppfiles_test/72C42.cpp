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
  int t1 = query(1, midy) + 1, t2 = query(midx, 1) + 1,
      t3 = 1e9 - query(1e9, midy), t4 = 1e9 - query(midx, 1e9);
  cout << '!' << ' ' << t1 << ' ' << t2 << ' ' << t3 << ' ' << t4 << endl,
      cout.flush();
  return 0;
}
