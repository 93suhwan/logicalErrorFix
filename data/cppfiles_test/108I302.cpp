#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) (ch == '-') && (f = -f), ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
template <typename Type>
inline void chkmin(Type &x, const Type &y) {
  if (x > y) x = y;
}
template <typename Type>
inline void chkmax(Type &x, const Type &y) {
  if (x < y) x = y;
}
int n;
struct Node {
  int a, b, ord;
  bool operator<(const Node &tmp) const { return a < tmp.a; }
} a[MAXN];
bool ans[MAXN];
inline void solve() {
  int i;
  n = read();
  for (i = 1; i <= n; ++i) a[i].a = read(), a[i].ord = i;
  for (i = 1; i <= n; ++i) a[i].b = read();
  sort(a + 1, a + n + 1);
  int mx = 1;
  for (i = 2; i <= n; ++i)
    if (a[i].b > a[mx].b) mx = i;
  for (i = 1; i < mx; ++i) ans[a[i].ord] = 0;
  for (i = mx; i <= n; ++i) ans[a[i].ord] = 1;
  for (i = 1; i <= n; ++i) printf("%d", ans[i]);
  puts("");
}
int main() {
  for (int T = read(); T; --T) solve();
  return 0;
}
