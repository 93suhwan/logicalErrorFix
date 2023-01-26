#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
inline long long fastpow(long long a, long long n) {
  long long ans = 1;
  while (n) {
    if (n & 1) ans = ans * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return ans;
}
long long p2[1000010];
inline void Init2(long long n) {
  p2[0] = 1;
  for (long long i = 1; i <= n; i++) p2[i] = p2[i - 1] * 2 % mod;
}
inline long long inv(long long x) { return fastpow(x, mod - 2); }
map<pair<long long, long long>, long long> mp;
long long r[1000010][2], c[1000010][2], rc[2];
inline long long calcr(long long x) {
  return 2 - (bool(r[x][0]) + bool(r[x][1]));
}
inline long long calcc(long long x) {
  return 2 - (bool(c[x][0]) + bool(c[x][1]));
}
inline long long calcrc() { return 2 - (bool(rc[0]) + bool(rc[1])); }
long long totr[3], totc[3];
signed main() {
  long long n, m, k;
  scanf("%lld %lld %lld", &n, &m, &k);
  Init2(max(n, m));
  totr[0] = totr[1] = 0, totr[2] = n;
  totc[0] = totc[1] = 0, totc[2] = m;
  while (k--) {
    long long x, y, t;
    scanf("%lld %lld %lld", &x, &y, &t);
    long long prer = calcr(x), prec = calcc(y);
    if (mp.find({x, y}) != mp.end() && mp[{x, y}] != -1) {
      long long tmp = mp[{x, y}];
      r[x][(y ^ tmp) & 1]--;
      c[y][(x ^ tmp) & 1]--;
      rc[(x ^ y ^ tmp) & 1]--;
    }
    mp[{x, y}] = t;
    if (t != -1) {
      r[x][(y ^ t) & 1]++;
      c[y][(x ^ t) & 1]++;
      rc[(x ^ y ^ t) & 1]++;
    }
    long long nowr = calcr(x), nowc = calcc(y);
    totr[prer]--, totc[prec]--;
    totr[nowr]++, totc[nowc]++;
    long long ansr = totr[0] ? 0 : p2[totr[2]],
              ansc = totc[0] ? 0 : p2[totc[2]];
    printf("%lld\n", (ansr + ansc - calcrc() + mod) % mod);
  }
  return 0;
}
