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
const int N = 2e5 + 10;
int n, q, a[N], op, l, r;
struct node {
  long long sum;
  int len, pre, suf;
  inline node(int l = 0, int a = 0, int b = 0, long long c = 0) {
    len = l, pre = a, suf = b, sum = c;
  }
  inline node operator*(const node& p) const {
    node r =
        node(len + p.len, pre, p.suf, sum + p.sum + (long long)suf * p.pre);
    if (pre == len) r.pre += p.pre;
    if (p.suf == p.len) r.suf += suf;
    return r;
  }
} tr[N * 4];
inline node nnode(int v) {
  return v >= 0 ? node(1, 1, 1, 1) : node(1, 0, 0, 0);
}
void bld(int x, int l, int r) {
  if (l > r) return;
  if (l == r) {
    tr[x] = nnode(a[l] - a[l - 1]);
    return;
  }
  bld((x << 1), l, ((l + r) >> 1)), bld((x << 1 | 1), ((l + r) >> 1) + 1, r);
  tr[x] = tr[(x << 1)] * tr[(x << 1 | 1)];
}
void mdf(int x, int l, int r, int p, int v) {
  if (l == r) {
    tr[x] = nnode(v);
    return;
  }
  if (p <= ((l + r) >> 1))
    mdf((x << 1), l, ((l + r) >> 1), p, v);
  else
    mdf((x << 1 | 1), ((l + r) >> 1) + 1, r, p, v);
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
  bld(1, 2, n);
  while (q--) {
    op = read(), l = read(), r = read();
    if (op == 1) {
      if (n == 1) continue;
      a[l] = r;
      if (l > 1) mdf(1, 2, n, l, a[l] - a[l - 1]);
      if (l < n) mdf(1, 2, n, l + 1, a[l + 1] - a[l]);
    } else {
      if (l == r)
        write(1), putchar('\n');
      else
        write(qry(1, 2, n, l + 1, r).sum + (r - l + 1)), putchar('\n');
    }
  }
}
