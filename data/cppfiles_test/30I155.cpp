#include <bits/stdc++.h>
using namespace std;
namespace io {
const int N = 1 << 20;
char buf[N], *t1 = buf, *t2 = buf;
inline int read() {
  static int an, f;
  an = 0, f = 1;
  static char ch;
  ch = t1 == t2 && (t2 = (t1 = buf) + fread(buf, 1, N, stdin), t1 == t2)
           ? EOF
           : *t1++;
  while (ch < 48 || ch > 57)
    ch == '-' ? f = -1 : 0,
                ch = t1 == t2 && (t2 = (t1 = buf) + fread(buf, 1, N, stdin),
                                  t1 == t2)
                         ? EOF
                         : *t1++;
  while (ch >= 48 && ch <= 57)
    an = (an << 3) + (an << 1) + (ch ^ 48),
    ch = t1 == t2 && (t2 = (t1 = buf) + fread(buf, 1, N, stdin), t1 == t2)
             ? EOF
             : *t1++;
  return an * f;
}
char buff[N], *T = buff;
inline void flush() {
  fwrite(buff, 1, T - buff, stdout);
  T = buff;
}
inline void putc(char ch) {
  if (T == buff + N) flush();
  *T++ = ch;
}
template <typename T>
inline void print(T x) {
  if (!x) {
    putc('0');
    return;
  }
  if (x < 0) putc('-'), x = -x;
  static int st[30], tp;
  while (x) st[++tp] = x % 10, x /= 10;
  while (tp) putc(st[tp--] ^ 48);
}
}  // namespace io
using io::flush;
using io::print;
using io::putc;
using io::read;
int n, q, f[1000010], p[1000010], pnum, a[150010];
bool vis[1000010];
vector<int> d[1000010];
void init() {
  for (int i = 1; i <= 1000001; ++i) f[i] = i;
  for (int i = 2; i <= 1000001; ++i) {
    if (!vis[i]) p[++pnum] = i, d[i].emplace_back(i);
    for (int j = 1; j <= pnum && p[j] * i <= 1000001; ++j) {
      vis[p[j] * i] = 1;
      d[p[j] * i] = d[i];
      if (i % p[j] == 0)
        break;
      else
        d[p[j] * i].emplace_back(p[j]);
    }
  }
  memset(vis + 1, 0, 1000001);
}
int find(int x) {
  if (x != f[x]) return f[x] = find(f[x]);
  return x;
}
int solve(int x, int y) {
  bool flag = 0;
  for (auto i : d[x]) vis[find(i)] = 1;
  for (auto i : d[y])
    if (vis[find(i)]) flag = 1;
  if (flag) {
    for (auto i : d[x]) vis[find(i)] = 0;
    return 0;
  }
  for (auto i : d[y + 1])
    if (vis[find(i)]) flag = 1;
  for (auto i : d[x]) vis[find(i)] = 0;
  if (flag) return 1;
  for (auto i : d[y]) vis[find(i)] = 1;
  for (auto i : d[x + 1])
    if (vis[find(i)]) flag = 1;
  for (auto i : d[y]) vis[find(i)] = 0;
  return flag ? 1 : 2;
}
int main() {
  init();
  n = read(), q = read();
  for (int i = 1; i <= n; ++i) {
    a[i] = read();
    int rt = find(d[a[i]][0]);
    for (auto x : d[a[i]]) f[find(x)] = rt;
  }
  while (q--) print(solve(a[read()], a[read()])), putc('\n');
  flush();
  return 0;
}
