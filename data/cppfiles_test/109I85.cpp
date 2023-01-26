#include <bits/stdc++.h>
using namespace std;
long long w[2], b[2], q[2], mod = 998244353, fac[100001];
long long modpow(long long b, long long p) {
  long long ret = 1;
  while (p > 0) {
    if (p & 1) ret = ret * b % mod;
    b = b * b % mod;
    p >>= 1;
  }
  return ret;
}
long long choose(long long n, long long m) {
  long long denom = modpow(fac[m], mod - 2) * modpow(fac[n - m], mod - 2) % mod;
  return (fac[n] * denom % mod);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, qq = 0;
  bool bw = true, wb = true, both = true;
  string s;
  fac[0] = 1;
  for (int i = 1; i < 100001; i++) fac[i] = fac[i - 1] * i % mod;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < 2; j++) {
      if (s[j] == 'W') w[j]++;
      if (s[j] == 'B') b[j]++;
      if (s[j] == '?') q[j]++;
    }
    if (s == "??") qq++;
    if (s == "WW" || s == "BB") bw = wb = both = false;
    if (s == "W?" || s == "?B") bw = false;
    if (s == "B?" || s == "?W") wb = false;
  }
  if (n == 1) {
    if (s == "WW" | s == "BB") cout << 0;
    if (s == "WB" | s == "BW") cout << 1;
    if (s == "??")
      cout << 2;
    else
      cout << 1;
    return 0;
  }
  long long ans = 0;
  for (int i = 0; i < q[0] + 1; i++) {
    if (w[0] + i < b[1] || w[0] + i > b[1] + q[1]) continue;
    ans = (ans + choose(q[0], i) * choose(q[1], w[0] + i - b[1])) % mod;
  }
  if (both) {
    ans -= modpow(2, qq);
    if (bw) ans++;
    if (wb) ans++;
  }
  ans = ((ans % mod) + mod) % mod;
  cout << ans;
}
