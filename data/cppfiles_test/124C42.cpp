#include <bits/stdc++.h>
using namespace std;
template <typename T>
void chkmax(T& x, T y) {
  if (x < y) x = y;
}
template <typename T>
void chkmin(T& x, T y) {
  if (x > y) x = y;
}
namespace orzjk {
const int SZ = 1e6;
char buf[SZ], *p1 = buf, *p2 = buf;
char nc() {
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, SZ, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
char fub[SZ], *p3 = fub, *p4 = fub + SZ;
void pc(char c) {
  p3 == p4 && (fwrite(fub, 1, SZ, stdout), p3 = fub);
  *p3++ = c;
}
void flush() { fwrite(fub, 1, p3 - fub, stdout), p3 = fub; }
}  // namespace orzjk
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < 48) c == '-' && (f = -1), c = getchar();
  while (c > 47) x = x * 10 + (c ^ 48), c = getchar();
  return x * f;
}
void write(int x) {
  static char st[11];
  if (!x) return putchar(48), void();
  char* p = st;
  if (x < 0) x = -x, putchar('-');
  for (; x; x /= 10) *p++ = x % 10 | 48;
  do {
    putchar(*--p);
  } while (p != st);
}
const int P = 1e9 + 7;
int n;
char S[2010], T[2010];
int pre_S[2010][2], pre_T[2010][2];
int C[4010][4010];
namespace Arraiter {
int calc(int n, int m, int dt) {
  if (dt < 0) dt = -dt, swap(n, m);
  int res = 0;
  res = n >= dt ? C[n + m][n - dt] : 0;
  return res;
}
void solve() {
  scanf("%d%s%s", &n, S + 1, T + 1);
  for (int i = (1), iend = (n); i <= iend; ++i)
    if (i % 2 == 0) {
      if (S[i] != '?') S[i] ^= 1;
      if (T[i] != '?') T[i] ^= 1;
    }
  for (int i = (1), iend = (n); i <= iend; ++i)
    for (int j = (0), jend = (1); j <= jend; ++j)
      pre_S[i][j] = pre_S[i - 1][j] + (S[i] == 48 + j);
  for (int i = (1), iend = (n); i <= iend; ++i)
    for (int j = (0), jend = (1); j <= jend; ++j)
      pre_T[i][j] = pre_T[i - 1][j] + (T[i] == 48 + j);
  int ans = 0;
  for (int i = (1), iend = (n); i <= iend; ++i)
    for (int j = (1), jend = (n); j <= jend; ++j)
      if (S[i] != '0' && T[j] != '0') {
        int res = 0;
        {
          int x1 = pre_S[i - 1][1], y1 = i - 1 - x1 - pre_S[i - 1][0];
          int x2 = pre_T[j - 1][1], y2 = j - 1 - x2 - pre_T[j - 1][0];
          res = calc(y1, y2, x2 - x1);
        }
        {
          int x1 = pre_S[n][1] - pre_S[i][1],
              y1 = n - i - x1 - (pre_S[n][0] - pre_S[i][0]);
          int x2 = pre_T[n][1] - pre_T[j][1],
              y2 = n - j - x2 - (pre_T[n][0] - pre_T[j][0]);
          res = 1ll * res * calc(y1, y2, x2 - x1) % P;
        }
        ans = (ans + 1ll * abs(i - j) * res) % P;
      }
  write(ans), putchar(10);
}
}  // namespace Arraiter
signed main() {
  for (int i = (0), iend = (4000); i <= iend; ++i) {
    C[i][0] = 1;
    for (int j = (1), jend = (i); j <= jend; ++j)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % P;
  }
  int T = read();
  while (T--) Arraiter::solve();
  orzjk::flush();
  return 0;
}
