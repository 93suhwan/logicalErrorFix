#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2005;
const int MOD = 1e9 + 7;
inline void ADD(int& x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}
inline void DEC(int& x, int y) {
  x -= y;
  if (x < 0) x += MOD;
}
inline int add(int x, int y) { return x + y < MOD ? x + y : x + y - MOD; }
inline int dec(int x, int y) { return x < y ? x - y + MOD : x - y; }
long long q_pow(long long a, long long b, long long p = MOD) {
  long long ret = 1;
  for (; b; a = a * a % p, b >>= 1)
    if (b & 1) ret = ret * a % p;
  return ret;
}
long long q_inv(long long x, long long p = MOD) { return q_pow(x, p - 2, p); }
int fac[MAXN], ifac[MAXN];
void build(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = 1ll * fac[i - 1] * i % MOD;
  ifac[n] = q_inv(fac[n]);
  for (int i = n - 1; i >= 0; --i) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % MOD;
}
template <typename T>
void chkmax(T& x, T y) {
  if (y > x) x = y;
}
template <typename T>
void chkmin(T& x, T y) {
  if (y < x) x = y;
}
int Data, N, C[MAXN][MAXN];
char S[MAXN], T[MAXN];
int s1[MAXN], s2[MAXN], t1[MAXN], t2[MAXN];
int binom(int n, int m) { return m < 0 || m > n ? 0 : C[n][m]; }
int main() {
  C[0][0] = 1;
  for (int i = 1; i <= 2000; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++j) C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
  }
  scanf("%d", &Data);
  while (Data--) {
    scanf("%d%s%s", &N, S + 1, T + 1);
    for (int i = 2; i <= N; i += 2) {
      if (S[i] != '?') S[i] = '0' + '1' - S[i];
      if (T[i] != '?') T[i] = '0' + '1' - T[i];
    }
    for (int i = 1; i <= N; ++i) {
      s1[i] = s1[i - 1], s2[i] = s2[i - 1], t1[i] = t1[i - 1],
      t2[i] = t2[i - 1];
      if (S[i] == '1')
        ++s1[i];
      else if (S[i] == '?')
        ++s2[i];
      if (T[i] == '1')
        ++t1[i];
      else if (T[i] == '?')
        ++t2[i];
    }
    int ans = 0;
    for (int i = 1; i <= N; ++i)
      for (int j = 1; j <= N; ++j)
        if (S[i] != '0' && T[j] != '0') {
          int a1 = s1[i - 1], a2 = s2[i - 1], b1 = t1[j - 1], b2 = t2[j - 1];
          int tmp = binom(a2 + b2, b2 - a1 + b1);
          a1 = s1[N] - s1[i], a2 = s2[N] - s2[i], b1 = t1[N] - t1[j],
          b2 = t2[N] - t2[j];
          tmp = 1ull * tmp * binom(a2 + b2, b2 - a1 + b1);
          ADD(ans, 1ull * abs(i - j) * tmp % MOD);
        }
    printf("%d\n", ans);
  }
  return 0;
}
