#include <bits/stdc++.h>
using std::vector;
struct op {
  int val;
  int pos;
  op() { val = pos = 0; }
};
op max(op u, op v) {
  if (u.val > v.val)
    return u;
  else
    return v;
}
struct SegmentT {
  int l, r;
  op d;
  op c;
};
SegmentT t[4000005];
struct Element {
  int l, r;
};
int a[1000005];
vector<Element> g[300005];
int nxt[300005];
int vis[300005];
int preWork(int n) {
  std::sort(a + 1, a + 1 + n);
  int p = 1, size = 0;
  while (p <= n) {
    int np = p;
    while (np + 1 <= n && a[np + 1] == a[p]) np++;
    a[++size] = a[p];
    p = np + 1;
  }
  return size;
}
int getID(int u, int n) {
  int L = 1, R = n;
  int res = -1;
  while (L <= R) {
    int M = (L + R) / 2;
    if (a[M] <= u) {
      res = M;
      L = M + 1;
    } else
      R = M - 1;
  }
  return res;
}
int max(int a, int b) { return a > b ? a : b; }
void build(int p, int l, int r) {
  t[p].l = l, t[p].r = r;
  t[p].c.val = t[p].c.pos = 0;
  if (l == r)
    t[p].d.val = t[p].d.pos = 0;
  else {
    int m = (l + r) / 2;
    build(2 * p, l, m);
    build(2 * p + 1, m + 1, r);
    t[p].d = max(t[2 * p].d, t[2 * p + 1].d);
  }
}
void spread(int p) {
  if (t[p].c.val != 0) {
    op c = t[p].c;
    t[p].c.val = t[p].c.pos = 0;
    t[2 * p].d = max(t[2 * p].d, c);
    t[2 * p].c = max(t[2 * p].c, c);
    t[2 * p + 1].d = max(t[2 * p + 1].d, c);
    t[2 * p + 1].c = max(t[2 * p + 1].c, c);
  }
}
void change(int p, int l, int r, op v) {
  if (l <= t[p].l && r >= t[p].r) {
    t[p].d = max(t[p].d, v);
    t[p].c = max(t[p].c, v);
  } else {
    spread(p);
    int m = (t[p].l + t[p].r) / 2;
    if (l <= m) change(2 * p, l, r, v);
    if (r >= m + 1) change(2 * p + 1, l, r, v);
    t[p].d = max(t[2 * p].d, t[2 * p + 1].d);
  }
}
op ask(int p, int l, int r) {
  if (l <= t[p].l && r >= t[p].r)
    return t[p].d;
  else {
    spread(p);
    op res;
    res.val = res.pos = 0;
    int m = (t[p].l + t[p].r) / 2;
    if (l <= m) res = max(res, ask(2 * p, l, r));
    if (r >= m + 1) res = max(res, ask(2 * p + 1, l, r));
    return res;
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int size = 0;
  for (int i = 0; i < m; i++) {
    int r, x, y;
    scanf("%d%d%d", &r, &x, &y);
    a[++size] = x;
    a[++size] = y + 1;
    g[r].push_back(Element{x, y});
  }
  size = preWork(size);
  build(1, 1, size);
  int ans = 1, id = 1;
  for (int i = n; i >= 1; i--) {
    int val = 1;
    nxt[i] = 0;
    for (Element e : g[i]) {
      int l = e.l, r = e.r;
      int x = getID(l, size);
      int y = getID(r, size);
      op offer = ask(1, x, y);
      if (val < offer.val + 1) {
        val = offer.val + 1;
        nxt[i] = offer.pos;
      }
    }
    if (ans < val) {
      ans = val;
      id = i;
    }
    for (Element e : g[i]) {
      int l = e.l, r = e.r;
      int x = getID(l, size);
      int y = getID(r, size);
      op now;
      now.val = val, now.pos = i;
      change(1, x, y, now);
    }
  }
  int p = id;
  while (p != 0) {
    vis[p] = 1;
    p = nxt[p];
  }
  printf("%d\n", n - ans);
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) printf("%d ", i);
  }
  printf("\n");
  return 0;
}
