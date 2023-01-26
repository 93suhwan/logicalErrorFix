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
inline long long read() {
  long long x = 0, f = 0;
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
void write(long long x) {
  if (x < 0) pc('-'), x = -x;
  if (x > 9) write(x / 10);
  pc(x % 10 ^ 48);
}
const int N = 5e5 + 5;
int T, n, a[N];
bool flag = false;
inline void Solve() {
  n = read();
  int ans = 0;
  for (register int i = 1; i <= n; ++i) a[i] = read();
  if (!(n & 1)) {
    puts("YES");
    return;
  }
  for (register int i = 2; i <= n; ++i)
    if (a[i - 1] >= a[i]) {
      puts("YES");
      return;
    }
  puts("NO");
  return;
}
signed main() {
  T = read();
  while (T--) Solve();
  fwrite(o_str, 1, o_t, stdout), o_t = 0;
  return 0;
}
