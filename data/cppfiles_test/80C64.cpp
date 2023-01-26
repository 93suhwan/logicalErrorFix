#include <bits/stdc++.h>
using namespace std;
void main0();
int main() {
  clock_t start, end;
  ios::sync_with_stdio(false);
  cin.tie(0);
  main0();
  return 0;
}
const int dx[8] = {0, 1, -1, 0, 1, 1, -1, -1};
const int dy[8] = {1, 0, 0, -1, 1, -1, -1, 1};
const int N = 1e6 + 5;
const int M = 1e5;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const double eps = 1e-6;
const double Pi = acos(-1.0);
mt19937 rnd(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
int n, m;
int a[N];
int b[N];
vector<pair<int, int> > v;
struct BIT {
  int n;
  int c[N];
  int lowbit(int x) { return x & (-x); }
  void init(int _n) {
    n = _n;
    for (int i = 1; i <= n; ++i) c[i] = 0;
  }
  void update(int i, int x) {
    while (i <= n) {
      c[i] += x;
      i += lowbit(i);
    }
  }
  int query(int i) {
    int ret = 0;
    while (i) {
      ret += c[i];
      i -= lowbit(i);
    }
    return ret;
  }
} bit;
struct SGT {
  struct node {
    int l, r, lc, rc;
    int v, tag;
  } t[N * 2];
  int cnt;
  void init(int n) {
    cnt = 0;
    for (int i = 1; i <= 2 * n; ++i) {
      t[i].l = t[i].r = t[i].lc = t[i].rc = t[i].v = t[i].tag = 0;
    }
  }
  void pushup(int u) { t[u].v = min(t[t[u].lc].v, t[t[u].rc].v); }
  void build(int l, int r) {
    int u = ++cnt;
    t[u].l = l, t[u].r = r;
    t[u].v = t[u].tag = 0;
    if (l == r) {
      t[u].v = 1;
    } else {
      t[u].lc = cnt + 1, build(l, ((t[u].l + t[u].r) / 2));
      t[u].rc = cnt + 1, build(((t[u].l + t[u].r) / 2) + 1, r);
      pushup(u);
    }
  }
  void apply(int u, int x) {
    t[u].v += x;
    t[u].tag += x;
  }
  void pushdown(int u) {
    apply(t[u].lc, t[u].tag);
    apply(t[u].rc, t[u].tag);
    t[u].tag = 0;
  }
  void update(int u, int l, int r, int x) {
    if ((l <= t[u].l) && (t[u].r <= r)) {
      apply(u, x);
    } else {
      pushdown(u);
      if (l <= ((t[u].l + t[u].r) / 2)) update(t[u].lc, l, r, x);
      if (((t[u].l + t[u].r) / 2) + 1 <= r) update(t[u].rc, l, r, x);
      pushup(u);
    }
  }
  int query(int u, int l, int r) {
    if ((l <= t[u].l) && (t[u].r <= r)) {
      return t[u].v;
    } else {
      pushdown(u);
      int ret = INF;
      if (l <= ((t[u].l + t[u].r) / 2)) ret = min(ret, query(t[u].lc, l, r));
      if (((t[u].l + t[u].r) / 2) + 1 <= r)
        ret = min(ret, query(t[u].rc, l, r));
      return ret;
    }
  }
} sgt;
void main0() {
  int T;
  cin >> T;
  while (T--) {
    v.clear();
    v.push_back({0, 0});
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      v.push_back({a[i], i});
    }
    for (int i = 1; i <= m; ++i) {
      cin >> b[i];
    }
    sort((v).begin(), (v).end());
    sort(b + 1, b + m + 1);
    long long ans = 0;
    bit.init(n);
    for (int i = n; i >= 1; --i) {
      int rk = lower_bound((v).begin(), (v).end(), (pair<int, int>){a[i], 0}) -
               v.begin();
      ans += bit.query(rk - 1);
      bit.update(rk, 1);
    }
    sgt.init(n);
    sgt.build(1, n);
    for (int i = 1; i <= n; ++i) {
      sgt.update(1, i, n, 1);
    }
    for (int i = 1; i <= m; ++i) {
      int l, r;
      l = lower_bound((v).begin(), (v).end(), (pair<int, int>){b[i - 1], INF}) -
          v.begin();
      r = lower_bound((v).begin(), (v).end(), (pair<int, int>){b[i], INF}) -
          v.begin();
      r--;
      for (int j = l; j <= r; ++j) {
        sgt.update(1, v[j].second, n, -1);
      }
      l = lower_bound((v).begin(), (v).end(), (pair<int, int>){b[i - 1], 0}) -
          v.begin();
      r = lower_bound((v).begin(), (v).end(), (pair<int, int>){b[i], 0}) -
          v.begin();
      r--;
      for (int j = l; j <= r; ++j) {
        sgt.update(1, v[j].second, n, -1);
      }
      ans += r + min(0, sgt.query(1, 1, n));
    }
    cout << ans << endl;
  }
}
