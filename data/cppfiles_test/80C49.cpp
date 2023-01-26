#include <bits/stdc++.h>
using namespace std;
int n, m, a[2000100], b[2000100], c[2000100], len, p[2000100];
long long ans;
class BIT {
  int b[2000100];
  inline int lowbit(int x) { return x & (-x); }

 public:
  void Clear(int n) {
    for (int i = 1; i <= len; ++i) {
      b[i] = 0;
    }
  }
  inline void Add(int x, int d) {
    while (x <= len) b[x] += d, x += lowbit(x);
  }
  inline int Ask(int x) {
    int ans = 0;
    while (x) ans += b[x], x -= lowbit(x);
    return ans;
  }
} B;
class Segment_Tree {
  struct node {
    int mx, add;
    inline void Add(int d) { add += d, mx += d; }
  } t[2000100 << 2];
  inline void pushdown(int u) {
    if (t[u].add) {
      t[u << 1].Add(t[u].add);
      t[u << 1 | 1].Add(t[u].add);
      t[u].add = 0;
    }
  }
  inline void update(int u) { t[u].mx = max(t[u << 1].mx, t[u << 1 | 1].mx); }

 public:
  void build(int u, int L, int R) {
    t[u].mx = t[u].add = 0;
    if (L == R) {
      t[u].mx = n - L;
      return;
    }
    int mid = (L + R) >> 1;
    build(u << 1, L, mid);
    build(u << 1 | 1, mid + 1, R);
    update(u);
  }
  void Plus(int u, int L, int R, int l, int r, int d) {
    if (L >= l && R <= r) {
      t[u].Add(d);
      return;
    }
    pushdown(u);
    int mid = (L + R) >> 1;
    if (l <= mid) Plus(u << 1, L, mid, l, r, d);
    if (r > mid) Plus(u << 1 | 1, mid + 1, R, l, r, d);
    update(u);
  }
  int get_ans() { return t[1].mx; }
} T;
void Solve() {
  cin >> n >> m;
  len = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    c[++len] = a[i];
    p[i] = i;
  }
  for (int i = 1; i <= m; ++i) {
    cin >> b[i];
    c[++len] = b[i];
  }
  sort(c + 1, c + len + 1);
  len = unique(c + 1, c + len + 1) - c - 1;
  for (int i = 1; i <= n; ++i) {
    a[i] = lower_bound(c + 1, c + len + 1, a[i]) - c;
  }
  for (int i = 1; i <= m; ++i) {
    b[i] = lower_bound(c + 1, c + len + 1, b[i]) - c;
  }
  ans = 1LL * m * (m - 1) / 2;
  B.Clear(len);
  for (int i = 1; i <= n; ++i) {
    ans += B.Ask(a[i]);
    B.Add(a[i], 1);
  }
  sort(b + 1, b + m + 1);
  sort(p + 1, p + n + 1, [&](int i, int j) { return a[i] < a[j]; });
  T.build(1, 0, n);
  for (int i = 1, j = 1, k = 1; i <= m; ++i) {
    while (j <= n && a[p[j]] <= b[i]) T.Plus(1, 0, n, p[j], n, 1), ++j;
    while (k <= n && a[p[k]] < b[i]) T.Plus(1, 0, n, 0, p[k] - 1, -1), ++k;
    ans += T.get_ans();
  }
  cout << 1LL * (n + m) * (n + m - 1) / 2 - ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) Solve();
  return 0;
}
