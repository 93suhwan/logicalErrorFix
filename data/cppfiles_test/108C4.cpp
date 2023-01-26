#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
template <typename T>
inline void read(T &WOW) {
  T x = 0, flag = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  WOW = flag * x;
}
int n, q;
struct BIT {
  long long t1[MAXN], t2[MAXN];
  inline void add(int x, int v) {
    long long tmp = x * v;
    for (int i = x; i <= n; i += (i & (-i))) {
      t1[i] += v;
      t2[i] += tmp;
    }
  }
  inline long long sum(int x) {
    long long r1 = 0, r2 = 0;
    for (int i = x; i; i -= (i & (-i))) {
      r1 += t1[i];
      r2 += t2[i];
    }
    return r1 * (x + 1) - r2;
  }
  inline void upd(int l, int r, int v) {
    add(l, v);
    if (r < n) add(r + 1, -v);
  }
  inline long long qry(int l, int r) { return sum(r) - sum(l - 1); }
} seg1;
struct SegmentTreeBeats {
  int mx[MAXN << 2], mx2[MAXN << 2], cnt[MAXN << 2], tag[MAXN << 2];
  inline void puttag(int rt, int tg) { mx[rt] = tag[rt] = tg; }
  inline void pushdown(int rt) {
    if (tag[rt]) {
      int tmp = max(mx[(rt << 1)], mx[(rt << 1) | 1]);
      if (mx[(rt << 1)] == tmp) {
        puttag((rt << 1), tag[rt]);
      }
      if (mx[(rt << 1) | 1] == tmp) {
        puttag((rt << 1) | 1, tag[rt]);
      }
      tag[rt] = 0;
    }
  }
  inline void pushup(int rt) {
    if (mx[(rt << 1)] == mx[(rt << 1) | 1]) {
      mx[rt] = mx[(rt << 1)];
      mx2[rt] = max(mx2[(rt << 1)], mx2[(rt << 1) | 1]);
      cnt[rt] = cnt[(rt << 1)] + cnt[(rt << 1) | 1];
    } else if (mx[(rt << 1)] > mx[(rt << 1) | 1]) {
      mx[rt] = mx[(rt << 1)];
      mx2[rt] = max(mx2[(rt << 1)], mx[(rt << 1) | 1]);
      cnt[rt] = cnt[(rt << 1)];
    } else {
      mx[rt] = mx[(rt << 1) | 1];
      mx2[rt] = max(mx[(rt << 1)], mx2[(rt << 1) | 1]);
      cnt[rt] = cnt[(rt << 1) | 1];
    }
  }
  void Build(int rt, int b, int e) {
    if (b == e) {
      mx[rt] = b;
      mx2[rt] = 0;
      cnt[rt] = 1;
      return;
    }
    int mid = (b + e) >> 1;
    Build((rt << 1), b, mid);
    Build((rt << 1) | 1, mid + 1, e);
    pushup(rt);
  }
  void Insert(int rt, int b, int e, int p, int v) {
    if (b == e) {
      seg1.upd(b, mx[rt], -1);
      mx[rt] = v;
      seg1.upd(b, mx[rt], 1);
      return;
    }
    int mid = (b + e) >> 1;
    pushdown(rt);
    if (p <= mid)
      Insert((rt << 1), b, mid, p, v);
    else
      Insert((rt << 1) | 1, mid + 1, e, p, v);
    pushup(rt);
  }
  void UpdateMin(int rt, int b, int e, int l, int r, int v) {
    if (mx[rt] <= v) return;
    if (l <= b && e <= r && v > mx2[rt]) {
      seg1.upd(v + 1, mx[rt], -cnt[rt]);
      puttag(rt, v);
      return;
    }
    int mid = (b + e) >> 1;
    pushdown(rt);
    if (l <= mid) UpdateMin((rt << 1), b, mid, l, r, v);
    if (r > mid) UpdateMin((rt << 1) | 1, mid + 1, e, l, r, v);
    pushup(rt);
  }
} seg2;
void solve() {
  read(n);
  read(q);
  seg1.upd(1, n, 1);
  seg2.Build(1, 1, n);
  int type, l, r;
  while (q--) {
    read(type);
    read(l);
    read(r);
    if (type == 1) {
      seg2.Insert(1, 1, n, l, r);
      if (l > 1) seg2.UpdateMin(1, 1, n, 1, l - 1, l - 1);
    } else {
      printf("%lld\n", seg1.qry(l, r));
    }
  }
}
int main() {
  solve();
  return 0;
}
