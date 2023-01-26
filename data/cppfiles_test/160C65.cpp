#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5, mod = 1e9 + 7;
const long long ll_lim = 1e18 + 7;
const long long int_lim = 1e9 + 7;
int tc, n, m, z, t, x, y;
bool maximize(long long& x, long long y) {
  if (x < y) {
    x = y;
    return 1;
  }
  return 0;
}
bool minimize(long long& x, long long y) {
  if (x > y) {
    x = y;
    return 1;
  }
  return 0;
}
long long spow(long long x, long long mu) {
  if (mu == 0) return (1);
  if (mu == 1) return (x);
  long long k = spow(x, mu / 2);
  if (mu % 2 == 1)
    return ((((k * k) % mod) * x) % mod);
  else
    return ((k * k) % mod);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> tc;
  while (tc--) {
    cin >> n >> m >> x >> y >> z >> t;
    int dx = 1, dy = 1;
    int c = 0;
    while (x != z && y != t) {
      if (dx + x > n || dx + x < 0) dx = -dx;
      if (dy + y > m || dy + y < 0) dy = -dy;
      x += dx;
      y += dy;
      c++;
    }
    cout << c << "\n";
  }
}
