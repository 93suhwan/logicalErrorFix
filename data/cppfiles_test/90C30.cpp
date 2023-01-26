#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tt;
  cin >> tt;
  for (int cs = 1; cs <= tt; cs++) {
    long long n, m, i, j, k, l, x, y;
    cin >> x >> y;
    if (y % x == 0)
      cout << x << '\n';
    else if (y >= x) {
      m = y - (y % x);
      cout << (m + y) / 2 << '\n';
    } else
      cout << x + y << endl;
  }
  return 0;
}
