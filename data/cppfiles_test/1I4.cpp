#include <bits/stdc++.h>
using namespace std;
namespace {
using T = long double;
constexpr char endl = '\n';
const int maxN = 2e5 + 5;
namespace {
const T eps = 1e-6;
const T inf = 1e18;
const T pi = acos(-1.0);
int sgn(T x) { return x < -eps ? -1 : (x > eps ? 1 : 0); }
T deg(T rad) { return rad / pi * 180.0; }
T rad(T deg) { return deg / 180.0 * pi; }
typedef struct V {
  T x, y;
  V operator+(const V& r) const { return {x + r.x, y + r.y}; }
  V operator-(const V& r) const { return {x - r.x, y - r.y}; }
  V operator*(T r) const { return {x * r, y * r}; }
  V operator/(T r) const { return {x / r, y / r}; }
  bool operator!=(const V& r) const { return sgn(x - r.x) || sgn(y - r.y); }
  bool operator==(const V& r) const { return !sgn(x - r.x) && !sgn(y - r.y); }
  bool operator<(const V& r) const {
    return sgn(x - r.x) == 0 ? sgn(y - r.y) < 0 : sgn(x - r.x) < 0;
  }
  friend istream& operator>>(istream& in, V& a) { return in >> a.x >> a.y; }
  friend ostream& operator<<(ostream& out, const V& a) {
    return out << '(' << a.x << ',' << a.y << ')';
  }
} P;
using S = vector<P>;
T dot(const V& a, const V& b) { return a.x * b.x + a.y * b.y; }
T dot(const P& a, const P& b, const P& o) { return dot(a - o, b - o); }
T len(const V& a) { return sqrt(dot(a, a)); }
T dist(const P& a, const P& b) { return len(a - b); }
V normalize(const V& a) { return a / len(a); }
T cross(const V& a, const V& b) { return a.x * b.y - a.y * b.x; }
T cross(const P& a, const P& b, const P& o) { return cross(a - o, b - o); }
P lerp(const P& a, const P& b, T t) { return a + (b - a) * t; }
T angle(const V& a) { return atan2(a.y, a.x); }
T angle(const V& a, const V& b) { return acos(dot(a, b) / len(a) / len(b)); }
T angle(const V& a, const V& b, const V& o) { return angle(a - o, b - o); }
V rotate(const V& a, T r) {
  return {a.x * cos(r) - a.y * sin(r), a.x * sin(r) + a.y * cos(r)};
}
P rotate(const P& p, const P& o, T r) { return rotate(p - o, r) + o; }
P rotate_acw_90(const V& v) { return {-v.y, v.x}; }
P rotate_cw_90(const V& v) { return {v.y, -v.x}; }
V normal(const V& v) { return normalize(rotate_acw_90(v)); }
int modi(int i, int n) {
  while (i < 0) i += n;
  while (i >= n) i -= n;
  return i;
}
template <class T>
T& at(T arr[], int n, int i) {
  return arr[modi(i, n)];
}
template <class T>
T& at(vector<T>& arr, int n, int i) {
  return arr[modi(i, n)];
}
}  // namespace
int n, k;
S s;
struct Seg {
  T l, r;
};
vector<Seg> segs;
vector<T> pos;
vector<T> d;
vector<int> f;
set<pair<int, int>> ps;
void add(T l, T r) {
  if (l > r) return add(l, pi * 2), add(0, r);
  pos.push_back(l), pos.push_back(r);
  segs.emplace_back(Seg{l, r});
}
void solve() {
  cin >> n >> k, s.resize(n), d.resize(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (ps.count(make_pair(x, y))) {
      i--, n--;
      continue;
    }
    ps.emplace(make_pair(x, y));
    s[i] = {(T)x, (T)y}, d[i] = len(s[i]) * 0.5;
  }
  T l = 0, r = 1e6, mid;
  while (r - l > eps) {
    mid = (l + r) * 0.5;
    segs.clear(), pos.clear(), f.clear();
    for (int i = 0; i < n; i++) {
      if (sgn(d[i] - mid) > 0) continue;
      if (!sgn(d[i])) add(0, pi * 2);
      V v = normal(s[i]);
      T t = sqrt(mid * mid - d[i] * d[i]);
      T ang_l = angle(s[i] * 0.5 - v * t) + pi;
      T ang_r = angle(s[i] * 0.5 + v * t) + pi;
      add(ang_l, ang_r);
    }
    sort(pos.begin(), pos.end());
    pos.erase(unique(pos.begin(), pos.end()), pos.end());
    f.resize(pos.size() + 5);
    for (auto& [l, r] : segs) {
      f[lower_bound(pos.begin(), pos.end(), l) - pos.begin()]++;
      f[upper_bound(pos.begin(), pos.end(), r) - pos.begin()]--;
    }
    int cnt = 0;
    for (int i = 1; i < f.size(); i++) cnt = max(cnt, f[i] += f[i - 1]);
    if (cnt >= k)
      r = mid;
    else
      l = mid;
  }
  cout << mid << endl;
}
}  // namespace
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t(1);
  cout << fixed << setprecision(8);
  for (int i = 1; i <= t; i++) solve();
}
