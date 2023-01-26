#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long mod = 1e9 + 7;
inline long long read() {
  bool f = true;
  long long x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = false;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
  if (f) return x;
  return ~(--x);
}
inline void write(const long long &x) {
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline void print(const long long &x) {
  x < 0 ? putchar('-'), write(~(x - 1)) : write(x);
  putchar('\n');
}
inline long long max(const long long &a, const long long &b) {
  return a > b ? a : b;
}
inline long long min(const long long &a, const long long &b) {
  return a < b ? a : b;
}
const int MAXN = 2e5 + 7;
int n, q;
long long s1[MAXN], s2[MAXN];
inline long long add(long long x, long long y) {
  return (x += y) < mod ? x : x - mod;
}
inline long long dec(long long x, long long y) {
  return (x -= y) < 0 ? x + mod : x;
}
long long ksm(long long d, long long t) {
  long long res = 1;
  for (; t; t >>= 1, d = d * d % mod)
    if (t & 1) res = res * d % mod;
  return res;
}
int main() {
  n = read(), q = read();
  for (int i = 1; i <= n; ++i) {
    long long x = read();
    s1[i] = (s1[i - 1] + x) % MOD;
    s2[i] = (s2[i - 1] + x * x) % MOD;
  }
  for (int i = 1; i <= q; ++i) {
    long long l = read(), r = read(), d = read(), sum1 = dec(s1[r], s1[l - 1]),
              sum2 = dec(s2[r], s2[l - 1]), sz = (r - l + 1);
    long long mi = dec(2 * sum1 * ksm(sz, mod - 2) % mod, d * (sz - 1) % mod) *
                   ksm(2, mod - 2) % mod;
    long long tmp2 = sz * mi % mod * mi % mod;
    tmp2 = add(tmp2, d * d % mod * (sz - 1) % mod * sz % mod * (2 * sz - 1) %
                         mod * ksm(6, mod - 2) % mod) %
           mod;
    tmp2 = add(tmp2, mi * d % mod * sz % mod * (sz - 1) % mod) % mod;
    if (tmp2 == sum2) {
      puts("Yes");
      continue;
    }
    mi = mod - mi;
    tmp2 = sz * mi % mod * mi % mod;
    tmp2 = add(tmp2, d * d % mod * (sz - 1) % mod * sz % mod * (2 * sz - 1) %
                         mod * ksm(6, mod - 2) % mod) %
           mod;
    tmp2 = add(tmp2, mi * d % mod * sz % mod * (sz - 1) % mod) % mod;
    if (tmp2 == sum2) {
      puts("Yes");
      continue;
    }
    puts("No");
  }
}
