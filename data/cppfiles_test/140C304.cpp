#include <bits/stdc++.h>
using namespace std;
using vll = vector<long long>;
using vi = vector<long long>;
using vpl = vector<pair<long long, long long>>;
using pll = pair<long long, long long>;
long long mod = 1000000007;
long long mod2 = 998244353;
const long long MX = 2e5 + 5;
long long ipow(long long base, long long k, long long M) {
  base %= M;
  k = k % (M - 1);
  long long total = 1;
  while (k) {
    if (k & 1) {
      total = (total * base) % M;
    }
    base = (base * base) % M;
    k >>= 1;
  }
  return total;
}
long long precomp[100];
long long modu(long long a, long long b) {
  long long c = a % b;
  return (c < 0) ? c + b : c;
}
void solve() {
  long long v, e, a, b;
  long long n, bal;
  long long count = 0, x, y;
  cin >> n;
  a = floor(sqrt(n));
  b = floor(cbrt(n));
  long long ans = a + b;
  for (long long i = 0; i < 101; i++) {
    if (n < precomp[i]) {
      ans -= i;
      break;
    }
  }
  cout << ans << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long tc = 1;
  long long cnt = 1;
  cin >> tc;
  for (long long i = 1; i < 101; i++) {
    precomp[i - 1] = ipow(i, 6, 1000000000000000000);
  }
  while (tc--) {
    solve();
  }
}
