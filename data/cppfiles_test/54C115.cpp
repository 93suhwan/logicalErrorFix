#include <bits/stdc++.h>
const int N = 4e5 + 10;
const int M = 9699690;
const int mod = 1e9 + 7, Gi = 332748118;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3fll;
const int SIZE = 1 << 21;
char ibuf[SIZE], *iS, *iT;
using std::pair;
template <class T>
void read(T &x) {
  x = 0;
  int f = 0;
  char c = getchar();
  while (!isdigit(c)) f |= c == '-', c = getchar();
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  if (f) x = -x;
}
int random(int i) { return rand() % i + 1; }
template <class T>
void ckmax(T &x, T y) {
  x = x > y ? x : y;
}
template <class T>
void ckmin(T &x, T y) {
  x = x < y ? x : y;
}
template <class T>
T Abs(T x) {
  return x > 0 ? x : -x;
}
inline int plus(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
int qp(int d, int k) {
  int f = 1;
  while (k) {
    if (k & 1) f = (1ll * (f) * (d) % mod);
    d = (1ll * (d) * (d) % mod), k >>= 1;
  }
  return f;
}
int n, m, f[N], siz[N], vis[N];
char s[N];
int Find(int x) { return f[x] = f[x] == x ? x : Find(f[x]); }
void Merge(int u, int v) {
  u = Find(u), v = Find(v);
  if (u == v) return;
  siz[u] += siz[v];
  f[v] = u;
}
void work() {
  read(n), read(m);
  for (int i = (1); i <= (n); i++) siz[i] = 1, siz[i + n] = 0;
  for (int i = (1); i <= (n << 1); i++) f[i] = i, vis[i] = 0;
  int flg = 0;
  for (int i = (1); i <= (m); i++) {
    int u, v;
    read(u), read(v);
    scanf("%s", s + 1);
    if (flg) continue;
    if (s[1] == 'i') {
      if (Find(u) == Find(v))
        flg = 1;
      else {
        Merge(u, v + n);
        Merge(v, u + n);
      }
    } else {
      if (Find(u) == Find(v + n))
        flg = 1;
      else {
        Merge(u, v);
        Merge(u + n, v + n);
      }
    }
  }
  if (flg)
    puts("-1");
  else {
    int ans = 0;
    for (int i = (1); i <= (n); i++) {
      int r1 = Find(i), r2 = Find(i + n);
      if (!vis[r1] && !vis[r2]) {
        vis[r1] = vis[r2] = 1;
        ans += std::max(siz[r1], siz[r2]);
      }
    }
    printf("%d\n", ans);
  }
}
int main() {
  int T = 1;
  read(T);
  while (T--) work();
  return 0;
}
