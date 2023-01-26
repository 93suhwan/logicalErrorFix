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
  int twon = 2 * n;
  vector<int> x(k), y(k);
  vector<pair<int, int> > chords;
  vector<int> occ(2 * n, 0);
  for (int i = 0; i < k; i++) {
    in >> x[i] >> y[i];
    x[i]--;
    y[i]--;
    if (x[i] > y[i]) swap(x[i], y[i]);
    chords.push_back({x[i], y[i]});
    occ[x[i]] = occ[y[i]] = 1;
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
  for (int i = 0; i < chords.size(); i++)
    for (int j = i + 1; j < chords.size(); ++j)
      ret += chords_conn(chords[i], chords[j]);
  std::function<int(int, int, int)> go = [&](int pos, int res, int cmpl) {
    if (pos == 2 * n) return res;
    if (occ[pos] == 1) return go(pos + 1, res, cmpl);
    vector<pair<int, int> > cands;
    for (int j = pos + 1; j < 2 * n; ++j) {
      if (occ[j] == 0) {
        int tadd = 0;
        for (int k = 0; k < cmpl; k++)
          tadd += chords_conn(chords[k], make_pair(pos, j));
        cands.push_back({tadd, j});
      }
    }
    sort(begin(cands), end(cands));
    reverse(begin(cands), end(cands));
    int tret = res;
    int maxval = cands[0].first;
    for (auto&& cand : cands) {
      if (cand.first != maxval) break;
      chords.push_back({pos, cand.second});
      occ[pos] = occ[cand.second] = 1;
      tret = max(tret, go(pos + 1, res + cand.first, cmpl + 1));
      occ[pos] = occ[cand.second] = 0;
      chords.pop_back();
    }
    return tret;
  };
  out << go(0, ret, chords.size()) << '\n';
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
