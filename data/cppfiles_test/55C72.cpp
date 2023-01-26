#include <bits/stdc++.h>
using namespace std;
int n, m, cnt, A[600009 << 1], f[600009], idx[600009];
struct data {
  int x, l, r;
} a[600009];
vector<data> cc[600009];
struct node {
  int id, mi;
  node() { id = 0, mi = 1000000000; }
} s[600009 << 2], tag[600009 << 2];
node operator+(node i, node j) {
  node o;
  if (i.mi < j.mi) {
    o = i;
  } else {
    o = j;
  }
  return o;
}
void mark(int now, node v) {
  if (v.mi < s[now].mi) {
    s[now] = v;
    tag[now] = v;
  } else {
    tag[now] = v;
  }
}
void pushdown(int now) {
  if (tag[now].mi != 1000000000) {
    mark((now << 1), tag[now]);
    mark((now << 1 | 1), tag[now]);
    tag[now] = node();
  }
}
void update(int l, int r, int now, int L, int R, node v) {
  if (l >= L && r <= R) {
    mark(now, v);
    return;
  }
  pushdown(now);
  int mid = (l + r) >> 1;
  if (L <= mid) update(l, mid, (now << 1), L, R, v);
  if (R > mid) update(mid + 1, r, (now << 1 | 1), L, R, v);
  s[now] = s[(now << 1)] + s[(now << 1 | 1)];
}
node query(int l, int r, int now, int L, int R) {
  if (l >= L && r <= R) {
    return s[now];
  }
  pushdown(now);
  int mid = (l + r) >> 1;
  if (L <= mid && R > mid)
    return query(l, mid, (now << 1), L, R) +
           query(mid + 1, r, (now << 1 | 1), L, R);
  else if (L <= mid)
    return query(l, mid, (now << 1), L, R);
  else
    return query(mid + 1, r, (now << 1 | 1), L, R);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d%d", &a[i].x, &a[i].l, &a[i].r);
    A[++cnt] = a[i].l, A[++cnt] = a[i].r;
  }
  sort(A + 1, A + 1 + cnt);
  cnt = unique(A + 1, A + 1 + cnt) - A - 1;
  for (int i = 1; i <= m; ++i) {
    a[i].l = lower_bound(A + 1, A + 1 + cnt, a[i].l) - A;
    a[i].r = lower_bound(A + 1, A + 1 + cnt, a[i].r) - A;
    cc[a[i].x].push_back(a[i]);
  }
  int ans = n - 1, ii = 0;
  for (int i = n; i >= 1; --i) {
    f[i] = n - i;
    int id = n + 1;
    idx[i] = n + 1;
    if (!cc[i].size()) {
      continue;
    }
    for (int j = 0; j < cc[i].size(); ++j) {
      int l = cc[i][j].l, r = cc[i][j].r;
      node pp = query(1, cnt, 1, l, r);
      if (pp.mi - i - 1 < f[i]) {
        f[i] = pp.mi - i - 1;
        id = pp.id;
      }
    }
    idx[i] = id;
    node nn;
    nn.mi = f[i] + i, nn.id = i;
    for (int j = 0; j < cc[i].size(); ++j) {
      int l = cc[i][j].l, r = cc[i][j].r;
      update(1, cnt, 1, l, r, nn);
    }
    if (i - 1 + f[i] < ans) ii = i;
    ans = min(ans, i - 1 + f[i]);
  }
  if (ans == n - 1) {
    printf("%d\n", ans);
    for (int i = 1; i < n; ++i) printf("%d ", i);
    return 0;
  }
  if (ans == 0)
    printf("0\n");
  else {
    printf("%d\n", ans);
    for (int i = 1; i < ii; ++i) printf("%d ", i);
    for (int i = ii; i <= n; i = idx[i]) {
      int l = i + 1, r = idx[i] - 1;
      for (int p = l; p <= r; ++p) printf("%d ", p);
    }
  }
  return 0;
}
