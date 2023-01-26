#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int k = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    k = k * 10 + ch - '0';
    ch = getchar();
  }
  return k * f;
}
inline void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writeln(int x) {
  write(x);
  puts("");
}
const int N = 4e5 + 10, M = 2e5;
int t[20 * N], ls[20 * N], rs[20 * N], n;
int a[N], cntt = 0;
int f[N], maxx = 0;
inline void upd(int l, int r, int x, int v, int &nod) {
  if (!nod) nod = ++cntt;
  if (l == r) {
    t[nod] = v;
    return;
  }
  int mid = l + r >> 1;
  if (x <= mid)
    upd(l, mid, x, v, ls[nod]);
  else
    upd(mid + 1, r, x, v, rs[nod]);
  t[nod] = max(t[ls[nod]], t[rs[nod]]);
}
inline void update(int x, int y, int v) {
  for (; x <= maxx; x += x & -x) upd(1, M + n, y, v, f[x]);
}
inline int tmax(int l, int r, int i, int j, int &nod) {
  if (!nod) return -1;
  if (l >= i && r <= j) return t[nod];
  int mid = l + r >> 1, ans = -1;
  if (i <= mid) ans = max(ans, tmax(l, mid, i, j, ls[nod]));
  if (j > mid) ans = max(ans, tmax(mid + 1, r, i, j, rs[nod]));
  return ans;
}
inline int smax(int x, int y) {
  int ans = -1;
  for (; x; x -= x & -x) {
    ans = max(ans, tmax(1, M + n, 1, y, f[x]));
  }
  return ans;
}
int main() {
  n = read();
  memset(t, -1, sizeof t);
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    maxx = max(maxx, a[i]);
  }
  maxx++;
  update(1, 0 + M, 0);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int p = i - a[i];
    int v = smax(a[i], p + M) + 1;
    ans = max(ans, v);
    update(a[i] + 1, p + M, v);
  }
  writeln(ans);
  return 0;
}
