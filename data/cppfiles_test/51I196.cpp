#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::system_clock().now().time_since_epoch().count());
int n, k, w[55][55], d[55], mn;
const double delta = 0.99996;
const double eps = 1e-6;
vector<pair<int, int> > E;
class Union_Set {
  int f[55];

 public:
  Union_Set(int n) {
    for (int i = 1; i <= n; ++i) f[i] = i;
  }
  inline int getf(int x) { return f[x] == x ? x : f[x] = getf(f[x]); }
  inline void Merge(int x, int y) {
    int fx = getf(x), fy = getf(y);
    if (fx ^ fy) f[fy] = fx;
  }
};
void SA(double beg) {
  for (double t = beg; t > eps; t *= delta) {
    Union_Set S(n);
    vector<pair<int, int> > G = E;
    G.erase(G.begin() + rnd() % (n - 1));
    static int _d[55];
    for (int i = 1; i <= n; ++i) _d[i] = 0;
    for (auto [u, v] : G) S.Merge(u, v), ++_d[u], ++_d[v];
    int x, y;
    do {
      x = rnd() % n + 1, y = rnd() % n + 1;
    } while (S.getf(x) == S.getf(y) || _d[x] + 1 > d[x] || _d[y] + 1 > d[y]);
    int nw = 0;
    G.emplace_back(x, y);
    for (auto [u, v] : G) nw += w[u][v];
    if (nw < mn) {
      E = G, mn = nw;
    } else if (exp((mn - nw) / t) > 1.0 * rnd() / rnd.max()) {
      E = G;
    }
  }
}
void Solve() {
  cin >> n >> k;
  for (int i = 1; i <= k; ++i) cin >> d[i];
  for (int i = k + 1; i <= n; ++i) d[i] = n;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      cin >> w[i][j];
      w[j][i] = w[i][j];
    }
  }
  for (int i = 1; i < n; ++i) {
    E.emplace_back(i, n);
    mn += w[i][n];
  }
  SA(1e6);
  cout << mn << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T = 1;
  while (T--) Solve();
  return 0;
}
