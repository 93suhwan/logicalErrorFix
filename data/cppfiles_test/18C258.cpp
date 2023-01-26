#include <bits/stdc++.h>
using namespace std;
template <class T>
int size(const T& x) {
  return x.size();
}
const int INF_INT = numeric_limits<int>::max();
void CMaximizeTheIntersections(std::istream& in, std::ostream& out) {
  int n, k;
  in >> n >> k;
  vector<int> x(k), y(k);
  vector<pair<int, int> > chords(k);
  vector<int> occ(2 * n, 0);
  for (int i = 0; i < k; i++) {
    in >> x[i] >> y[i];
    x[i]--;
    y[i]--;
    if (x[i] > y[i]) swap(x[i], y[i]);
    chords[i] = {x[i], y[i]};
    occ[x[i]] = occ[y[i]] = 1;
  }
  vector<int> mapfree;
  for (int i = 0; i < 2 * n; i++) {
    if (!occ[i]) mapfree.push_back(i);
  }
  for (int i = 0; i < (n - k); i++) {
    chords.push_back({mapfree[i], mapfree[i + (n - k)]});
  }
  auto chords_conn = [&](pair<int, int> c1, pair<int, int> c2) {
    if (c1.first > c2.first) swap(c1, c2);
    int c1x = c1.first, c1y = c1.second;
    int c2x = c2.first, c2y = c2.second;
    if (c2x < c1y && c2y > c1y)
      return true;
    else
      return false;
  };
  int ret = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; ++j) ret += chords_conn(chords[i], chords[j]);
  out << ret << '\n';
}
struct Solver {
  void solve(std::istream& in, std::ostream& out) {
    return CMaximizeTheIntersections(in, out);
  }
};
int main() {
  std::ios_base::sync_with_stdio(false), std::cin.tie(NULL),
      std::cout.tie(NULL);
  Solver solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  int n;
  in >> n;
  for (int i = 0; i < n; ++i) {
    solver.solve(in, out);
  }
  return 0;
}
