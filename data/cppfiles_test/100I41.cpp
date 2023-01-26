#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long f[N], mod = 998244353;
long long power(long long x, long long y) {
  long long sum = 1;
  while (y) {
    if (y & 1) sum = sum * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return sum;
}
long long inverse(long long x) { return power(x, mod - 2); }
long long c(int x, int y) {
  return (f[x] % mod * inverse(((f[y] % mod) * (f[x - y] % mod)) % mod)) % mod;
}
void fac() {
  f[0] = 1;
  for (long long i = 1; i < N; ++i) {
    f[i] = f[i - 1] * i;
    f[i] %= mod;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  fac();
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    if (a[n - 1] - a[n - 2] > 1) {
      cout << 0 << '\n';
      continue;
    } else if (a[n - 1] - a[n - 2] == 0) {
      cout << f[n] << '\n';
      continue;
    }
    long long cnt = 0;
    for (int i = n - 2; i >= 0; --i) {
      if (a[i] != a[n - 2]) break;
      ++cnt;
    }
    long long ans = f[n] - f[n - 1];
    for (int i = n - 2; i >= cnt; --i) {
      long long x = c(n - cnt - 1, n - i - 1) * f[n - i - 1];
      x %= mod;
      ans -= ((f[i] * (x)) % mod);
      ans += mod;
      ans %= mod;
    }
    cout << ans << '\n';
  }
  return 0;
}
