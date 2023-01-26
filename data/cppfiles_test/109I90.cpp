#include <bits/stdc++.h>
using namespace std;
inline char nc() {
  static char buf[1000000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline void read(long long& sum) {
  char ch = nc();
  sum = 0;
  while (!(ch >= '0' && ch <= '9')) ch = nc();
  while (ch >= '0' && ch <= '9')
    sum = (sum << 3) + (sum << 1) + (ch - 48), ch = nc();
}
const long long maxn = 2e5 + 5;
const long long inf = 0x3f3f3f3f;
const long long INF = 1e18;
const double PI = acos(double(-1));
const long long mod = 998244353;
long long f[maxn];
inline long long qp(long long x, long long q) {
  long long res = 1;
  while (q) {
    if (q & 1) res = res * x % mod;
    x = x * x % mod;
    q >>= 1;
  }
  return res;
}
inline long long inv(long long x) { return qp(x, mod - 2); }
inline long long c(long long n, long long m) {
  return (f[n] * inv(f[n - m]) % mod) * inv(f[m]) % mod;
}
long long n;
char s[100005][2];
bool flag = false;
long long c1 = 0, c2 = 0, c3 = 0;
signed main() {
  f[0] = 1;
  for (long long i = 1; i <= 200000; i++) f[i] = f[i - 1] * i % mod;
  cin >> n;
  for (long long i = 1; i <= n; ++i) {
    cin >> s[i];
    if (s[i][0] == 'W') c1++;
    if (s[i][1] == 'W') c1++;
    if (s[i][0] == 'B') c2++;
    if (s[i][1] == 'B') c2++;
    if (s[i][0] == s[i][1])
      if ((s[i][0] == 'W' || s[i][0] == 'B'))
        flag = 1;
      else
        c3++;
  }
  long long ans = c((n << 1) - c1 - c2, n - c1);
  if (!flag) {
    long long sub = 1;
    for (long long i = 1; i <= c3; ++i) sub = (sub << 1) % mod;
    if (n - c3 == 1) sub -= 1;
    ans -= sub;
  }
  cout << ans;
}
