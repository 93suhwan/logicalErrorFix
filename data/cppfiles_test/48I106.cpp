#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int r = 0, f = 1;
  char c = getchar();
  while (c < 48 || c > 57) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= 48 && c <= 57) r = r * 10 + (c & 15), c = getchar();
  return r * f;
}
inline void write(long long x) {
  char c[20], len = 0;
  if (!x) {
    putchar('0');
    return;
  }
  if (x < 0) x = -x, putchar('-');
  while (x) c[len++] = x % 10, x /= 10;
  while (len) putchar(c[--len] + 48);
}
const int N = 1e5 + 10;
int n, q, a[N];
long long suf[N];
struct node {
  long long s, pmx, smx, mx, mns;
  inline node operator*(const node& p) const {
    node r;
    r.s = s + p.s;
    r.pmx = pmx == s ? max(pmx, s + p.pmx) : pmx;
    r.smx = p.smx == p.s ? max(p.smx, smx + p.s) : p.smx;
    r.mx = max(max(mx, p.mx), smx + p.pmx);
    r.mns = min(mns, p.mns);
    return r;
  }
} tr[N * 4];
void bld(int x, int l, int r) {
  if (l == r) {
    tr[x].s = a[l];
    tr[x].pmx = tr[x].smx = tr[x].mx = max(0, a[l]);
    tr[x].mns = suf[l];
    return;
  }
  bld((x << 1), l, ((l + r) >> 1)), bld((x << 1 | 1), ((l + r) >> 1) + 1, r);
  tr[x] = tr[(x << 1)] * tr[(x << 1 | 1)];
}
node qry(int x, int l, int r, int L, int R) {
  if (l == L && r == R) return tr[x];
  if (R <= ((l + r) >> 1)) return qry((x << 1), l, ((l + r) >> 1), L, R);
  if (L > ((l + r) >> 1)) return qry((x << 1 | 1), ((l + r) >> 1) + 1, r, L, R);
  return qry((x << 1), l, ((l + r) >> 1), L, ((l + r) >> 1)) *
         qry((x << 1 | 1), ((l + r) >> 1) + 1, r, ((l + r) >> 1) + 1, R);
}
int main() {
  n = read(), q = read();
  for (int i = 1; i <= n; ++i) a[i] = read();
  for (int i = 1; i <= n; ++i) a[i] -= read();
  for (int i = n; i; --i) suf[i] = suf[i + 1] + a[i];
  bld(1, 1, n);
  while (q--) {
    int l = read(), r = read();
    node o = qry(1, 1, n, l, r);
    if (o.s || o.mns < suf[r + 1])
      puts("-1");
    else
      write(o.mx), putchar('\n');
  }
}
