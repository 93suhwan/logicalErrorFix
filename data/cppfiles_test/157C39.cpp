#include <bits/stdc++.h>
using namespace std;
const long long inf = 1000000000000000000;
const long long mod = 998244353;
long long fact[1000005], n, k, pr, cnt, na, a[5005], ans;
string s;
long long bin_pow(long long x, long long step) {
  if (step == 0) return 1;
  if (step == 1) return x;
  if (step % 2 == 0) {
    long long p = bin_pow(x, step / 2);
    return ((p * p) % mod);
  }
  return ((x * bin_pow(x, step - 1)) % mod);
}
long long inv(long long x) { return bin_pow(x, mod - 2); }
long long c(long long n, long long k) {
  return ((((fact[n] * inv(fact[n - k])) % mod) * inv(fact[k])) % mod);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  fact[0] = fact[1] = 1;
  for (long long i = 2; i <= 1000000; ++i) fact[i] = (fact[i - 1] * i) % mod;
  cin >> n >> k;
  cin >> s;
  s = '$' + s;
  pr = cnt = 0;
  for (long long i = 1; i <= n; ++i) {
    if (s[i] == '1') a[++na] = i;
  }
  if (k > na || k == 0) {
    cout << 1;
    return 0;
  }
  if (k == na) {
    cout << c(n, k);
    return 0;
  }
  a[0] = 0;
  a[++na] = n + 1;
  for (long long i = k + 1; i <= na; ++i) {
    ans += c(a[i] - a[i - k - 1] - 1, k);
    ans %= mod;
    if (i > k + 1) {
      ans -= c(a[i - 1] - a[i - k - 1] - 1, k - 1);
      ans += mod;
      ans %= mod;
    }
  }
  cout << ans;
  return 0;
}
