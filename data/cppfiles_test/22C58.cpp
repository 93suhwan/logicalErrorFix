#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vpii = vector<pii>;
using ll = long long;
using vll = vector<long long>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
template <class T>
using min_queue = priority_queue<T, vector<T>, greater<T>>;
template <class T>
istream &operator>>(istream &, vector<T> &);
template <class T>
ostream &operator<<(ostream &, const vector<T> &);
template <class T, class U>
istream &operator>>(istream &, pair<T, U> &);
template <class T, class U>
ostream &operator<<(ostream &, const pair<T, U> &);
template <class T = int>
constexpr T INFTY = numeric_limits<T>::has_infinity
                        ? numeric_limits<T>::infinity()
                        : numeric_limits<T>::max();
template <>
constexpr int INFTY<int> = 0x3f3f3f3f;
template <>
constexpr ll INFTY<ll> = 0x3f3f3f3f3f3f3f3fLL;
template <class T, class U>
constexpr pair<T, U> INFTY<pair<T, U>> = make_pair(INFTY<T>, INFTY<U>);
constexpr int INF = INFTY<>;
constexpr ll BINF = INFTY<ll>;
struct Solver {
  Solver() {}
  int solve();
};
template <class T>
class DiffArray : public vector<T> {
 public:
  template <class... Args>
  DiffArray(Args &&...args) : vector<T>(forward<Args>(args)...) {}
  void modify(int l, int r, int v) {
    if (l > r) return;
    (*this)[l] += v;
    if (r + 1 < int(this->size())) (*this)[r + 1] -= v;
  }
  vector<T> build() {
    vector<T> res(this->size());
    partial_sum(this->begin(), this->end(), res.begin());
    return res;
  }
};
int Solver::solve() {
  int n, m;
  cin >> n >> m;
  vpii xy(n);
  cin >> xy;
  const int M = 320;
  DiffArray<int> ans(m);
  vvi store(M, vi(M));
  vi lst(n);
  for (int i = 0; i < m; i++) {
    int op, k;
    cin >> op >> k;
    k--;
    int v = op == 1 ? 1 : -1;
    auto [xk, yk] = xy[k];
    int off = op == 1 ? i : lst[k];
    if (xk + yk < M) {
      for (int j = 0; j < yk; j++) {
        store[xk + yk][(off + xk + j) % (xk + yk)] += v;
      }
    } else {
      for (int j = off; j + xk < m; j += xk + yk) {
        ans.modify(max(i, j + xk), j + xk + yk - 1, v);
      }
    }
    for (int md = 2; md < M; md++) ans.modify(i, i, store[md][i % md]);
    lst[k] = i;
  }
  vi rans = ans.build();
  for (int x : rans) cout << x << '\n';
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solver solver;
  solver.solve();
  return 0;
}
template <class T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto it = v.begin(); it != v.end(); ++it) is >> *it;
  return is;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (auto it = v.begin(); it != v.end();)
    os << *it, os << " \n"[++it == v.end()];
  return os;
}
template <class T, class U>
istream &operator>>(istream &is, pair<T, U> &p) {
  return is >> p.first >> p.second;
}
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  return os << p.first << ' ' << p.second;
}
