#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 200200;
struct seg_tree {
  ll sum[maxn * 4], lazy[maxn * 4];
  void build(int l, int r, int rt) {
    sum[rt] = r - l + 1;
    if (l == r) return;
    int mid = (l + r) / 2;
    build(l, mid, rt << 1);
    build(mid + 1, r, rt << 1 | 1);
  }
  void push_down(int l, int r, int rt) {
    if (lazy[rt]) {
      int mid = (l + r) / 2;
      sum[rt << 1] += (mid - l + 1) * lazy[rt];
      sum[rt << 1 | 1] += (r - mid) * lazy[rt];
      lazy[rt << 1] += lazy[rt];
      lazy[rt << 1 | 1] += lazy[rt];
      lazy[rt] = 0;
    }
  }
  void add(int L, int R, int v, int l, int r, int rt) {
    if (L <= l && r <= R) {
      sum[rt] += v * (ll)(r - l + 1);
      lazy[rt] += v;
      return;
    }
    push_down(l, r, rt);
    int mid = (l + r) / 2;
    if (L <= mid) add(L, R, v, l, mid, rt << 1);
    if (mid < R) add(L, R, v, mid + 1, r, rt << 1 | 1);
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
  }
  ll ask(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) return sum[rt];
    int mid = (l + r) / 2;
    ll ans = 0;
    if (L <= mid) ans += ask(L, R, l, mid, rt << 1);
    if (mid < R) ans += ask(L, R, mid + 1, r, rt << 1 | 1);
    return ans;
  }
} S;
struct seg_tree2 {
  int n;
  struct node {
    int mx, mx2, num_mx, tag;
  } tr[maxn * 4];
  void build(int l, int r, int rt) {
    if (l == r) {
      tr[rt].mx = l;
      tr[rt].mx2 = 0;
      tr[rt].num_mx = 1;
      return;
    }
    int mid = (l + r) / 2;
    build(l, mid, rt << 1);
    build(mid + 1, r, rt << 1 | 1);
    tr[rt].mx = r;
    tr[rt].mx2 = r - 1;
    tr[rt].num_mx = 1;
  }
  void push_up(int rt) {
    if (tr[rt << 1].mx > tr[rt << 1 | 1].mx) {
      tr[rt].mx = tr[rt << 1].mx;
      tr[rt].mx2 = max(tr[rt << 1].mx2, tr[rt << 1 | 1].mx);
      tr[rt].num_mx = tr[rt << 1].num_mx;
    } else if (tr[rt << 1].mx < tr[rt << 1 | 1].mx) {
      tr[rt].mx = tr[rt << 1 | 1].mx;
      tr[rt].mx2 = max(tr[rt << 1].mx, tr[rt << 1 | 1].mx2);
      tr[rt].num_mx = tr[rt << 1 | 1].num_mx;
    } else {
      tr[rt].mx = tr[rt << 1].mx;
      tr[rt].mx2 = max(tr[rt << 1].mx2, tr[rt << 1 | 1].mx2);
      tr[rt].num_mx = tr[rt << 1].num_mx + tr[rt << 1 | 1].num_mx;
    }
  }
  void push_down(int rt) {
    if (tr[rt].tag) {
      if (tr[rt << 1].mx > tr[rt].tag) {
        tr[rt << 1].mx = tr[rt].tag;
        tr[rt << 1].tag = tr[rt].tag;
      }
      if (tr[rt << 1 | 1].mx > tr[rt].tag) {
        tr[rt << 1 | 1].mx = tr[rt].tag;
        tr[rt << 1 | 1].tag = tr[rt].tag;
      }
      tr[rt].tag = 0;
    }
  }
  void upd_min(int L, int R, int v, int l, int r, int rt) {
    if (l > R || r < L || tr[rt].mx <= v) return;
    if (L <= l && r <= R && tr[rt].mx2 < v) {
      S.add(v + 1, tr[rt].mx, -tr[rt].num_mx, 1, n, 1);
      tr[rt].mx = v;
      tr[rt].tag = v;
      return;
    }
    push_down(rt);
    int mid = (l + r) / 2;
    upd_min(L, R, v, l, mid, rt << 1);
    upd_min(L, R, v, mid + 1, r, rt << 1 | 1);
    push_up(rt);
  }
  void upd(int p, int v, int l, int r, int rt) {
    if (l == r) {
      if (tr[rt].mx > v) {
        S.add(v + 1, tr[rt].mx, -1, 1, n, 1);
      } else if (tr[rt].mx < v) {
        S.add(tr[rt].mx + 1, v, 1, 1, n, 1);
      }
      tr[rt].mx = v;
      return;
    }
    push_down(rt);
    int mid = (l + r) / 2;
    if (p <= mid)
      upd(p, v, l, mid, rt << 1);
    else
      upd(p, v, mid + 1, r, rt << 1 | 1);
    push_up(rt);
  }
} T;
int main(void) {
  int n, q;
  scanf("%d%d", &n, &q);
  S.build(1, n, 1);
  T.n = n;
  T.build(1, n, 1);
  for (int i = 0; i < q; i++) {
    int op, x, y;
    scanf("%d%d%d", &op, &x, &y);
    if (op == 1) {
      T.upd(x, y, 1, n, 1);
      if (x > 1) T.upd_min(1, x - 1, x - 1, 1, n, 1);
    } else {
      ll ans = S.ask(x, y, 1, n, 1);
      printf("%lld\n", ans);
    }
  }
  return 0;
}
