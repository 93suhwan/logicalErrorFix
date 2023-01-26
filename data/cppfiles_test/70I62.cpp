#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const double eps = 1e-10;
inline long long Max(long long x, long long y) { return x > y ? x : y; }
inline long long Min(long long x, long long y) { return x < y ? x : y; }
inline double Max(double x, double y) { return x - y > eps ? x : y; }
inline double Min(double x, double y) { return x - y < eps ? x : y; }
inline long long Add(long long x, long long y, long long M = mod) {
  return (x + y) % M;
}
inline long long Mul(long long x, long long y, long long M = mod) {
  return 1ll * x * y % M;
}
inline long long Dec(long long x, long long y, long long M = mod) {
  return (x - y + M) % M;
}
inline long long Abs(long long x) { return x < 0 ? -x : x; }
inline long long read() {
  long long s = 0, w = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    s = s * 10 + ch - '0';
    ch = getchar();
  }
  return s * w;
}
inline void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline long long qpow(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = Mul(res, x);
    x = Mul(x, x);
    y >>= 1;
  }
  return res;
}
const long long N = 2e5 + 10;
long long n, q, a[N];
long long f[N][2], inv2, inv6;
inline long long inv(long long x) { return qpow(x, mod - 2); }
inline long long sum_sq(long long x) {
  return Mul(inv6, Mul(x, Mul(x + 1, Add(1, Mul(2, x)))));
}
inline long long sum_1(long long x) { return Mul(inv2, Mul(x, x + 1)); }
long long calc(long long og, long long d, long long len) {
  long long S2 = 0;
  S2 = Add(S2, Mul(Mul(d, d), sum_sq(len - 1)));
  S2 = Add(S2, Mul(Mul(og, og), len));
  S2 = Add(S2, Mul(Mul(Mul(2, d), og), sum_1(len - 1)));
  return S2;
}
long long calc1(long long og, long long d, long long len) {
  return Add(Mul(og, len), Mul(d, sum_1(len - 1)));
}
signed main() {
  srand(time(0));
  n = read();
  q = read();
  for (long long i = 1; i <= n; ++i) a[i] = read();
  long long v_seed = rand();
  for (long long i = 1; i <= n; ++i) a[i] = Add(a[i], v_seed);
  for (long long i = 1; i <= n; ++i) {
    f[i][0] = Add(f[i - 1][0], a[i]);
    f[i][1] = Add(f[i - 1][1], Mul(a[i], a[i]));
  }
  inv2 = inv(2);
  inv6 = inv(6);
  long long cnt = 0;
  while (q--) {
    ++cnt;
    long long l = read(), r = read(), d = read();
    if (l == r) {
      puts("Yes");
      continue;
    }
    long long len = (r - l + 1);
    long long s1 = f[r][0] - f[l - 1][0];
    long long s2 = f[r][1] - f[l - 1][1];
    long long og = Mul(sum_1(len - 1), d);
    og = Dec(s1, og);
    og = Mul(og, inv(len));
    long long S1 = calc1(og, d, len);
    if (S1 != s1) {
      puts("No");
      continue;
    }
    long long S2 = calc(og, d, len);
    if (S2 != s2) {
      puts("No");
    } else
      puts("Yes");
  }
  return 0;
}
