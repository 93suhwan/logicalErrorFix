#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
const int inf = 1e9 + 9;
int n, m;
int a[maxn][maxn];
int sq(int x) { return x * x; }
struct line {
  int a, b;
  line() {}
  line(int _a, int _b) : a(_a), b(_b) {}
  int eval(int x) { return sq(x) - 2 * x * a + b; }
};
bool bad(line d1, line d2, line d3) {
  double x12 = (double)(d2.b - d1.b) / (d2.a - d1.a) * 2;
  double x23 = (double)(d3.b - d2.b) / (d3.a - d2.a) * 2;
  return x12 > x23;
}
struct convex_hull_trick {
  int ptr;
  vector<line> hull;
  convex_hull_trick() {
    ptr = 0;
    hull.clear();
  }
  void add(line d) {
    while ((int)hull.size() >= 2 &&
           bad(hull[(int)hull.size() - 2], hull.back(), d)) {
      hull.pop_back();
    }
    hull.push_back(d);
  }
  int query(int x) {
    if (ptr >= (int)hull.size()) return inf;
    while (ptr + 1 < (int)hull.size() &&
           hull[ptr + 1].eval(x) < hull[ptr].eval(x)) {
      ++ptr;
    }
    return hull[ptr].eval(x);
  }
} cht;
int f[maxn][maxn], g[maxn][maxn];
int lst[maxn];
void read_input() {
  cin >> n >> m;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      char c;
      cin >> c;
      a[i][j] = (c == '1' ? 1 : 0);
    }
  }
}
void solve() {
  fill(lst, lst + n + 1, -1);
  for (int y = 0; y <= m; ++y) {
    for (int x = 0; x <= n; ++x) {
      if (a[x][y] == 1) lst[x] = y;
    }
    cht = convex_hull_trick();
    for (int x = 0; x <= n; ++x) {
      if (lst[x] == -1) continue;
      cht.add(line(x, sq(lst[x] - y) + sq(x)));
    }
    for (int x = 0; x <= n; ++x) {
      f[x][y] = cht.query(x);
    }
  }
  for (int y = 0; y <= m / 2; ++y) {
    for (int x = 0; x <= n; ++x) {
      if (y == m - y) continue;
      swap(a[x][y], a[x][m - y]);
    }
  }
  fill(lst, lst + n + 1, -1);
  for (int y = 0; y <= m; ++y) {
    for (int x = 0; x <= n; ++x) {
      if (a[x][y] == 1) lst[x] = y;
    }
    cht = convex_hull_trick();
    for (int x = 0; x <= n; ++x) {
      if (lst[x] == -1) continue;
      cht.add(line(x, sq(lst[x] - y) + sq(x)));
    }
    for (int x = 0; x <= n; ++x) {
      g[x][m - y] = cht.query(x);
    }
  }
  long long ans = 0;
  for (int x = 0; x <= n; ++x) {
    for (int y = 0; y <= m; ++y) {
      ans += min(f[x][y], g[x][y]);
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  read_input();
  solve();
}
