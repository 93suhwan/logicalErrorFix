#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long test;
  cin >> test;
  while (test--) {
    long long a, b, c, m;
    cin >> a >> b >> c >> m;
    if ((a - 1) > b + c + m || (b - 1) > m + c + a || (c - 1) > a + m + b) {
      cout << "NO\n";
      continue;
    } else if (a + b + c - 3 >= m) {
      cout << "YES\n";
    } else
      cout << "NO\n";
  }
}
