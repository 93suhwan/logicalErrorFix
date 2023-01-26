#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
inline long long llread() {
  long long x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
long long fact[110], c[110][110];
long long f[110][110][110];
long long n, m, k, p;
void DP(long long sz, long long cnt, long long dep) {
  if (f[dep][sz][cnt] != -1) return;
  f[dep][sz][cnt] = 0;
  if (!sz) {
    f[dep][sz][cnt] = 1;
    return;
  }
  if ((1 << (m - dep)) < cnt) return;
  if (cnt && m - dep > sz) return;
  if (dep == m) {
    if (cnt != 1)
      f[dep][sz][cnt] = 0;
    else
      f[dep][sz][cnt] = fact[sz];
    return;
  }
  for (long long i = (0); i <= (sz - 1); i++) {
    long long sum = 0;
    for (long long j = (max(0ll, cnt + i + 1 - sz)); j <= (min(cnt, i)); j++) {
      if (f[dep + 1][i][j] && f[dep + 1][sz - i - 1][cnt - j]) {
        DP(i, j, dep + 1);
        DP(sz - i - 1, cnt - j, dep + 1);
        sum = (sum + f[dep + 1][i][j] * f[dep + 1][sz - i - 1][cnt - j]) % p;
      }
    }
    f[dep][sz][cnt] = (f[dep][sz][cnt] + sum * c[sz - 1][i]) % p;
  }
}
signed main() {
  n = llread(), m = llread() - 1, k = llread(), p = llread();
  c[0][0] = fact[0] = 1;
  for (long long i = (1); i <= (n); i++) {
    c[i][0] = c[i][i] = 1;
    for (long long j = (1); j <= (i - 1); j++)
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % p;
  }
  for (long long i = (1); i <= (n); i++) fact[i] = (fact[i - 1] * i) % p;
  memset(f, -1, sizeof(f));
  DP(n, k, 0);
  printf("%lld\n", f[0][n][k]);
  return 0;
}
