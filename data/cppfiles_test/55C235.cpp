#include <bits/stdc++.h>
using namespace std;
void _debug() { cerr << '\n'; }
template <typename A, typename... B>
void _debug(A a, B... b) {
  cerr << a << ' ', _debug(b...);
}
const int oo = 2000000000;
const int mod = 1e9 + 7;
long long fp(long long a, long long b, const int mod) {
  if (b == 1) return a % mod;
  if (b == 0) return 1;
  if (b & 1) return (fp(a, b - 1, mod) % mod * a % mod) % mod;
  long long val = fp(a, b / 2, mod) % mod;
  return (val % mod * val % mod) % mod;
}
void solve() {
  long long h;
  cin >> h;
  long long sum = 0;
  sum = fp(2, h, mod - 1) - 2;
  cout << 6 * fp(4, sum, mod) % mod << '\n';
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  int t;
  t = 1;
  while (t--) solve();
}
