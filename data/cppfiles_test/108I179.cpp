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
} a[MAXN];
int premax[MAXN];
bool ans[MAXN];
set<int> s;
inline void solve() {
  int i;
  n = read();
  s.clear();
  for (i = 1; i <= n; ++i) a[i].a = read(), a[i].ord = i;
  for (i = 1; i <= n; ++i) a[i].b = read();
  sort(a + 1, a + n + 1, [](Node a, Node b) { return a.a < b.a; });
  for (i = 1; i <= n; ++i) premax[i] = max(premax[i - 1], a[i].b);
  ans[a[n].ord] = 1;
  s.insert(-a[n].b);
  for (i = n - 1; i; --i) {
    set<int>::iterator it = s.lower_bound(-a[i].b);
    if (it != s.end() || premax[i] > a[n].b)
      ans[a[i].ord] = 1, s.insert(-a[i].b);
    else
      ans[a[i].ord] = 0;
  }
  for (i = 1; i <= n; ++i) printf("%d", ans[i]);
  puts("");
}
int main() {
  for (int T = read(); T; --T) solve();
  return 0;
}
