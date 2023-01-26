#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long qpow(long long p, long long k) {
  long long b = p, ans = 1;
  while (k) {
    if (k & 1) {
      ans *= b;
      ans %= mod;
    }
    b *= b;
    b %= mod;
    k >>= 1;
  }
  return ans;
}
long long fact[100005];
long long inv(long long u) { return qpow(u, mod - 2); }
long long c(long long p, long long k) {
  if (k > p or k < 0) return 0;
  return fact[p] * inv(fact[k]) % mod * inv(fact[p - k]) % mod;
}
long long cnta0, cnta1, cntb0, e0, e1, cntb1, ans;
string s[100005];
signed main() {
  long long n;
  cin >> n;
  fact[0] = 1;
  for (long long i = 1; i <= n; i++) {
    fact[i] = fact[i - 1] * i;
    fact[i] %= mod;
  }
  for (long long i = 1; i <= n; i++) {
    cin >> s[i];
    if (s[i][0] == '?') e0++;
    if (s[i][0] == 'W') cnta0++;
    if (s[i][0] == 'B') cnta1++;
    if (s[i][1] == '?') e1++;
    if (s[i][1] == 'W') cntb0++;
    if (s[i][1] == 'B') cntb1++;
  }
  for (long long i = cnta0; i + cnta1 <= n; i++) {
    ans += c(e0, i - cnta0) * c(e1, i - cntb1);
    ans %= mod;
  }
  long long sub = 1;
  for (long long i = 1; i <= n; i++) {
    if (s[i][0] == s[i][1]) {
      if (s[i][0] == '?') {
        sub *= 2;
        sub %= mod;
      } else
        sub = 0;
    }
  }
  long long ra = 1, rb = 1;
  for (long long i = 1; i <= n; i++) {
    if (s[i][0] == 'B' or s[i][1] == 'W') {
      ra = 0;
    }
    if (s[i][1] == 'B' or s[i][0] == 'W') {
      rb = 0;
    }
  }
  cout << (ans + mod - sub + ra + rb) % mod << endl;
}
