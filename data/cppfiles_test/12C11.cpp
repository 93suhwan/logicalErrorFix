#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using VI = vector<int>;
using dbl = double;
const dbl INF = 1e16;
struct HullDynamic {
  struct Line {
    int a;
    ll b, val = 0;
    dbl xLeft = -INF;
    bool type = false;
    explicit Line(int a = 0, ll b = 0) : a(a), b(b) {}
    ll eval(int x) const { return a * 1ll * x + b; }
    bool operator<(const Line &l2) const {
      return l2.type ? (xLeft > l2.val) : (a < l2.a);
    }
  };
  using Iter = set<Line>::iterator;
  static bool parallel(const Line &l1, const Line &l2) { return l1.a == l2.a; }
  dbl meetX(const Line &l1, const Line &l2) {
    return parallel(l1, l2) ? INF : (l2.b - l1.b) / (dbl(l1.a - l2.a));
  }
  set<Line> hull;
  bool hasPrev(Iter it) const { return it != hull.begin(); }
  bool hasNext(Iter it) const {
    return it != hull.end() && next(it) != hull.end();
  }
  bool bad(const Line &l1, const Line &l2, const Line &l3) {
    return meetX(l1, l3) <= meetX(l1, l2);
  }
  bool bad(Iter it) {
    return hasPrev(it) && hasNext(it) && (bad(*next(it), *it, *prev(it)));
  }
  Iter upd_left_border(Iter it) {
    if (!hasNext(it)) return it;
    dbl val = meetX(*it, *next(it));
    Line buf(*it);
    it = hull.erase(it);
    buf.xLeft = val;
    return hull.insert(it, buf);
  }
  void insert_line(int a, ll b) {
    Line l3 = Line(a, b);
    auto it = hull.lower_bound(l3);
    if (it != hull.end() && parallel(*it, l3)) {
      if (it->b <= b) return;
      it = hull.erase(it);
    }
    it = hull.insert(it, l3);
    if (bad(it)) {
      hull.erase(it);
      return;
    }
    while (hasPrev(it) && bad(prev(it))) hull.erase(prev(it));
    while (hasNext(it) && bad(next(it))) hull.erase(next(it));
    it = upd_left_border(it);
    if (hasPrev(it)) upd_left_border(prev(it));
    if (hasNext(it)) upd_left_border(next(it));
  }
  ll eval(int x) {
    Line q;
    q.val = x;
    q.type = true;
    auto best = hull.lower_bound(q);
    return (best == hull.end()) ? INF : best->eval(x);
  }
};
void prec() {}
const int N = 2005;
char grid[N][N];
int lt[N][N], rt[N][N];
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i <= n; i++) cin >> grid[i];
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      lt[i][j] = j ? lt[i][j - 1] : -1;
      if (grid[i][j] == '1') lt[i][j] = j;
    }
    for (int j = m; j >= 0; j--) {
      rt[i][j] = j == m ? N : rt[i][j + 1];
      if (grid[i][j] == '1') rt[i][j] = j;
    }
  }
  ll ans = 0;
  for (int y = 0; y <= m; y++) {
    ll cur = 0;
    HullDynamic hull;
    for (int x = 0; x <= n; x++) {
      for (int yy : {lt[x][y], rt[x][y]}) {
        if (0 <= yy && yy <= m)
          hull.insert_line(-2 * x, x * x + (y - yy) * (y - yy));
      }
    }
    for (int x = 0; x <= n; x++) {
      cur += x * x + hull.eval(x);
    }
    ans += cur;
  }
  cout << ans << endl;
}
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  prec();
  int t = 1;
  for (int it = 1; it <= t; it++) {
    solve();
  }
  return 0;
}
