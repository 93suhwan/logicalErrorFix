#include <bits/stdc++.h>
using ll = long long;
using namespace std;
template <class T>
T power(T x, long long e) {
  T res = 1;
  for (; e > 0; e /= 2) {
    if (e & 1) res = res * x;
    x = x * x;
  }
  return res;
}
template <int P>
struct mod {
  int x;
  mod(int v = 0) : x(v < 0 ? v + P : v) {}
  mod operator-() { return P - x; }
  mod inv() {
    assert(x != 0);
    return power(*this, P - 2);
  }
  void operator+=(mod o) { *this = *this + o; }
  void operator-=(mod o) { *this = *this - o; }
  void operator*=(mod o) { *this = *this * o; }
  void operator/=(mod o) { *this = *this * o.inv(); }
  mod operator*(mod o) { return int(1ll * x * o.x % P); }
  mod operator/(mod o) { return *this * o.inv(); }
  mod operator+(mod o) { return x + o.x < P ? x + o.x : x + o.x - P; }
  mod operator-(mod o) { return 0 <= x - o.x ? x - o.x : x - o.x + P; }
  friend ostream &operator<<(ostream &os, const mod &n) { return os << n.x; }
  friend istream &operator>>(istream &is, mod &n) { return is >> n.x; }
};
using Z = mod<998244353>;
struct work {
  int n, cnt_bad, empty_rows;
  int par[1 << 20][2][2];
  map<pair<int, int>, int> m;
  void init(int N) { n = empty_rows = N; }
  int bad(int i) {
    return (par[i][0][0] && par[i][0][1]) || (par[i][1][0] && par[i][1][1]) ||
           (par[i][0][0] && par[i][1][0]) || (par[i][0][1] && par[i][1][1]);
  }
  int empty(int i) {
    return ((par[i][0][0] + par[i][0][1] + par[i][1][0] + par[i][1][1]) == 0);
  }
  void add(int i, int j, int add) {
    cnt_bad -= bad(i);
    empty_rows -= empty(i);
    if (m.count(make_pair(i, j))) {
      par[i][j % 2][m[make_pair(i, j)]] -= 1;
    }
    if (add == -1) m.erase(make_pair(i, j));
    if (add == 0) {
      m[make_pair(i, j)] = 0;
      par[i][j % 2][0]++;
    }
    if (add == 1) {
      m[make_pair(i, j)] = 1;
      par[i][j % 2][1]++;
    }
    cnt_bad += bad(i);
    empty_rows += empty(i);
  }
  Z res() {
    if (cnt_bad) return 0;
    return power(Z(2), empty_rows);
  }
};
int n, m, k;
work A, B;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> k;
  A.init(n);
  B.init(m);
  while (k--) {
    int x, y, add;
    cin >> x >> y >> add;
    A.add(x, y, add);
    B.add(y, x, add);
    Z res = A.res() + B.res();
    if (A.cnt_bad == 0 && B.cnt_bad == 0) {
      res -= 1;
      if (A.empty_rows == n) res -= 1;
    }
    cout << res << '\n';
  }
  return 0;
}
