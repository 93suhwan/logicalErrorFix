#include <bits/stdc++.h>
using namespace std;
template <typename A>
using VE = vector<A>;
template <typename A>
using USET = unordered_set<A>;
template <typename A>
using HEAP = priority_queue<A>;
template <typename A, typename B>
using PA = pair<A, B>;
template <typename A, typename B>
using UMAP = unordered_map<A, B>;
template <typename A>
using RHEAP = priority_queue<A, vector<A>, greater<A> >;
template <typename A>
A MAX(const A &a) {
  return a;
}
template <typename A>
A MIN(const A &a) {
  return a;
}
template <typename A>
A MAX(const A *a, const A *b) {
  return *max_element(a, b);
}
template <typename A>
A MIN(const A *a, const A *b) {
  return *min_element(a, b);
}
template <typename A, typename... B>
A MAX(const A &a, const B &...b) {
  return max(a, MAX(b...));
}
template <typename A, typename... B>
A MIN(const A &a, const B &...b) {
  return min(a, MIN(b...));
}
template <typename A, typename B = typename std::iterator_traits<A>::value_type>
B MAX(A a, A b) {
  return *max_element(a, b);
}
template <typename A, typename B = typename std::iterator_traits<A>::value_type>
B MIN(A a, A b) {
  return *min_element(a, b);
}
const int N = 100010, M = 1010;
class Dsu {
 public:
  vector<int> p, sz;
  int n;
  Dsu(int _n) {
    n = _n + 1;
    p.resize(n);
    sz.assign(n, 1);
    iota(p.begin(), p.end(), 0);
  }
  inline int get(int x) { return (x == p[x] ? x : (p[x] = get(p[x]))); }
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      sz[y] += sz[x];
      return true;
    }
    return false;
  }
  inline int getSize(int x) { return sz[x]; }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  Dsu d1(n), d2(n);
  for (int i = 0; i < m1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    d1.unite(a, b);
  }
  for (int i = 0; i < m2; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    d2.unite(a, b);
  }
  vector<pair<int, int> > res;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      if (d1.get(i) != d1.get(j) && d2.get(i) != d2.get(j)) {
        d1.unite(i, j);
        d2.unite(i, j);
        res.emplace_back(i, j);
      }
    }
  cout << ((int)res.size()) << '\n';
  for (auto &[x, y] : res) cout << x + 1 << ' ' << y + 1 << '\n';
  return 0;
}
