#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long inf = 0x3f3f3f3f;
long long fpow(long long x, long long y) {
  if (x == 0) return 0;
  if (y == 0) return 1;
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = res * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return res;
}
long long fac[300005];
long long C(long long x, long long y) {
  return fac[y] * fpow(fac[y - x], mod - 2) % mod * fpow(fac[x], mod - 2) % mod;
}
long long cnt[4];
long long f1(long long x) { return x * (x - 1) * (x - 2) / 6; }
long long f2(long long x) { return x * (x - 1) / 2; }
void solve() {
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    long long x, y;
    cin >> x >> y;
    cnt[((x / 2) % 2) * 2 + (y / 2) % 2]++;
  }
  long long ans = 0;
  for (long long i = 0; i <= 3; i++) ans += f1(cnt[i]);
  for (long long i = 0; i <= 3; i++)
    for (long long j = i + 1; j <= 3; j++) {
      ans += f2(cnt[i]) * cnt[j] + f2(cnt[j]) * cnt[i];
    }
  cout << ans << endl;
}
signed main() {
  long long _ = 1;
  while (_--) solve();
  return 0;
}
