#include <bits/stdc++.h>
using namespace std;
long long t, n;
int32_t main() {
  cin >> t;
  while (t--) {
    long long x, y;
    cin >> n;
    long long a = n % 3;
    x = trunc(n / 3);
    y = (a == 0) ? x : x + 1;
    if (x + 2 * y == n)
      cout << x << ' ' << y << '\n';
    else
      cout << y << ' ' << x << '\n';
  }
  return 0;
}
