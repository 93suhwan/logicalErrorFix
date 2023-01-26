#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
int n, m, tot, a[MAXN], b[MAXN], d[MAXN];
map<int, int> to;
struct Node {
  int val, pos;
  bool operator<(const Node &AI) const { return val < AI.val; }
} c[MAXN];
struct Tree {
  int sum[MAXN * 4], lmin[MAXN * 4];
  void pushup(int rt) {
    sum[rt] = sum[(rt << 1)] + sum[(rt << 1 | 1)];
    lmin[rt] = min(lmin[(rt << 1)], sum[(rt << 1)] + lmin[(rt << 1 | 1)]);
  }
  void build(int rt, int l, int r) {
    if (l == r) {
      sum[rt] = lmin[rt] = 1;
      return;
    }
    int mid = (l + r) >> 1;
    build((rt << 1), l, mid);
    build((rt << 1 | 1), mid + 1, r);
    pushup(rt);
  }
  void modify(int rt, int l, int r, int p, int k) {
    if (l == r) {
      sum[rt] = lmin[rt] = k;
      return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid)
      modify((rt << 1), l, mid, p, k);
    else
      modify((rt << 1 | 1), mid + 1, r, p, k);
    pushup(rt);
  }
} T;
int lowbit(int x) { return x & -x; }
int query(int p) {
  int ret = 0;
  while (p > 0) ret += d[p], p -= lowbit(p);
  return ret;
}
void modify(int p) {
  while (p <= tot) d[p]++, p += lowbit(p);
}
int main() {
  int cas;
  scanf("%d", &cas);
  while (cas--) {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]), d[i] = a[i];
      c[i] = (Node){a[i], i};
    }
    long long ans = 0;
    sort(d + 1, d + n + 1);
    tot = unique(d + 1, d + n + 1) - d - 1;
    for (int i = 1; i <= tot; ++i) to[d[i]] = i, d[i] = 0;
    for (int i = 1; i <= n; ++i) {
      ans += i - 1 - query(to[a[i]]);
      modify(to[a[i]]);
    }
    for (int i = 1; i <= m; ++i) scanf("%d", &b[i]);
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    sort(c + 1, c + n + 1);
    int cur = 1;
    T.build(1, 1, n);
    for (int i = 1; i <= m; ++i) {
      long long base_ans = lower_bound(a + 1, a + n + 1, b[i]) - a - 1;
      while (cur <= n && c[cur].val < b[i]) {
        T.modify(1, 1, n, c[cur].pos, -1), cur++;
      }
      for (int j = cur; j <= n; ++j) {
        if (c[j].val != b[i]) break;
        T.modify(1, 1, n, c[j].pos, 0);
      }
      if (T.lmin[1] < 0) base_ans += T.lmin[1];
      ans += base_ans;
      while (cur <= n && c[cur].val == b[i]) {
        T.modify(1, 1, n, c[cur].pos, -1), cur++;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
