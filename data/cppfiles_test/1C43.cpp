#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = long double;
using str = string;
using pi = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T, size_t SZ>
using AR = array<T, SZ>;
using vi = V<int>;
using vb = V<bool>;
using vpi = V<pi>;
const int MOD = 1e9 + 7;
const db PI = acos((db)-1);
mt19937 rng(0);
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
template <class T, class U>
T fstTrue(T lo, T hi, U first) {
  ++hi;
  assert(lo <= hi);
  while (lo < hi) {
    T mid = lo + (hi - lo) / 2;
    first(mid) ? hi = mid : lo = mid + 1;
  }
  return lo;
}
using T = db;
const T EPS = 1e-9;
using P = pair<T, T>;
using vP = V<P>;
using Line = pair<P, P>;
int sgn(T a) { return (a > EPS) - (a < -EPS); }
T sq(T a) { return a * a; }
T norm(P p) { return sq(p.first) + sq(p.second); }
T abs(P p) { return sqrt(norm(p)); }
T arg(P p) { return atan2(p.second, p.first); }
P conj(P p) { return P(p.first, -p.second); }
P perp(P p) { return P(-p.second, p.first); }
P dir(T ang) { return P(cos(ang), sin(ang)); }
const int mx = 100005;
struct Eff {
  int n, k;
  P hab[mx];
  bool works(db r) {
    V<pair<db, int>> ch;
    for (int i = 1; i <= n; i++) {
      if (abs(hab[i]) <= 2.0 * r - EPS) {
        db theta_diff = PI / 2.0 - asin(abs(hab[i]) / 2.0 / r);
        db theta = arg(hab[i]);
        assert(theta_diff <= PI / 2.0);
        ch.push_back(make_pair(theta - theta_diff, +1));
        ch.push_back(make_pair(theta + theta_diff, -1));
        ch.push_back(make_pair(theta - theta_diff + 2 * PI, +1));
        ch.push_back(make_pair(theta + theta_diff + 2 * PI, -1));
      }
    }
    sort(begin(ch), end(ch));
    int running_sum = 0;
    for (auto u : ch) {
      running_sum += u.second;
      if (0 <= u.first && u.first <= 2 * PI) {
        if (running_sum >= k) return true;
      }
    }
    return false;
  }
  void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> hab[i].first >> hab[i].second;
    }
    db lo = EPS;
    db hi = 200005.0;
    for (int i = 0; i < 50; i++) {
      db mid = (lo + hi) / 2;
      if (works(mid)) {
        hi = mid;
      } else {
        lo = mid;
      }
    }
    cout << lo << "\n";
  }
};
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);
  Eff e;
  e.solve();
}
