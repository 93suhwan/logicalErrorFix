#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &t) {
  t = 0;
  char ch = getchar();
  int f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  do {
    (t *= 10) += ch - '0';
    ch = getchar();
  } while ('0' <= ch && ch <= '9');
  t *= f;
}
template <class T>
inline void chkmin(T &x, T y) {
  x = min(x, y);
}
template <class T>
inline void chkmax(T &x, T y) {
  x = max(x, y);
}
const int p = 1e9 + 7;
const int inv2 = ((p + 1) >> 1);
inline int inc(int x, int y) {
  if ((x += y) >= p) x -= p;
  return x;
}
inline int dec(int x, int y) {
  if ((x -= y) < 0) x += p;
  return x;
}
inline void Inc(int &x, int y) { x = inc(x, y); }
inline void Dec(int &x, int y) { x = dec(x, y); }
inline int mval(int x) {
  if (x < 0) return x + p;
  if (x >= p) x -= p;
  return x;
}
inline int ksm(int a, int b) {
  int ans = 1;
  for (; b; b >>= 1, a = 1ll * a * a % p)
    if (b & 1) ans = 1ll * ans * a % p;
  return ans;
}
char s[2][2005];
int f[2005][4005], g[2005][4005];
int n;
inline void solve() {
  scanf("%d", &n);
  for (int i = (0); i <= (1); ++i) scanf("%s", s[i] + 1);
  for (int i = (0); i <= (1); ++i)
    for (int j = (1); j <= (n); ++j)
      if (s[i][j] != '?') s[i][j] ^= (j & 1);
  for (int i = (0); i <= (n); ++i)
    for (int j = (2001 - n); j <= (2001 + n); ++j) f[i][j] = g[i][j] = 0;
  g[0][2001] = 1;
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (4001); ++j)
      if (g[i - 1][j]) {
        for (int v0i = (0); v0i <= (1); ++v0i)
          for (int v1i = (0); v1i <= (1); ++v1i)
            if ((s[0][i] == '?' || (s[0][i] == (v0i + '0'))) &&
                (s[1][i] == '?' || (s[1][i] == (v1i + '0')))) {
              Inc(g[i][j + v0i - v1i], g[i - 1][j]);
              Inc(f[i][j + v0i - v1i], f[i - 1][j]);
              int t = j - 2001;
              if (t == 0) {
                if (v0i != v1i)
                  Dec(f[i][j + v0i - v1i], 2ll * g[i - 1][j] * i % p);
              } else if (t < 0) {
                if (!v0i)
                  Dec(f[i][j + v0i - v1i], 1ll * g[i - 1][j] * i % p);
                else
                  Inc(f[i][j + v0i - v1i], 1ll * g[i - 1][j] * i % p);
                if (!v1i)
                  Inc(f[i][j + v0i - v1i], 1ll * g[i - 1][j] * i % p);
                else
                  Dec(f[i][j + v0i - v1i], 1ll * g[i - 1][j] * i % p);
              } else {
                if (v0i)
                  Dec(f[i][j + v0i - v1i], 1ll * g[i - 1][j] * i % p);
                else
                  Inc(f[i][j + v0i - v1i], 1ll * g[i - 1][j] * i % p);
                if (v1i)
                  Inc(f[i][j + v0i - v1i], 1ll * g[i - 1][j] * i % p);
                else
                  Dec(f[i][j + v0i - v1i], 1ll * g[i - 1][j] * i % p);
              }
            }
      }
  printf("%d\n", 1ll * f[n][2001] * inv2 % p);
}
int main() {
  int T;
  cin >> T;
  while (T--) solve();
}
