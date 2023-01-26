#include <bits/stdc++.h>
using namespace std;
inline void Read(int &first) {
  int f = 1;
  first = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    first = (first << 3) + (first << 1) + c - '0', c = getchar();
  }
  first *= f;
}
const int N = 100010, p = 998244353;
int T, n, f[N];
struct Edge {
  int to, nxt;
} e[N << 1];
int hd[N], cnt;
inline void ade(int u, int v) {
  e[++cnt].to = v, e[cnt].nxt = hd[u], hd[u] = cnt;
}
bool ff;
int DFS(int u, int ff, int m) {
  int tot = 0;
  for (register int i = hd[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (v != ff) tot += DFS(v, u, m);
  }
  if (tot % m == 0) return 1;
  if ((tot + 1) % m == 0 && u != 1) return 0;
  ff = 0;
  return 0;
}
int main() {
  Read(T);
  while (T--) {
    memset(f, 0, sizeof f);
    Read(n), memset(hd, 0, sizeof hd), cnt = 0, f[1] = 1;
    for (register int i = 1, u, v; i < n; i++) {
      Read(u), Read(v), ade(u, v), ade(v, u), f[1] = 2ll * f[1] % p;
    }
    for (register int i = 2; i < n; i++) {
      if ((n - 1) % i == 0) {
        ff = 1, DFS(1, 0, i), f[i] = ff;
      }
    }
    for (register int i = n - 1; i; i--) {
      for (register int j = i + i; j < n; j += i) f[i] -= f[j];
      f[i] = (f[i] % p + p) % p;
    }
    for (register int i = 1; i <= n; i++) cout << f[i] << " ";
    puts("");
  }
  return 0;
}
