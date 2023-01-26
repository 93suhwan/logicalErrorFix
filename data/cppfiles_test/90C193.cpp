#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long x, y;
    cin >> x >> y;
    long long n;
    if (x <= y) {
      long long z = y / x * x;
      n = z + y >> 1;
    } else
      n = x + y;
    cout << n << '\n';
  }
  return 0;
}
