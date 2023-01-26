#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Vi = vector<int>;
using Pii = pair<int, int>;
int uplg(int n) { return 32 - __builtin_clz(n); }
int uplg(ll n) { return 64 - __builtin_clzll(n); }
void run();
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(12);
  run();
  cout << flush;
  _Exit(0);
}
template <class T, class S>
struct bvec2 {
  T first, second;
  S operator+(S r) const { return {first + r.first, second + r.second}; }
  S operator-(S r) const { return {first - r.first, second - r.second}; }
  S operator*(T r) const { return {first * r, second * r}; }
  S operator/(T r) const { return {first / r, second / r}; }
  T dot(S r) const { return first * r.first + second * r.second; }
  T cross(S r) const { return first * r.second - second * r.first; }
  T len2() const { return first * first + second * second; }
  double len() const { return hypot(first, second); }
  S perp() const { return {-second, first}; }
  pair<T, T> yx() const { return {second, first}; }
  double angle() const {
    double a = atan2(second, first);
    return (a < 0 ? a + 2 * M_PI : a);
  }
};
struct vec2i : bvec2<ll, vec2i> {
  vec2i() : bvec2{0, 0} {}
  vec2i(ll a, ll b) : bvec2{a, b} {}
  bool upper() const { return (second ?: first) >= 0; }
  int angleCmp(vec2i r) const {
    ll c = cross(r);
    return r.upper() - upper() ?: (c < 0) - (c > 0);
  }
  bool operator<(vec2i r) const {
    return (angleCmp(r) ?: len2() - r.len2()) < 0;
  }
  bool operator==(vec2i r) const {
    return first == r.first && second == r.second;
  }
  bool operator!=(vec2i r) const {
    return first != r.first || second != r.second;
  }
};
using vec2 = vec2i;
void run() {
  int n;
  cin >> n;
  int k;
  cin >> k;
  k--;
  vector<vec2> points(n);
  for (auto& p : (points)) cin >> p.first >> p.second;
  vector<vec2> line;
  vec2 dir, other;
  if (n == 3) {
    line.push_back(points[0]);
    line.push_back(points[1]);
    dir = points[1] - points[0];
    other = points[2];
  } else {
    for (int i = (0); i < (4); i++)
      for (int j = (i + 1); j < (4); j++)
        for (int l = (j + 1); l < (4); l++) {
          vec2 a = points[i], b = points[j], c = points[l];
          if ((b - a).cross(c - a) == 0) {
            for (auto& p : (points)) {
              if ((p - a).cross(b - a) == 0) {
                line.push_back(p);
              } else {
                other = p;
              }
            }
            dir = b - a;
            goto done;
          }
        }
    assert(0);
  done:;
    sort((line).begin(), (line).end(),
         [&](vec2 a, vec2 b) { return dir.dot(a) < dir.dot(b); });
  }
  double ans = 1e30;
  if (points[k] == other) {
    ans = (line.back() - line[0]).len() +
          min((other - line.back()).len(), (other - line[0]).len());
  } else {
    for (int t = (0); t < (2); t++) {
      int i = 0;
      while (line[i] != points[k]) i++;
      int start = i;
      for (; i < int((line).size()); i++) {
        double alt = 0;
        if (i + 1 < int((line).size())) {
          alt += (line.back() - line[i + 1]).len() +
                 min((line.back() - other).len(), (line[i + 1] - other).len());
        }
        double first = (line[start] - line[0]).len();
        double second = (line[start] - line[i]).len();
        alt += min(first * 2 + second + (line[i] - other).len(),
                   second * 2 + first + (line[0] - other).len());
        ans = min(ans, alt);
      }
      reverse((line).begin(), (line).end());
    }
  };
  cout << ans << '\n';
}
