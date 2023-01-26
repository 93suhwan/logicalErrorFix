#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using VI = vector<int>;
void prec() {}
inline void umin(int &a, int b) { a = min(a, b); }
inline void umax(int &a, int b) { a = max(a, b); }
void solve(istream &cin, ostream &cout) {
  int n, m;
  cin >> n >> m;
  vector<VI> grid(n, VI(m));
  for (auto &row : grid)
    for (auto &cell : row) cin >> cell;
  VI idxs(n);
  iota((idxs).begin(), (idxs).end(), 0);
  sort((idxs).begin(), (idxs).end(),
       [&](int i, int j) { return grid[i][0] > grid[j][0]; });
  sort((grid).begin(), (grid).end(),
       [](const VI &a, const VI &b) { return a[0] > b[0]; });
  vector<VI> lmin(n, VI(m)), rmin(n, VI(m));
  vector<VI> lmax(n, VI(m)), rmax(n, VI(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      lmin[i][j] = grid[i][j];
      if (i) umin(lmin[i][j], lmin[i - 1][j]);
      if (j) umin(lmin[i][j], lmin[i][j - 1]);
    }
    for (int j = m - 1; j >= 0; j--) {
      rmax[i][j] = grid[i][j];
      if (i) umax(rmax[i][j], rmax[i - 1][j]);
      if (j + 1 < m) umax(rmax[i][j], rmax[i][j + 1]);
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < m; j++) {
      lmax[i][j] = grid[i][j];
      if (i + 1 < n) umax(lmax[i][j], lmax[i + 1][j]);
      if (j) umax(lmax[i][j], lmax[i][j - 1]);
    }
    for (int j = m - 1; j >= 0; j--) {
      rmin[i][j] = grid[i][j];
      if (i + 1 < n) umin(rmin[i][j], rmin[i + 1][j]);
      if (j + 1 < m) umin(rmin[i][j], rmin[i][j + 1]);
    }
  };
  ;
  ;
  ;
  ;
  for (int i = 0; i + 1 < n; i++) {
    for (int j = 0; j + 1 < m; j++) {
      if (lmin[i][j] > lmax[i + 1][j] && rmin[i + 1][j + 1] > rmax[i][j + 1]) {
        cout << "YES\n";
        string col(n, 'B');
        for (int k = 0; k <= i; k++) col[idxs[k]] = 'R';
        cout << col << ' ' << (j + 1) << '\n';
        return;
      }
    }
  }
  cout << "NO\n";
}
struct DRedBlueMatrix {
  int case_num = 0;
  void solve(std::istream &in, std::ostream &out) { ::solve(in, out); }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  prec();
  DRedBlueMatrix solver;
  std::istream &in(std::cin);
  std::ostream &out(std::cout);
  int n;
  in >> n;
  for (int i = 0; i < n; ++i) {
    solver.solve(in, out);
  }
  return 0;
}
