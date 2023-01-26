#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5;
const long long M = 1e5;
const long long mod = 1e9 + 7;
const long long inf = 1e18;
long long read() {
  long long x = 0, y = 0;
  char ch = getchar();
  for (; ch < '0' || ch > '9'; y |= (ch == '-'), ch = getchar())
    ;
  for (; ch >= '0' && ch <= '9'; x = x * 10 + ch - '0', ch = getchar())
    ;
  return x * (y ? -1 : 1);
}
long long a, b, s[N + 5], p1[N + 5], p2[N + 5];
bool ans[N + 5];
struct ask {
  long long l, r, d, id;
  bool operator<(const ask &o) const { return r < o.r; }
} q[N + 5];
map<long long, long long> mp;
long long qpow(long long n, long long m = mod - 2) {
  long long res = 1;
  for (; m; m >>= 1) {
    if (m & 1) res = res * n % mod;
    n = n * n % mod;
  }
  return res;
}
const long long inv2 = (mod + 1) / 2, inv6 = (mod + 1) / 6;
long long c1(long long n) { return (1 + n) * n % mod * inv2 % mod; }
long long c2(long long n) {
  return n * (n + 1) % mod * (2 * n + 1) % mod * inv6 % mod;
}
signed main() {
  a = read();
  b = read();
  for (long long i = 1; i <= a; ++i)
    s[i] = read(), p1[i] = (p1[i - 1] + s[i]) % mod,
    p2[i] = (s[i] * s[i] % mod + p2[i - 1]) % mod;
  for (long long i = 1; i <= b; ++i) {
    q[i].l = read();
    q[i].r = read();
    q[i].d = read();
    q[i].id = i;
  }
  sort(q + 1, q + b + 1);
  long long R = 1;
  for (long long i = 1; i <= a; ++i) {
    mp[s[i]] = i;
    for (; R <= b && q[R].r == i; ++R) {
      long long l = q[R].l, r = q[R].r, d = q[R].d, len = r - l + 1;
      long long a0 = ((p1[r] - p1[l - 1] + mod) % mod * qpow(len) % mod * 2 -
                      d * (len - 1) % mod + mod) *
                     inv2 % mod;
      if (!mp.count(a0) || mp[a0] < l) continue;
      long long t1 = (p2[r] - p2[l - 1] + mod) % mod,
                t2 = (len * a0 % mod * a0 % mod +
                      c1(len - 1) * 2 * a0 % mod * d % mod +
                      d * d % mod * c2(len - 1) % mod) %
                     mod;
      ans[q[R].id] = (t1 == t2);
    }
  }
  for (long long i = 1; i <= b; ++i) puts(ans[i] ? "Yes" : "No");
  return 0;
}
