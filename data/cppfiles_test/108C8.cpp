#include <bits/stdc++.h>
#pragma GCC optimize(2, 3, "Ofast")
#pragma GCC target("avx", "avx2")
using namespace std;
template <typename T1, typename T2>
void ckmin(T1 &a, T2 b) {
  if (a > b) a = b;
}
template <typename T1, typename T2>
void ckmax(T1 &a, T2 b) {
  if (a < b) a = b;
}
int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template <typename T>
void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
void print(T x, char let) {
  print(x), putchar(let);
}
const int N = 200005;
const int inf = 1e9;
int n, q;
struct SMT1 {
  long long sum[N << 2], tag[N << 2];
  void pushup(int u) { sum[u] = sum[(u << 1)] + sum[(u << 1 | 1)]; }
  void pushtag(int u, int tg, int l, int r) {
    tag[u] += tg, sum[u] += 1ll * tg * (r - l + 1);
  }
  void pushdown(int u, int l, int r) {
    if (tag[u]) {
      int mid = l + r >> 1;
      pushtag((u << 1), tag[u], l, mid),
          pushtag((u << 1 | 1), tag[u], mid + 1, r);
      tag[u] = 0;
    }
  }
  void build(int u, int l, int r) {
    if (l == r) {
      sum[u] = 1;
      return;
    }
    int mid = l + r >> 1;
    build((u << 1), l, mid), build((u << 1 | 1), mid + 1, r);
    pushup(u);
  }
  void update(int u, int l, int r, int ql, int qr, int x) {
    if (ql > qr) return;
    if (ql <= l && r <= qr) {
      pushtag(u, x, l, r);
      return;
    }
    pushdown(u, l, r);
    int mid = l + r >> 1;
    if (ql <= mid) update((u << 1), l, mid, ql, qr, x);
    if (qr > mid) update((u << 1 | 1), mid + 1, r, ql, qr, x);
    pushup(u);
  }
  long long query(int u, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return sum[u];
    int mid = l + r >> 1;
    pushdown(u, l, r);
    long long ret = 0;
    if (ql <= mid) ret += query((u << 1), l, mid, ql, qr);
    if (qr > mid) ret += query((u << 1 | 1), mid + 1, r, ql, qr);
    return ret;
  }
} smt1;
struct SMT2 {
  int mx[N << 2], mx2[N << 2], cnt[N << 2];
  int tag[N << 2];
  void pushup(int u) {
    if (mx[(u << 1)] == mx[(u << 1 | 1)])
      mx[u] = mx[(u << 1)], mx2[u] = max(mx2[(u << 1)], mx2[(u << 1 | 1)]),
      cnt[u] = cnt[(u << 1)] + cnt[(u << 1 | 1)];
    else if (mx[(u << 1)] > mx[(u << 1 | 1)])
      mx[u] = mx[(u << 1)], mx2[u] = max(mx2[(u << 1)], mx[(u << 1 | 1)]),
      cnt[u] = cnt[(u << 1)];
    else
      mx[u] = mx[(u << 1 | 1)], mx2[u] = max(mx[(u << 1)], mx2[(u << 1 | 1)]),
      cnt[u] = cnt[(u << 1 | 1)];
  }
  void pushtag(int u, int t) {
    if (mx[u] > t) mx[u] = t, tag[u] = t;
  }
  void pushdown(int u) {
    if (tag[u] != inf)
      pushtag((u << 1), tag[u]), pushtag((u << 1 | 1), tag[u]), tag[u] = inf;
  }
  void build(int u, int l, int r) {
    tag[u] = inf;
    if (l == r) {
      mx[u] = l, mx2[u] = 0, cnt[u] = 1;
      return;
    }
    int mid = l + r >> 1;
    build((u << 1), l, mid), build((u << 1 | 1), mid + 1, r);
    pushup(u);
  }
  void beat(int u, int l, int r, int ql, int qr, int x) {
    if (ql > qr || mx[u] <= x) return;
    if (ql <= l && r <= qr && mx2[u] < x) {
      smt1.update(1, 1, n, x + 1, mx[u], -cnt[u]);
      pushtag(u, x);
      return;
    }
    pushdown(u);
    int mid = l + r >> 1;
    if (ql <= mid) beat((u << 1), l, mid, ql, qr, x);
    if (qr > mid) beat((u << 1 | 1), mid + 1, r, ql, qr, x);
    pushup(u);
  }
  void update(int u, int l, int r, int pos, int x) {
    if (l == r) {
      if (x > mx[u])
        smt1.update(1, 1, n, mx[u] + 1, x, 1);
      else
        smt1.update(1, 1, n, x + 1, mx[u], -1);
      mx[u] = x, mx2[u] = 0, cnt[u] = 1;
      return;
    }
    pushdown(u);
    int mid = l + r >> 1;
    if (pos <= mid)
      update((u << 1), l, mid, pos, x);
    else
      update((u << 1 | 1), mid + 1, r, pos, x);
    pushup(u);
  }
} smt2;
int main() {
  n = read(), q = read();
  smt1.build(1, 1, n);
  smt2.build(1, 1, n);
  while (q--) {
    int opt = read(), x = read(), y = read();
    if (opt == 1) {
      smt2.beat(1, 1, n, 1, x - 1, x - 1);
      smt2.update(1, 1, n, x, y);
    } else {
      print(smt1.query(1, 1, n, x, y), '\n');
    }
  }
  return 0;
}
