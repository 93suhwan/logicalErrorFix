#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template <class T>
void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template <class T>
void print(T x, char let) {
  print(x), putchar(let);
}
template <class T1, class T2>
void ckmin(T1& x, T2 y) {
  if (x > y) x = y;
}
template <class T1, class T2>
void ckmax(T1& x, T2 y) {
  if (x < y) x = y;
}
const int N = 200005;
const int inf = 1e9;
char s[N];
int ls[N], rs[N];
int a[N], sq[N], p[N], ans[N], c;
int n, k;
void dfs(int u) {
  if (!u) return;
  dfs(ls[u]);
  ++c, sq[c] = s[u], p[u] = c;
  dfs(rs[u]);
}
void dfs0(int u) {
  if (!u) return;
  dfs0(ls[u]);
  if (a[u])
    printf("%c%c", s[u], s[u]);
  else
    printf("%c", s[u]);
  dfs0(rs[u]);
}
int sol(int u, int d) {
  if (ls[u] && sol(ls[u], d + 1)) a[u] = 1;
  if (rs[u]) {
    if (a[u] || (ans[p[u]] && k >= d)) {
      if (!a[u])
        a[u] = 1, k -= d;
      else if (sol(rs[u], 1))
        a[u] = 1;
    } else {
      if (sol(rs[u], inf)) a[u] = 1;
    }
  } else {
    if (a[u] || !(ans[p[u]] && k >= d))
      ;
    else
      a[u] = 1, k -= d;
  }
  return a[u];
}
int main() {
  scanf("%d%d%s", &n, &k, s + 1);
  for (int i = (1); i <= (n); i++) ls[i] = read(), rs[i] = read();
  dfs(1), ans[n] = 0;
  for (int i = (1); i <= (c); i++) sq[i] -= 'a';
  for (int i = (n - 1); i >= (0); i--)
    ans[i] = sq[i] != sq[i + 1] ? (sq[i] < sq[i + 1]) : ans[i + 1];
  sol(1, 1);
  dfs0(1);
  return 0;
}
