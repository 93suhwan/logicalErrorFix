#include <bits/stdc++.h>
using namespace std;
int n, Q;
class ZYK {
  class BIT {
    long long b[200020];
    inline int lowbit(int x) { return x & (-x); }

   public:
    inline void Add(int x, long long d) {
      while (x <= n) b[x] += d, x += lowbit(x);
    }
    inline long long Ask(int x) {
      long long ans = 0;
      while (x) ans += b[x], x -= lowbit(x);
      return ans;
    }
  } B1, B2;

 public:
  void Change(int l, int r, int d) {
    B1.Add(l, d), B1.Add(r + 1, -d);
    B2.Add(l, 1LL * l * d), B2.Add(r + 1, -1LL * (r + 1) * d);
  }
  long long Query(int l, int r) {
    return (1LL * (r + 1) * B1.Ask(r) - B2.Ask(r)) -
           (1LL * l * B1.Ask(l - 1) - B2.Ask(l - 1));
  }
} B;
class Seg {
  struct node {
    int mx, se, add, cnt;
    inline void Add(int d) { add += d, mx += d; }
    friend node operator+(const node &a, const node &b) {
      node c;
      c.mx = max(a.mx, b.mx);
      c.cnt = 0;
      if (c.mx == a.mx) c.cnt += a.cnt;
      if (c.mx == b.mx) c.cnt += b.cnt;
      c.se = max(c.mx == a.mx ? a.se : a.mx, c.mx == b.mx ? b.se : b.mx);
      return c;
    }
  } t[200020 << 2];
  inline void pushdown(int u) {
    if (t[u].add) {
      if (t[u << 1].mx + t[u].add == t[u].mx) t[u << 1].Add(t[u].add);
      if (t[u << 1 | 1].mx + t[u].add == t[u].mx) t[u << 1 | 1].Add(t[u].add);
      t[u].add = 0;
    }
  }

 public:
  void build(int u, int L, int R) {
    if (L == R) {
      t[u].mx = L;
      t[u].se = 0;
      B.Change(L, L, 1);
      t[u].cnt = 1;
      return;
    }
    int mid = (L + R) >> 1;
    build(u << 1, L, mid), build(u << 1 | 1, mid + 1, R);
  }
  void Min(int u, int L, int R, int l, int r, int d) {
    if (d >= t[u].mx) return;
    if (L >= l && R <= r && d > t[u].se) {
      B.Change(d + 1, t[u].mx, -t[u].cnt);
      t[u].Add(d - t[u].mx);
      return;
    }
    pushdown(u);
    int mid = (L + R) >> 1;
    if (l <= mid) Min(u << 1, L, mid, l, r, d);
    if (r > mid) Min(u << 1 | 1, mid + 1, R, l, r, d);
    t[u] = t[u << 1] + t[u << 1 | 1];
  }
  int Find(int u, int L, int R, int p) {
    if (L == R) return t[u].mx;
    pushdown(u);
    int mid = (L + R) >> 1;
    return p <= mid ? Find(u << 1, L, mid, p) : Find(u << 1 | 1, mid + 1, R, p);
  }
  void Change(int u, int L, int R, int p, int d) {
    if (L == R) {
      t[u].mx = d;
      return;
    }
    int mid = (L + R) >> 1;
    pushdown(u);
    p <= mid ? Change(u << 1, L, mid, p, d)
             : Change(u << 1 | 1, mid + 1, R, p, d);
    t[u] = t[u << 1] + t[u << 1 | 1];
  }
} T;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> Q;
  T.build(1, 1, n);
  while (Q--) {
    int opt, x, y;
    cin >> opt >> x >> y;
    if (opt == 1) {
      if (x > 1) T.Min(1, 1, n, 1, x - 1, x - 1);
      int z = T.Find(1, 1, n, x);
      B.Change(x, z, -1);
      T.Change(1, 1, n, x, y);
      B.Change(x, y, 1);
    } else {
      cout << B.Query(x, y) << '\n';
    }
  }
  return 0;
}
