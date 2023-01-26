#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using VI = vector<int>;
void prec() {}
using T = tuple<int, int, int, int>;
const int N = 2e5 + 5;
int sa[N], mm[N], x[N];
vector<int> ixs;
void clear(int w) {
  for (int i : ixs) x[i] = sa[i] - w;
  ixs.clear();
}
void solve(istream &cin, ostream &cout) {
  int n;
  cin >> n;
  vector<T> ranges;
  for (int i = 0; i < n; i++) {
    int a, b, m;
    cin >> a >> b >> m;
    const int w = a + b - m;
    const int lo = a - min(a, m);
    const int hi = a - max(0, m - b);
    ranges.emplace_back(w, hi, lo, i);
    sa[i] = a;
    mm[i] = m;
  }
  sort((ranges).begin(), (ranges).end());
  int pw = -1, r = -1, bal = 0;
  ixs.clear();
  for (auto [w, hi, lo, i] : ranges) {
    if (w != pw) {
      clear(r);
      pw = w;
      r = hi;
      ++bal;
    }
    if (lo > r) {
      clear(r);
      r = hi;
      bal++;
    }
    ixs.push_back(i);
  }
  clear(r);
  cout << bal << '\n';
  for (int i = 0; i < n; i++) {
    cout << x[i] << ' ' << (mm[i] - x[i]) << '\n';
  }
}
struct HBanquetPreparations2 {
  int case_num = 0;
  void solve(std::istream &in, std::ostream &out) { ::solve(in, out); }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  prec();
  HBanquetPreparations2 solver;
  std::istream &in(std::cin);
  std::ostream &out(std::cout);
  int n;
  in >> n;
  for (int i = 0; i < n; ++i) {
    solver.solve(in, out);
  }
  return 0;
}
