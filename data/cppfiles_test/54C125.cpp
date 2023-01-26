#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void qr(T &x) {
  x = 0;
  int f = 0;
  char s = getchar();
  while (s < '0' || '9' < s) f |= s == '-', s = getchar();
  while ('0' <= s && s <= '9') x = x * 10 + s - 48, s = getchar();
  x = f ? -x : x;
}
int cc = 0, buf[31];
template <typename T>
inline void qw(T x) {
  if (x < 0) putchar('-'), x = -x;
  do {
    buf[++cc] = int(x % 10);
    x /= 10;
  } while (x);
  while (cc) putchar(buf[cc--] + '0');
  putchar(' ');
}
int ad(int x, int y) {
  return (x + y) >= 1000000007 ? x + y - 1000000007 : x + y;
}
int mu(int x, int y) { return 1ll * x * y % 1000000007; }
int de(int x, int y) { return (x - y) < 0 ? x - y + 1000000007 : x - y; }
void mymin(int &x, int y) { x = x < y ? x : y; }
void mymax(int &x, int y) { x = x > y ? x : y; }
const int N = 4e5 + 10;
int n, m, fa[N], s[N];
char ss[21];
bool bk[N];
int findfa(int x) { return x == fa[x] ? x : fa[x] = findfa(fa[x]); }
void merge(int x, int y) {
  x = findfa(x), y = findfa(y);
  if (x != y) fa[x] = y, s[y] += s[x];
}
void solve() {
  qr(n), qr(m);
  for (int i = 1; i <= 2 * n; i++) fa[i] = i, bk[i] = 0;
  for (int i = 1; i <= n; i++) s[i] = 0;
  for (int i = n + 1; i <= n + n; i++) s[i] = 1;
  for (int i = 1; i <= m; i++) {
    int x, y;
    qr(x), qr(y);
    scanf("%s", ss + 1);
    int t = ss[1] == 'i';
    merge(x, y + t * n);
    merge(x + n, y + (t ^ 1) * n);
  }
  for (int i = 1; i <= n; i++)
    if (findfa(i) == findfa(i + n)) {
      puts("-1");
      return;
    }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (!bk[findfa(i)]) {
      bk[findfa(i)] = bk[findfa(i + n)] = 1;
      ans += max(s[findfa(i)], s[findfa(i + n)]);
    }
  qw(ans);
  puts("");
}
int main() {
  int tt;
  qr(tt);
  while (tt--) solve();
  return 0;
}
