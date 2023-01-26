#include <bits/stdc++.h>
using namespace std;
namespace IO {
long long len = 0;
char ibuf[(1 << 20) + 1], *iS, *iT, out[(1 << 25) + 1];
inline long long read() {
  char ch = (iS == iT ? iT = (iS = ibuf) + fread(ibuf, 1, (1 << 20) + 1, stdin),
             (iS == iT ? EOF : *iS++) : *iS++);
  long long x = 0;
  char t = 0;
  while (ch < '0' || ch > '9')
    t |= ch == '-', ch = (iS == iT ? iT = (iS = ibuf) +
                                          fread(ibuf, 1, (1 << 20) + 1, stdin),
                          (iS == iT ? EOF : *iS++) : *iS++);
  while (ch >= '0' && ch <= '9')
    x = x * 10 + (ch ^ 48),
    ch = (iS == iT ? iT = (iS = ibuf) + fread(ibuf, 1, (1 << 20) + 1, stdin),
          (iS == iT ? EOF : *iS++) : *iS++);
  return t ? -x : x;
}
inline void putc(char ch) { out[len++] = ch; }
template <class T>
inline void write(T x) {
  if (x < 0) putc('-'), x = -x;
  if (x > 9) write(x / 10);
  out[len++] = x % 10 + 48;
}
string getstr(void) {
  string s = "";
  char c = (iS == iT ? iT = (iS = ibuf) + fread(ibuf, 1, (1 << 20) + 1, stdin),
            (iS == iT ? EOF : *iS++) : *iS++);
  while (c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == EOF)
    c = (iS == iT ? iT = (iS = ibuf) + fread(ibuf, 1, (1 << 20) + 1, stdin),
         (iS == iT ? EOF : *iS++) : *iS++);
  while (!(c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == EOF))
    s.push_back(c),
        c = (iS == iT ? iT = (iS = ibuf) + fread(ibuf, 1, (1 << 20) + 1, stdin),
             (iS == iT ? EOF : *iS++) : *iS++);
  return s;
}
void putstr(string str, long long begin = 0, long long end = -1) {
  if (end == -1) end = str.size();
  for (long long i = begin; i < end; i++) putc(str[i]);
  return;
}
inline void flush() {
  fwrite(out, 1, len, stdout);
  len = 0;
}
}  // namespace IO
using IO::flush;
using IO::getstr;
using IO::putc;
using IO::putstr;
using IO::read;
using IO::write;
const long long N = 3000;
long long n, m, q, ans, cnt, a[N][N], dp1[N][N], dp2[N][N];
void solve() {
  n = read(), m = read(), q = read();
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++) dp1[i][j] = dp2[i][j] = 1;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      if (i > 1) dp1[i][j] = 1 + dp2[i - 1][j];
      if (j > 1) dp2[i][j] = 1 + dp1[i][j - 1];
      a[i][j] = 1;
    }
  }
  long long ans = 0, tot = n * m;
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++) ans += dp1[i][j] + dp2[i][j];
  while (q--) {
    long long i, j;
    i = read(), j = read();
    a[i][j] ^= 1;
    if (a[i][j] == 0) {
      tot--;
      ans -= (dp1[i][j] + dp2[i][j]);
      dp1[i][j] = dp2[i][j] = 0;
      ans += (dp1[i][j] + dp2[i][j]);
    } else {
      tot++;
      ans -= dp1[i][j] + dp2[i][j];
      if (i > 1)
        dp1[i][j] = 1 + dp2[i - 1][j];
      else
        dp1[i][j] = 1;
      if (j > 1)
        dp2[i][j] = 1 + dp1[i][j - 1];
      else
        dp2[i][j] = 1;
      ans += dp1[i][j] + dp2[i][j];
    }
    while (i <= n && j <= m) {
      if (i < n) {
        ans -= dp1[i + 1][j];
        dp1[i + 1][j] = a[i + 1][j] * (1 + dp2[i][j]);
        ans += dp1[i + 1][j];
      }
      if (j < m) {
        ans -= dp2[i][j + 1];
        dp2[i][j + 1] = a[i][j + 1] * (1 + dp1[i][j]);
        ans += dp2[i][j + 1];
      }
      if (i < n && j < m) {
        ans -= dp1[i + 1][j + 1] + dp2[i + 1][j + 1];
        dp1[i + 1][j + 1] = a[i + 1][j + 1] * (1 + dp2[i][j + 1]);
        dp2[i + 1][j + 1] = a[i + 1][j + 1] * (1 + dp1[i + 1][j]);
        ans += dp1[i + 1][j + 1] + dp2[i + 1][j + 1];
      }
      i++, j++;
    }
    cout << ans - tot << " " << endl;
  }
}
signed main() {
  solve();
  return 0;
}
