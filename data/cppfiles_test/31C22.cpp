#include <bits/stdc++.h>
template <typename T>
bool ckmax(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <typename T>
bool ckmin(T &x, T y) {
  return x > y ? x = y, true : false;
}
using namespace std;
const long long inf = 1000000000;
const double Pi = acos(-1);
const long long mod = 998244353;
const double eps = 1e-6;
inline long long fpow(long long a, long long b = mod - 2, long long p = mod) {
  a %= p;
  long long res = 1;
  while (b) {
    if (b & 1) res = 1ll * res * a % p;
    a = 1ll * a * a % p;
    b >>= 1;
  }
  return res;
}
inline long long read() {
  char c = getchar();
  long long x = 0;
  bool f = 0;
  for (; !isdigit(c); c = getchar()) f ^= !(c ^ 45);
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  if (f) x = -x;
  return x;
}
inline void write(long long x) {
  if (x < 0) {
    putchar('-');
    write(-x);
    return;
  }
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writesp(long long x) { write(x), putchar(' '); }
inline void writeln(long long x) {
  write(x);
  putchar('\n');
}
long long k, n;
long long ans[2222222], mn[2][2222222], mx[2][2222222];
signed main() {
  n = read(), k = read();
  for (long long i = (0), iE = ((1 << k) + 5); i <= iE; i++)
    mn[1][i] = ans[i] = inf, mx[1][i] = -inf;
  for (long long i = (1), iE = (n); i <= iE; i++) {
    static long long x;
    x = read();
    mn[1][x] = mx[1][x] = 0;
  }
  for (long long i = (0), iE = (k - 1); i <= iE; i++)
    for (long long j = (0), jE = ((1 << k) - 1); j <= jE; j++)
      if (j & (1 << i)) {
        long long k = j ^ (1 << i);
        ans[j] = ans[k] = min(ans[j], ans[k]);
        ckmin(ans[j], mn[(i + 1) & 1][k] - mx[(i + 1) & 1][j] + (1ll << i));
        ckmin(ans[k], mn[(i + 1) & 1][j] - mx[(i + 1) & 1][k] + (1ll << i));
        mn[i & 1][j] = min(mn[(i + 1) & 1][j], mn[(i + 1) & 1][k] + (1ll << i));
        mn[i & 1][k] = min(mn[(i + 1) & 1][k], mn[(i + 1) & 1][j] + (1ll << i));
        mx[i & 1][j] = max(mx[(i + 1) & 1][j], mx[(i + 1) & 1][k] + (1ll << i));
        mx[i & 1][k] = max(mx[(i + 1) & 1][k], mx[(i + 1) & 1][j] + (1ll << i));
      }
  for (long long i = (0), iE = ((1 << k) - 1); i <= iE; i++) writesp(ans[i]);
}
