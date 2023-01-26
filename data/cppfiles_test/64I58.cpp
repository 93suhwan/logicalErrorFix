#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
const long long mod = 1019260817LL * 998244353, G = 10;
long long Mul(long long x, long long y) {
  long long o = x * y - (long long)((long double)x * y / mod + 0.1) * mod;
  return o < 0 ? o + mod : o;
}
long long qpow(long long x, long long y) {
  long long res = 1;
  for (; y; x = Mul(x, x), y >>= 1)
    if (y & 1) res = Mul(res, x);
  return res;
}
const long long iG = qpow(G, 1019260816LL * 998244352 - 1);
char s[N], r[N];
long long Pw[N], iPw[N], pre[N], vx;
int n, m, mx;
unordered_map<long long, int> mp;
long long get(int l, int r) {
  return Mul(iPw[n - r], (pre[r] - pre[l - 1] + mod) % mod);
}
bool ok = false;
inline int LCP(int x) {
  int len = 0, p = 1;
  while (s[x] == r[p] && x <= n && p <= m) ++x, ++p, ++len;
  return len;
}
template <int N>
struct zfun {
  char s[N];
  int z[N];
  int operator[](int x) { return z[x]; }
  void work(int n) {
    for (int i = (1); i <= (n); ++i) z[i] = 0;
    int p = 1;
    for (int i = (2); i <= (n); ++i) {
      if (z[p] + p >= i) z[i] = min(z[p] + p - i, z[i - p + 1]);
      while (i + z[i] <= n && s[i + z[i]] == s[z[i] + 1]) ++z[i];
      if (i + z[i] > p + z[p]) p = i;
    }
    z[1] = n;
  }
};
zfun<N> z;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> (s + 1) >> (r + 1);
  n = strlen(s + 1);
  m = strlen(r + 1);
  for (int i = (1); i <= (m); ++i) z.s[i] = r[i];
  for (int i = (1); i <= (n); ++i) z.s[i + m] = s[i];
  z.work(n + m);
  Pw[0] = iPw[0] = 1;
  for (int i = (1); i <= (max(n, m)); ++i)
    Pw[i] = Mul(Pw[i - 1], G), iPw[i] = Mul(iPw[i - 1], iG);
  for (int i = (1); i <= (n); ++i)
    pre[i] = (pre[i - 1] + Mul(s[i] - '0', Pw[n - i])) % mod, mp[pre[i]] = i;
  for (int i = (1); i <= (m); ++i) (vx += Mul(r[i] - '0', Pw[m - i])) %= mod;
  for (int i = (1); i <= (n - m + 1); ++i) {
    int lcp = z[i + m], len = m - lcp;
    if (len <= 0) continue;
    if (i + m + len - 1 <= n) {
      if ((get(i, i + m - 1) + get(i + m, i + m + len - 1)) % mod == vx)
        return cout << i << ' ' << i + m - 1 << '\n'
                    << i + m << ' ' << i + m + len - 1 << '\n',
               0;
    }
    if (i > len) {
      if ((get(i, i + m - 1) + get(i - len, i - 1)) % mod == vx)
        return cout << i - len << ' ' << i - 1 << '\n'
                    << i << ' ' << i + m - 1 << '\n',
               0;
    }
    len -= 1;
    if (len <= 0) continue;
    if (i + m + len - 1 <= n) {
      if ((get(i, i + m - 1) + get(i + m, i + m + len - 1)) % mod == vx)
        return cout << i << ' ' << i + m - 1 << '\n'
                    << i + m << ' ' << i + m + len - 1 << '\n',
               0;
    }
    if (i > len) {
      if ((get(i, i + m - 1) + get(i - len, i - 1)) % mod == vx)
        return cout << i - len << ' ' << i - 1 << '\n'
                    << i << ' ' << i + m - 1 << '\n',
               0;
    }
  }
  if (m >= 1)
    for (int i = (1); i <= (n - (m - 1) * 2 + 1); ++i)
      if ((get(i, i + m - 2) + get(i + m - 1, i + m * 2 - 3)) == vx)
        return cout << i << ' ' << i + m - 2 << '\n'
                    << i + m - 1 << ' ' << i + m * 2 - 3 << '\n',
               0;
  return 0;
}
