#include <bits/stdc++.h>
using namespace std;
template <typename... Args>
void logger(string vars, Args&&... values) {
  cout << vars << " = ";
  string delim = "";
  (..., (cout << delim << values, delim = ", "));
}
const long long maxn = 1e5 + 10;
long long fact[maxn];
long long mod = 998244353;
long long mul(long long x, long long y) { return (x * y) % mod; }
long long power(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = mul(res, x);
    x = mul(x, x);
    y >>= 1;
  }
  return res;
}
long long modinv(long long x) { return power(x, mod - 2); }
long long ncr(long long n, long long r) {
  return mul(fact[n], modinv(mul(fact[n - r], fact[r])));
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(0);
  long long tt;
  cin >> tt;
  while (tt--) {
    long long n, m, k;
    cin >> n >> m >> k;
    long long sub = ((n * m) / 2) - k;
    if (n & 1) {
      if ((sub & 1) || (sub && m < 4))
        cout << "NO\n";
      else
        cout << "YES\n";
    } else if (m & 1) {
      if ((k & 1) || (k && n < 4))
        cout << "NO\n";
      else
        cout << "YES\n";
    } else {
      if (k & 1)
        cout << "NO\n";
      else
        cout << "YES\n";
    }
  }
  return 0;
}
