#include <bits/stdc++.h>
using namespace std;
const long long mod[3] = {1189573241, 3845887537, 3978682033};
const long long maxn = 5 * 1e5 + 13;
const long long K = 3;
long long n, m;
string s, sx;
using hs = array<long long, K>;
hs sum[maxn + 1], pw[maxn + 1];
inline long long add(long long x, long long y, long long mod) {
  x += y;
  if (x >= mod) x -= mod;
  if (x < 0) x += mod;
  return x;
}
inline long long mul(long long x, long long y, long long mod) {
  return x * 1ull * y % mod;
}
hs get1(const long long &x) {
  hs c;
  for (long long i = 0; i < K; ++i) c[i] = x;
  return c;
}
hs operator+(const hs &a, const hs &b) {
  hs c;
  for (long long i = 0; i < K; ++i) c[i] = add(a[i], b[i], mod[i]);
  return c;
}
hs operator-(const hs &a, const hs &b) {
  hs c;
  for (long long i = 0; i < K; ++i) c[i] = add(a[i], -b[i], mod[i]);
  return c;
}
hs operator*(const hs &a, const hs &b) {
  hs c;
  for (long long i = 0; i < K; ++i) c[i] = mul(a[i], b[i], mod[i]);
  return c;
}
hs get2(long long l, long long r) { return sum[r] - sum[l] * pw[r - l]; }
vector<long long> zfunction(const string &s) {
  long long n = s.size();
  vector<long long> z(n, 0);
  long long l = 0, r = 0;
  for (long long i = 1; i < n; ++i) {
    if (i <= r) z[i] = min(z[i - l], r - i + 1);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
  return z;
}
int32_t main() {
  cin >> s >> sx;
  n = s.size();
  m = sx.size();
  pw[0] = get1(1);
  for (long long i = 0; i < maxn - 1; ++i) {
    pw[i + 1] = pw[i] * get1(10);
  }
  sum[0] = get1(0);
  for (long long i = 0; i < n; ++i)
    sum[i + 1] = sum[i] * get1(10) + get1(s[i] - '0');
  hs x = get1(0);
  for (long long i = 0; i < m; ++i) x = x * get1(10) + get1(sx[i] - '0');
  if (m > 1)
    for (long long i = 0; i + 2 * (m - 1) <= n; ++i) {
      if (get2(i, i + m - 1) + get2(i + m - 1, i + 2 * (m - 1)) == x) {
        cout << i + 1 << ' ' << i + m - 1 << '\n';
        cout << i + m << ' ' << i + 2 * (m - 1) << '\n';
        return 0;
      }
    }
  auto z = zfunction(sx + "#" + s);
  for (long long i = 0; i + m <= n; ++i) {
    long long lcp = z[m + i + 1];
    for (long long len = m - lcp - 1; len <= m - lcp; ++len) {
      if (len < 1) continue;
      if (i + m + len <= n && get2(i, i + m) + get2(i + m, i + m + len) == x) {
        cout << i + 1 << ' ' << i + m << '\n';
        cout << i + m + 1 << ' ' << i + m + len << '\n';
        return 0;
      }
      if (i >= len && get2(i - len, i) + get2(i, i + m) == x) {
        cout << i - len + 1 << ' ' << i << '\n';
        cout << i + 1 << ' ' << i + m << '\n';
        return 0;
      }
    }
  }
  assert(false);
  return 0;
}
