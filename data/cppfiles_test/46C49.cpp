#include <bits/stdc++.h>
using namespace std;
mt19937 ran(time(0));
long long mod = 1e9 + 7;
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long Bpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans *= a;
      ans %= mod;
    }
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long ans = 0;
  for (long long i = 0; i < n; i += 2) {
    long long now = 0;
    long long mib = 0;
    for (long long j = i + 1; j < n; j++) {
      long long b = now + a[i] - a[j];
      now += (j % 2 ? -a[j] : a[j]);
      if (b > 0 && b > a[i] || b < 0 && -b > a[j] || j % 2 == 0) {
        mib = min(mib, now);
        continue;
      }
      long long l = a[i], r = a[j];
      if (b > 0)
        l -= b;
      else
        r += b;
      if (l > 0 && r > 0 && l >= -mib) ans += min(l + (mib ? mib + 1 : 0), r);
      mib = min(mib, now);
    }
  }
  cout << ans;
}
