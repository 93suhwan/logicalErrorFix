#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b != 0) {
    if (b & 1) res *= a, res %= 1000000007;
    a *= a, a %= 1000000007;
    b >>= 1;
  }
  return res % 1000000007;
}
void fastio() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void solve() {
  long long a, b, c;
  cin >> a >> b >> c;
  long long x = a + 2 * b + 3 * c;
  if (x % 2 == 0)
    cout << 0 << "\n";
  else
    cout << 1 << "\n";
}
signed main() {
  fastio();
  long long t;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
}
