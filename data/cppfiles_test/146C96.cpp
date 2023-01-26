#include <bits/stdc++.h>
const int N = 1e5 + 5;
const int block = 320;
int p[N], pre[N], to[N];
int n, q;
inline int Read() {
  char ch;
  int f = 1;
  while ((ch = getchar()) < '0' || ch > '9')
    if (ch == '-') f = -1;
  int x = ch ^ 48;
  while ((ch = getchar()) >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + (ch ^ 48);
  return x * f;
}
inline void print(const int x) {
  if (x >= 10) print(x / 10);
  putchar(x % 10 + 48);
  return;
}
inline void Print(const int x, const char ch = '\n') {
  if (x < 0) {
    putchar('-');
    print(-x);
  } else
    print(x);
  putchar(ch);
  return;
}
inline void Update(const int u) {
  int v = u;
  for (register int i = 1; i <= block; i++) v = p[v];
  int uu = u;
  for (register int i = 1; i <= block; i++) {
    to[uu] = v;
    uu = pre[uu];
    v = pre[v];
  }
  return;
}
inline void Swap(int& x, int& y) {
  int tmp = x;
  x = y;
  y = tmp;
  return;
}
inline void Modify(const int u, const int v) {
  Swap(p[u], p[v]);
  pre[p[u]] = u;
  pre[p[v]] = v;
  Update(u);
  Update(v);
  return;
}
inline int Query(const int u, int k) {
  int uu = u;
  while (k >= block) {
    k -= block;
    uu = to[uu];
  }
  while (k) {
    k--;
    uu = p[uu];
  }
  return uu;
}
inline void Init() {
  n = Read();
  q = Read();
  for (register int i = 1; i <= n; i++) {
    p[i] = Read();
    pre[p[i]] = i;
  }
  for (register int i = 1; i <= n; i++) Update(i);
  return;
}
int main() {
  for (Init(); q; q--) {
    int opt = Read(), u = Read(), v = Read();
    if (opt == 1)
      Modify(u, v);
    else
      Print(Query(u, v));
  }
  return 0;
}
