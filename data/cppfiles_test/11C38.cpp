#include <bits/stdc++.h>
using namespace std;
inline char nc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline int read() {
  register int x = 0, f = 1;
  register char ch = nc();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = nc();
  }
  while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = nc();
  return x * f;
}
inline void write(register int x) {
  if (!x) putchar('0');
  if (x < 0) x = -x, putchar('-');
  static int sta[20];
  register int tot = 0;
  while (x) sta[tot++] = x % 10, x /= 10;
  while (tot) putchar(sta[--tot] + 48);
}
int n, a[200005], f[200005], ans;
struct node {
  int ls, rs, mx;
} tr[200005 * 30];
int rt, tot;
void modify(int &x, int l, int r, int pos, int val) {
  if (!x) x = ++tot;
  tr[x].mx = max(tr[x].mx, val);
  if (l == r) return;
  int mid = l + r >> 1;
  if (pos <= mid)
    modify(tr[x].ls, l, mid, pos, val);
  else
    modify(tr[x].rs, mid + 1, r, pos, val);
}
int qry(int x, int l, int r, int L, int R) {
  if (!x) return 0;
  if (L <= l && r <= R) return tr[x].mx;
  int res = 0, mid = l + r >> 1;
  if (L <= mid) res = max(res, qry(tr[x].ls, l, mid, L, R));
  if (R > mid) res = max(res, qry(tr[x].rs, mid + 1, r, L, R));
  return res;
}
pair<int, int> p[200005];
int kk = 0;
void solve(int l, int r) {
  if (l == r) {
    if (l >= a[l]) f[l] = max(f[l], 1);
    return;
  }
  int mid = l + r >> 1;
  solve(l, mid);
  kk = 0;
  for (int i = l; i <= r; ++i) p[++kk] = make_pair(a[i], -i);
  sort(p + 1, p + 1 + kk);
  for (int i = 1; i <= kk; ++i) {
    int pos = -p[i].second;
    if (pos <= mid)
      modify(rt, -2e5, 2e5, a[pos] - pos, f[pos]);
    else {
      int val = qry(rt, -2e5, 2e5, a[pos] - pos, 2e5);
      if (val == 0) {
        if (pos >= a[pos]) f[pos] = max(f[pos], 1);
      } else
        f[pos] = max(f[pos], val + 1);
    }
  }
  rt = 0;
  for (int i = 1; i <= tot; ++i) tr[i].ls = tr[i].rs = tr[i].mx = 0;
  tot = 0;
  solve(mid + 1, r);
}
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) a[i] = read();
  solve(1, n);
  for (int i = 1; i <= n; ++i) ans = max(ans, f[i]);
  printf("%d\n", ans);
  return 0;
}
