#include <bits/stdc++.h>
using namespace std;
const int MAXL = 1 << 22;
char i_str[MAXL], o_str[MAXL], *i_s, *i_t;
int o_t;
inline char gc() {
  if (i_s == i_t) {
    i_s = i_str;
    i_t = i_s + fread(i_str, 1, MAXL, stdin);
    return i_s == i_t ? EOF : *i_s++;
  } else
    return *i_s++;
}
inline int read() {
  int x = 0, f = 0;
  char ch = gc();
  for (; ch < '0' || ch > '9'; ch = gc())
    if (ch == '-') f = 1;
  for (; ch >= '0' && ch <= '9'; ch = gc()) x = x * 10 + (ch ^ 48);
  return f ? -x : x;
}
inline void pc(char x) {
  o_str[o_t++] = x;
  if (o_t == MAXL) fwrite(o_str, 1, o_t, stdout), o_t = 0;
}
void write(int x) {
  if (x < 0) pc('-'), x = -x;
  if (x > 9) write(x / 10);
  pc(x % 10 ^ 48);
}
const int N = 2e5 + 5, INF = 0x3f3f3f3f;
int n;
char s[N], t[N];
inline void Solve() {
  scanf("%d%s%s", &n, s + 1, t + 1);
  int sumc = 0, sumt = 0, ans = INF;
  for (register int i = 1; i <= n; ++i)
    sumc += s[i] == '1', sumt += t[i] == '1';
  if (sumc == sumt) {
    int cnt = 0;
    for (register int i = 1; i <= n; ++i)
      if (s[i] != t[i]) ++cnt;
    ans = min(ans, cnt);
  }
  if (sumc + sumt == n + 1) {
    int cnt = 1, w = 0;
    for (register int i = 1; i <= n; ++i)
      if (s[i] == '1' && t[i] == '1') w = i;
    for (register int i = 1; i <= n; ++i) {
      if (i == w) continue;
      s[i] = (s[i] == '1') ? '0' : '1';
    }
    for (register int i = 1; i <= n; ++i)
      if (s[i] != t[i]) ++cnt;
    ans = min(ans, cnt);
  }
  write((ans == INF) ? -1 : ans), pc('\n');
  return;
}
signed main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) Solve();
  fwrite(o_str, 1, o_t, stdout), o_t = 0;
  return 0;
}
