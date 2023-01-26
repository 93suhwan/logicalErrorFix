#include <bits/stdc++.h>
using namespace std;
long long cnt;
long long mod = 1e9 + 7;
long long INF = 998244353;
long long qpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b % 2 == 1) ans = ans * a % mod;
    a = (a * a) % mod;
    b = b / 2;
  }
  return ans;
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    long long x, y;
    cin >> x >> y;
    if (x == y)
      cout << x << '\n';
    else if (x > y) {
      if (x % y == 0)
        cout << y << '\n';
      else
        cout << x + y << '\n';
    } else if (x < y) {
      if (y % x == 0)
        cout << x << '\n';
      else
        cout << x + y << '\n';
    }
  }
  return 0;
}
