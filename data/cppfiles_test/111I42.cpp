#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
void chkmin(T1 &x, T2 y) {
  if (x > y) x = y;
}
template <typename T1, typename T2>
void chkmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
namespace fastio {
char rbuf[1 << 23], *p1 = rbuf, *p2 = rbuf, wbuf[1 << 23], *p3 = wbuf;
inline char getc() {
  return p1 == p2 &&
                 (p2 = (p1 = rbuf) + fread(rbuf, 1, 1 << 23, stdin), p1 == p2)
             ? -1
             : *p1++;
}
inline void putc(char x) { (*p3++ = x); }
template <typename T>
void read(T &x) {
  x = 0;
  char c = getc();
  T neg = 0;
  while (!isdigit(c)) neg |= !(c ^ '-'), c = getc();
  while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getc();
  if (neg) x = (~x) + 1;
}
template <typename T>
void recursive_print(T x) {
  if (!x) return;
  recursive_print(x / 10);
  putc(x % 10 ^ 48);
}
template <typename T>
void print(T x) {
  if (!x) putc('0');
  if (x < 0) putc('-'), x = -x;
  recursive_print(x);
}
template <typename T>
void print(T x, char c) {
  print(x);
  putc(c);
}
void readstr(char *s) {
  char c = getc();
  while (c <= 32 || c >= 127) c = getc();
  while (c > 32 && c < 127) s[0] = c, s++, c = getc();
  (*s) = 0;
}
void printstr(string s) {
  for (int i = 0; i < s.size(); i++) putc(s[i]);
}
void printstr(char *s) {
  int len = strlen(s);
  for (int i = 0; i < len; i++) putc(s[i]);
}
void print_final() { fwrite(wbuf, 1, p3 - wbuf, stdout); }
}  // namespace fastio
const int MAXN = 2000;
const int MOD = 998244353;
int n, K, a[MAXN + 5], l[MAXN + 5], r[MAXN + 5];
int fac[MAXN + 5], ifac[MAXN + 5];
void init_fac(int n) {
  for (int i = (fac[0] = ifac[0] = ifac[1] = 1) + 1; i <= n; i++)
    ifac[i] = 1ll * ifac[MOD % i] * (MOD - MOD / i) % MOD;
  for (int i = 1; i <= n; i++) {
    fac[i] = 1ll * fac[i - 1] * i % MOD;
    ifac[i] = 1ll * ifac[i - 1] * ifac[i] % MOD;
  }
}
int dp[2][MAXN + 5][MAXN + 5], sum[2][MAXN + 5][MAXN + 5];
int main() {
  scanf("%d%d", &n, &K);
  init_fac(MAXN);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    l[i] = max(a[i] - K, 0);
    r[i] = min(a[i] + K, i);
  }
  int pre = 0, cur = 1;
  dp[pre][0][0] = sum[pre][0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i; j++)
      for (int k = max(l[i] - 1, 0); k <= r[i]; k++)
        dp[cur][j][k] = sum[cur][j][k] = 0;
    for (int j = 0; j <= i; j++)
      for (int k = l[i]; k <= r[i] && k <= j; k++) {
        dp[cur][j][k] = (dp[cur][j][k] + 1ll * j * dp[pre][j][k]) % MOD;
        if (j) {
          dp[cur][j][k] = (dp[cur][j][k] + dp[pre][j - 1][k]) % MOD;
          if (k)
            dp[cur][j][k] =
                (dp[cur][j][k] +
                 1ll * sum[pre][j - 1][min(k - 1, r[i - 1])] * ifac[j - k]) %
                MOD;
        }
        sum[cur][j][k] = 1ll * dp[cur][j][k] * fac[j - k] % MOD;
        if (k) sum[cur][j][k] = (sum[cur][j][k] + sum[cur][j][k - 1]) % MOD;
      }
    swap(pre, cur);
  }
  int res = 0;
  for (int i = 0; i <= n; i++)
    for (int j = l[n]; j <= r[n] && j <= i; j++)
      res = (res + 1ll * dp[pre][i][j] * fac[n - j] % MOD * ifac[n - i]) % MOD;
  printf("%d\n", res);
  return 0;
}
