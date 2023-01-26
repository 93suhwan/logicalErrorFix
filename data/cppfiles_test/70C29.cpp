#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &num) {
  T x = 0, f = 1;
  char ch = getchar();
  for (; ch > '9' || ch < '0'; ch = getchar())
    if (ch == '-') f = -1;
  for (; ch <= '9' && ch >= '0'; ch = getchar())
    x = (x << 3) + (x << 1) + (ch ^ '0');
  num = x * f;
}
const int mod = 1000000007, inv2 = 500000004, inv6 = 166666668;
inline int qmod(int x) { return x < mod ? x : x - mod; }
inline int fpow(int x, int t) {
  int r = 1;
  for (; t; t >>= 1, x = 1ll * x * x % mod)
    if (t & 1) r = 1ll * r * x % mod;
  return r;
}
int n, m, a[200005], sum[200005], s2[200005];
inline int c1(int x) { return 1ll * x * (x + 1) % mod * inv2 % mod; }
inline int c2(int x) {
  return 1ll * x * (x + 1) % mod * (2 * x + 1) % mod * inv6 % mod;
}
int main() {
  read(n);
  read(m);
  for (int i = 1; i <= n; i++)
    read(a[i]), sum[i] = qmod(sum[i - 1] + a[i]),
                s2[i] = qmod(s2[i - 1] + 1ll * a[i] * a[i] % mod);
  for (int i = 1, l, r, d; i <= m; i++) {
    read(l);
    read(r);
    read(d);
    int S = qmod(sum[r] - sum[l - 1] + mod), len = r - l + 1;
    int tmp = 2ll * S * fpow(len, mod - 2) % mod,
        st = 1ll * qmod(tmp - 1ll * (len - 1) * d % mod + mod) * inv2 % mod;
    int hs1 = qmod(s2[r] - s2[l - 1] + mod),
        hs2 = (1ll * st * st % mod * len % mod +
               2ll * st % mod * d % mod * c1(len - 1) % mod +
               1ll * d * d % mod * c2(len - 1) % mod) %
              mod;
    puts(hs1 == hs2 ? "Yes" : "No");
  }
  return 0;
}
