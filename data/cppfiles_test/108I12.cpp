#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char ch = getchar();
  long long nega = 1;
  while (!isdigit(ch)) {
    if (ch == '-') nega = -1;
    ch = getchar();
  }
  long long ans = 0;
  while (isdigit(ch)) {
    ans = ans * 10 + ch - 48;
    ch = getchar();
  }
  if (nega == -1) return -ans;
  return ans;
}
void print(vector<long long> x) {
  for (long long i = 0; i < (long long)x.size(); i++)
    printf("%lld%c", x[i], " \n"[i == (long long)x.size() - 1]);
}
long long n, Q;
struct SMT {
  long long t[200005 * 4], tag[200005 * 4];
  void upd(long long u, long long l, long long r, long long v) {
    tag[u] += v, t[u] += v * (r - l + 1);
  }
  void pushdown(long long u, long long l, long long r) {
    upd((u << 1), l, ((l + r) / 2), tag[u]),
        upd((u << 1 | 1), ((l + r) / 2) + 1, r, tag[u]), tag[u] = 0;
  }
  void update(long long u, long long l, long long r, long long L, long long R,
              long long v) {
    if (L > R) return;
    if (L <= l && r <= R) return upd(u, l, r, v);
    pushdown(u, l, r);
    if (((l + r) / 2) >= L) update((u << 1), l, ((l + r) / 2), L, R, v);
    if (((l + r) / 2) < R) update((u << 1 | 1), ((l + r) / 2) + 1, r, L, R, v);
    t[u] = t[(u << 1)] + t[(u << 1 | 1)];
  }
  long long query(long long u, long long l, long long r, long long L,
                  long long R) {
    if (L <= l && r <= R) return t[u];
    pushdown(u, l, r);
    long long ans = 0;
    if (((l + r) / 2) >= L) ans += query((u << 1), l, ((l + r) / 2), L, R);
    if (((l + r) / 2) < R)
      ans += query((u << 1 | 1), ((l + r) / 2) + 1, r, L, R);
    return ans;
  }
} smt;
struct Driver {
  long long mx[200005 * 4], second[200005 * 4], cnt[200005 * 4],
      tag[200005 * 4];
  void pushup(long long u) {
    if (mx[(u << 1)] == mx[(u << 1 | 1)]) {
      mx[u] = mx[(u << 1)],
      second[u] = max(second[(u << 1)], second[(u << 1 | 1)]);
      cnt[u] = cnt[(u << 1)] + cnt[(u << 1 | 1)];
    } else if (mx[(u << 1)] > mx[(u << 1 | 1)]) {
      mx[u] = mx[(u << 1)], second[u] = max(mx[(u << 1 | 1)], second[(u << 1)]);
      cnt[u] = cnt[(u << 1)];
    } else {
      mx[u] = mx[(u << 1 | 1)],
      second[u] = max(mx[(u << 1)], second[(u << 1 | 1)]);
      cnt[u] = cnt[(u << 1 | 1)];
    }
  }
  void upd(long long u, long long v) {
    if (v < mx[u]) mx[u] = v, tag[u] = v;
  }
  void pushdown(long long u) {
    if (tag[u] == 0x3f3f3f3f) return;
    upd((u << 1), tag[u]), upd((u << 1 | 1), tag[u]);
    tag[u] = 0x3f3f3f3f;
  }
  void build(long long u, long long l, long long r) {
    tag[u] = 0x3f3f3f3f;
    if (l == r) {
      mx[u] = l, cnt[u] = 1;
      return;
    }
    build((u << 1), l, ((l + r) / 2)),
        build((u << 1 | 1), ((l + r) / 2) + 1, r);
    pushup(u);
  }
  void update(long long u, long long l, long long r, long long L, long long R,
              long long v) {
    if (L > R || v >= mx[u]) return;
    if (L <= l && r <= R && v > second[u]) {
      smt.update(1, 1, n, v + 1, mx[u], -cnt[u]);
      upd(u, v);
      return;
    }
    pushdown(u);
    if (((l + r) / 2) >= L) update((u << 1), l, ((l + r) / 2), L, R, v);
    if (((l + r) / 2) < R) update((u << 1 | 1), ((l + r) / 2) + 1, r, L, R, v);
    pushup(u);
  }
  void fix(long long u, long long l, long long r, long long pos, long long v) {
    if (l == r) {
      smt.update(1, 1, n, mx[u] + 1, v, 1);
      mx[u] = v;
      return;
    }
    pushdown(u);
    if (pos <= ((l + r) / 2))
      fix((u << 1), l, ((l + r) / 2), pos, v);
    else
      fix((u << 1 | 1), ((l + r) / 2) + 1, r, pos, v);
    pushup(u);
  }
} smt2;
signed main() {
  cin >> n >> Q;
  smt2.build(1, 1, n);
  smt.update(1, 1, n, 1, n, 1);
  while (Q--) {
    long long op = read();
    if (op == 1) {
      long long p = read(), v = read();
      smt2.fix(1, 1, n, p, v);
      smt2.update(1, 1, n, 1, p - 1, p - 1);
    } else {
      long long l = read(), r = read();
      printf("%lld\n", smt.query(1, 1, n, l, r));
    }
  }
  return 0;
}
