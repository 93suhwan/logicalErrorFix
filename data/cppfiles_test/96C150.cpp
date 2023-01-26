#include <bits/stdc++.h>
namespace FastIO {
char buf[(1 << 20)], pbuf[(1 << 20)];
char *p1 = buf, *p2 = buf, *p3 = pbuf;
char gc() {
  if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, (1 << 20), stdin);
  return p1 == p2 ? EOF : *p1++;
}
inline bool isblank(char c) {
  return c == ' ' || c == '\r' || c == '\n' || c == '\t';
}
template <class T>
inline bool read(T &x) {
  double temp = 1;
  bool sign = false;
  x = 0;
  char c = gc();
  if (c == EOF) return false;
  for (; !isdigit(c); c = gc())
    if (c == '-') sign = true;
  for (; isdigit(c); c = gc()) x = (x << 3) + (x << 1) + (c ^ 48);
  if (c == '.')
    for (c = gc(); isdigit(c); c = gc()) temp /= 10, x += temp * (c ^ 48);
  if (sign) x = -x;
  return true;
}
template <class T, class... S>
inline bool read(T &a, S &...b) {
  return read(a) && read(b...);
}
inline void flush() { fwrite(pbuf, 1, p3 - pbuf, stdout); }
inline void push(const char &c) {
  if (p3 - pbuf == (1 << 20)) fwrite(pbuf, 1, (1 << 20), stdout), p3 = pbuf;
  *p3++ = c;
}
template <class T>
inline void write(T x) {
  if (x < 0) x = -x, push('-');
  static T stk[35];
  T top = 0;
  do {
    stk[++top] = x % 10, x /= 10;
  } while (x);
  while (top) push(stk[top--] ^ 48);
}
template <class T>
inline void write(T x, char pushchar) {
  write(x), push(pushchar);
}
}  // namespace FastIO
using namespace FastIO;
const long long N = 510, p = 998244353;
long long f[N][N];
long long dp[N][N];
void init(long long n) {
  for (long long i = 0; i <= n; ++i)
    for (long long j = 0; j <= i; ++j) {
      if (j == 0)
        f[i][j] = 1;
      else
        f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % p;
    }
}
long long qmi(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % p;
    a = (a * a) % p;
    b >>= 1;
  }
  return res;
}
int32_t main() {
  long long n, x;
  std::cin >> n >> x;
  init(n);
  for (long long i = 2; i <= n; ++i)
    for (long long j = 1; j <= x; ++j) {
      if (i - 1 >= j)
        dp[i][j] = qmi(j, i);
      else {
        for (long long k = 2; k <= i; ++k)
          (dp[i][j] += dp[k][j - i + 1] * qmi(i - 1, i - k) % p * f[i][k]) %= p;
        (dp[i][j] += qmi(i - 1, i)) %= p;
      }
    }
  std::cout << dp[n][x] << std::endl;
  flush();
  return 0;
}
