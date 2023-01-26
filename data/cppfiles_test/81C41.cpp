#include <bits/stdc++.h>
using namespace std;
int read() {
  char c = 0;
  int sum = 0;
  while (c < '0' || c > '9') c = getchar();
  while ('0' <= c && c <= '9') sum = sum * 10 + c - '0', c = getchar();
  return sum;
}
struct reads {
  int s, a;
  bool operator<(const reads &t) const { return s + a < t.s + t.a; }
};
reads q[1000000 + 1];
int length, st[1000000 + 1], dp[1000000 + 1], leng, ans;
struct seg {
  struct node {
    int l, r, lazya, lazyb;
  };
  node tree[4 * 1000000 + 1];
  void spread(int k) {
    tree[k << 1].lazya += tree[k].lazya,
        tree[k << 1].lazyb =
            max(tree[k << 1].lazyb + tree[k].lazya, tree[k].lazyb);
    tree[k << 1 | 1].lazya += tree[k].lazya,
        tree[k << 1 | 1].lazyb =
            max(tree[k << 1 | 1].lazyb + tree[k].lazya, tree[k].lazyb);
    tree[k].lazya = tree[k].lazyb = 0;
    return;
  }
  void build(int k, int l, int r) {
    tree[k].l = l, tree[k].r = r, tree[k].lazya = tree[k].lazyb = 0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(k << 1, l, mid), build(k << 1 | 1, mid + 1, r);
    return;
  }
  void get_max(int k, int l, int r, int d) {
    if (l > r) return;
    if (tree[k].l == l && tree[k].r == r) {
      tree[k].lazyb = max(tree[k].lazyb, d);
      return;
    }
    spread(k);
    int mid = (tree[k].l + tree[k].r) >> 1;
    if (r <= mid)
      get_max(k << 1, l, r, d);
    else if (l >= mid + 1)
      get_max(k << 1 | 1, l, r, d);
    else
      get_max(k << 1, l, mid, d), get_max(k << 1 | 1, mid + 1, r, d);
    return;
  }
  void add(int k, int l, int r, int d) {
    if (l > r) return;
    if (tree[k].l == l && tree[k].r == r) {
      tree[k].lazya += d, tree[k].lazyb += d;
      return;
    }
    spread(k);
    int mid = (tree[k].l + tree[k].r) >> 1;
    if (r <= mid)
      add(k << 1, l, r, d);
    else if (l >= mid + 1)
      add(k << 1 | 1, l, r, d);
    else
      add(k << 1, l, mid, d), add(k << 1 | 1, mid + 1, r, d);
    return;
  }
  int query(int k, int x) {
    if (tree[k].l == tree[k].r) return max(tree[k].lazya, tree[k].lazyb);
    spread(k);
    int mid = (tree[k].l + tree[k].r) >> 1;
    if (x <= mid)
      return query(k << 1, x);
    else
      return query(k << 1 | 1, x);
  }
};
seg T;
int main() {
  int n, s, a, d;
  n = read(), d = read(), length = leng = 0;
  for (int i = 1; i <= n; ++i) {
    s = read(), a = read();
    if (s >= d) q[++length] = (reads){s, a}, st[++leng] = s, st[++leng] = a;
  }
  if (!length) {
    puts("0");
    return 0;
  }
  sort(st + 1, st + leng + 1), leng = unique(st + 1, st + leng + 1) - st - 1,
                               sort(q + 1, q + length + 1), T.build(1, 1, leng);
  for (int i = length; i >= 1; --i)
    dp[i] = T.query(1, lower_bound(st + 1, st + leng + 1, q[i].a) - st) + 1,
    ans = max(ans, dp[i]),
    T.add(1, lower_bound(st + 1, st + leng + 1, q[i].a) - st,
          lower_bound(st + 1, st + leng + 1, q[i].s) - st, 1),
    T.get_max(1, 1,
              min(lower_bound(st + 1, st + leng + 1, q[i].a) - st - 1,
                  lower_bound(st + 1, st + leng + 1, q[i].s) - st),
              dp[i]);
  printf("%d\n", ans);
  return 0;
}
