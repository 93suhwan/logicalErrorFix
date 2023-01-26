#include <bits/stdc++.h>
using namespace std;
const long long xxx = 5e3;
const long long maxn = xxx + 5;
const long long inf = 0x3f3f3f3f3f3f3f3f;
const long long mod = 998244353;
const double pi = acos(-1.0);
inline void updmin(long long& a, long long b) { a > b ? a = b : 0; }
inline void updmax(long long& a, long long b) { a < b ? a = b : 0; }
long long fac[maxn], pos[maxn];
char s[maxn];
long long inv(long long x) {
  x %= mod;
  if (x == 1) {
    return 1;
  }
  return (-mod / x * inv(mod % x) % mod + mod) % mod;
}
long long C(long long n, long long m) {
  return fac[n] * inv(fac[m] * fac[n - m] % mod) % mod;
}
int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int cases;
  cases = 1;
  for (int cas = 1; cas <= cases; cas++) {
    long long n, k;
    cin >> n >> k;
    cin >> (s + 1);
    pos[0] = 0;
    long long cnt1 = 0;
    fac[0] = 1;
    for (long long i = 1; i <= n; i++) {
      if (s[i] == '1') {
        pos[++cnt1] = i;
      }
      fac[i] = fac[i - 1] * i % mod;
    }
    pos[cnt1 + 1] = n + 1;
    if (k == 0 || k > cnt1) {
      cout << 1 << "\n";
      continue;
    }
    long long ans = 0;
    for (long long i = k; i <= cnt1; i++) {
      if (i == k) {
        ans += C(pos[i + 1] - pos[i - k] - 1, k);
      } else {
        ans += (C(pos[i + 1] - pos[i - k] - 1, k) -
                C(pos[i] - pos[i - k] - 1, k - 1) + mod) %
               mod;
      }
      ans %= mod;
    }
    cout << ans << "\n";
  }
  return 0;
}
