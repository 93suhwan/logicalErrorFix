#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const long long nax = 5000 + 10, mod = 998244353, inf = 1e18;
long long first[nax], invf[nax];
long long mul(long long x, long long y) { return x * y % mod; }
long long expo(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = mul(res, a);
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}
long long inv(long long x) { return expo(x, mod - 2); }
long long nck(long long n, long long r) {
  if (r < 0 or r > n) return 0;
  return mul(first[n], mul(invf[n - r], invf[r]));
}
long long sub(long long x, long long y) {
  x -= y;
  if (x < 0) x += mod;
  return x;
}
long long add(long long x, long long y) {
  x += y;
  if (x >= mod) x -= mod;
  return x;
}
void solve() {
  long long n, res = 1, k;
  cin >> n >> k;
  string second;
  cin >> second;
  vector<long long> a(n), pref(n + 1, 0);
  for (long long i = 0; i < n; i++) a[i] = (second[i] - '0');
  for (long long i = 0; i < n; i++) pref[i + 1] = pref[i] + a[i];
  if (pref[n] >= k) {
    for (long long i = 0; i < n; i++)
      for (long long j = i + 1; j < n; j++) {
        long long ok = pref[j + 1] - pref[i];
        if (ok <= k) {
          ok -= (a[i] ^ 1) + (a[j] ^ 1);
          long long val = j - i - 1;
          res += nck(val, ok);
          res %= mod;
        }
      }
  }
  cout << res;
  cout << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  first[0] = 1;
  for (long long i = 1; i < nax; i++) first[i] = mul(first[i - 1], i);
  invf[nax - 1] = inv(first[nax - 1]);
  for (long long i = nax - 1; i; i--) invf[i - 1] = mul(invf[i], i);
  long long tt = 1;
  for (long long i = 1; i <= tt; i++) {
    solve();
  }
  return 0;
}
