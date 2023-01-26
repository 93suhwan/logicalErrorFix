#include <bits/stdc++.h>
using namespace std;
inline int read_int() {
  int t = 0;
  bool sign = false;
  char c = getchar();
  while (!isdigit(c)) {
    sign |= c == '-';
    c = getchar();
  }
  while (isdigit(c)) {
    t = (t << 1) + (t << 3) + (c & 15);
    c = getchar();
  }
  return sign ? -t : t;
}
inline long long read_LL() {
  long long t = 0;
  bool sign = false;
  char c = getchar();
  while (!isdigit(c)) {
    sign |= c == '-';
    c = getchar();
  }
  while (isdigit(c)) {
    t = (t << 1) + (t << 3) + (c & 15);
    c = getchar();
  }
  return sign ? -t : t;
}
inline char get_char() {
  char c = getchar();
  while (c == ' ' || c == '\n' || c == '\r') c = getchar();
  return c;
}
inline void write(long long x) {
  register char c[21], len = 0;
  if (!x) return putchar('0'), void();
  if (x < 0) x = -x, putchar('-');
  while (x) c[++len] = x % 10, x /= 10;
  while (len) putchar(c[len--] + 48);
}
inline void space(long long x) { write(x), putchar(' '); }
inline void enter(long long x) { write(x), putchar('\n'); }
const int MAXN = 15, MAXB = 8, mod = 1e9 + 7;
int quick_pow(int n, int k) {
  int ans = 1;
  while (k) {
    if (k & 1) ans = 1LL * ans * n % mod;
    n = 1LL * n * n % mod;
    k >>= 1;
  }
  return ans;
}
int f[1 << MAXN], a[MAXN], p[MAXN][MAXN], g[4][1 << MAXB][1 << MAXB];
void cal(int p1, int n1, int p2, int n2, int g[1 << MAXB][1 << MAXB]) {
  static int temp[MAXB][1 << MAXB];
  int s1 = 1 << n1, s2 = 1 << n2;
  for (int i = (0); i < (n1); ++i) {
    for (int j = (0); j < (s2); ++j) {
      temp[i][j] = 1;
      for (int k = (0); k < (n2); ++k) {
        if (j & (1 << k))
          temp[i][j] = 1LL * temp[i][j] * p[i + p1][k + p2] % mod;
      }
    }
  }
  for (int i = (0); i < (s1); ++i)
    for (int j = (0); j < (s2); ++j) {
      g[i][j] = 1;
      for (int k = (0); k < (n1); ++k) {
        if (i & (1 << k)) g[i][j] = 1LL * g[i][j] * temp[k][j] % mod;
      }
    }
}
int cal2(int i, int j, int m) {
  int mk = (1 << m) - 1;
  long long t = 1LL * g[0][i & mk][j & mk] * g[1][i & mk][j >> m] % mod;
  t = t * g[2][i >> m][j & mk] % mod * g[3][i >> m][j >> m] % mod;
  return t;
}
int cal3(int i) {
  int ans = 0;
  while (i) {
    ans += i & 1;
    i >>= 1;
  }
  return ans;
}
int main() {
  int n = read_int();
  if (n == 1) {
    puts("1");
    return 0;
  }
  for (int i = (0); i < (n); ++i) a[i] = read_int();
  for (int i = (0); i < (n); ++i) {
    for (int j = (0); j < (n); ++j)
      p[i][j] = 1LL * a[i] * quick_pow(a[i] + a[j], mod - 2) % mod;
  }
  int m = n / 2;
  cal(0, m, 0, m, g[0]);
  cal(0, m, m, n - m, g[1]);
  cal(m, n - m, 0, m, g[2]);
  cal(m, n - m, m, n - m, g[3]);
  int S = (1 << n) - 1, ans = 0;
  for (int i = (1); i <= (S); ++i) {
    f[i] = 1;
    for (int j = (i - 1) & i; j != i; j = (j - 1) & i)
      f[i] = (f[i] - 1LL * f[j] * cal2(j, i ^ j, m)) % mod;
    ans = (ans + 1LL * f[i] * cal2(i, i ^ S, m) % mod * cal3(i)) % mod;
  }
  enter((ans + mod) % mod);
  return 0;
}
