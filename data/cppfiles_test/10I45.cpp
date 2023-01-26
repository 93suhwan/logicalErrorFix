#include <bits/stdc++.h>
using namespace std;
long long mpow(long long x, long long y, long long m) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = res * x % m;
    y = y >> 1;
    x = x * x % m;
  }
  return res;
}
void solve() {
  long long n, m, k, r, c;
  cin >> n >> m >> k >> r >> c;
  long long ax, ay, bx, by;
  cin >> ax >> ay >> bx >> by;
  long long p = n * m - r * c;
  p %= 1000000007ll - 1;
  long long ans = mpow(k, p, 1000000007ll);
  cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  for (long long i = (1); i < (t + 1); i++) {
    solve();
    cout << "\n";
  }
}
