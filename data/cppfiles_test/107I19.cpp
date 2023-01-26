#include <bits/stdc++.h>
using namespace std;
const int IINF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const double DINF = numeric_limits<double>::infinity();
const double DNAN = numeric_limits<double>::quiet_NaN();
const double EPS = 1e-9;
const double PI = acos((double)-1.0);
const int DX[] = {1, 0, -1, 0, 1, -1, 1, -1};
const int DY[] = {0, 1, 0, -1, 1, -1, -1, 1};
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long sqr(long long x) { return x * x; }
long long sqr(int x) { return (long long)x * x; }
double sqr(double x) { return x * x; }
mt19937 mmtw(960172);
long long rnd(long long x, long long y) {
  static uniform_int_distribution<long long> d;
  return d(mmtw) % (y - x + 1) + x;
}
template <typename T, typename M>
T& updMin(T& a, M const& b) {
  if (b < a) a = b;
  return a;
}
template <typename T, typename M>
T& updMax(T& a, M const& b) {
  if (a < b) a = b;
  return a;
}
long long divFloor(long long a, long long b) {
  if (b < 0) {
    a = -a;
    b = -b;
  }
  return a >= 0 ? a / b : (a - b + 1) / b;
}
long long divCeil(long long a, long long b) {
  if (b < 0) {
    a = -a;
    b = -b;
  }
  return a >= 0 ? (a + b - 1) / b : a / b;
}
long long divFloorS(long long a, long long b) {
  if (b < 0) {
    a = -a;
    b = -b;
  }
  return a >= 0 ? (a + b - 1) / b - 1 : a / b - 1;
}
long long divCeilS(long long a, long long b) {
  if (b < 0) {
    a = -a;
    b = -b;
  }
  return a >= 0 ? a / b + 1 : (a - b + 1) / b + 1;
}
template <typename K, typename V>
V getOrDef(map<K, V> const& a, K const& k, V const& def = V()) {
  auto it = a.find(k);
  return it == a.end() ? def : it->second;
}
template <typename K, typename V>
V getOrDef(unordered_map<K, V> const& a, K const& k, V const& def = V()) {
  auto it = a.find(k);
  return it == a.end() ? def : it->second;
}
template <typename A, typename B>
istream& operator>>(istream& in, pair<A, B>& p) {
  return in >> p.first >> p.second;
}
template <typename A, typename B>
ostream& operator<<(ostream& out, pair<A, B> const& p) {
  return out << p.first << " " << p.second;
}
template <typename T>
istream& operator>>(istream& in, vector<T>& a) {
  for (T& x : a) in >> x;
  return in;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T> const& a) {
  bool f = true;
  for (T const& x : a) {
    if (!f) out << " ";
    f = false;
    out << x;
  }
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, vector<vector<T>> const& a) {
  for (vector<T> const& x : a) out << x << "\n";
  return out;
}
template <typename T>
bool isZero(T const& x) {
  return x == T(0);
}
bool isZero(float x) { return abs(x) < EPS; }
bool isZero(double x) { return abs(x) < EPS; }
bool isZero(long double x) { return abs(x) < EPS; }
template <typename T>
int sgn(T const& x) {
  if (isZero(x)) return 0;
  return x > 0 ? 1 : -1;
}
template <typename T>
struct Vec2 {
  T x, y;
  Vec2() {}
  Vec2(T nx, T ny) : x(nx), y(ny) {}
  template <typename M>
  Vec2(Vec2<M> const& b) : x(T(b.x)), y(T(b.y)) {}
  Vec2 operator-() const { return {-x, -y}; }
  Vec2 operator+(Vec2 const& b) const { return {x + b.x, y + b.y}; }
  Vec2 operator-(Vec2 const& b) const { return {x - b.x, y - b.y}; }
  Vec2 operator*(T b) const { return {x * b, y * b}; }
  Vec2 operator/(T b) const { return {x / b, y / b}; }
  Vec2& operator+=(Vec2 const& b) {
    x += b.x;
    y += b.y;
    return *this;
  }
  Vec2& operator-=(Vec2 const& b) {
    x -= b.x;
    y -= b.y;
    return *this;
  }
  Vec2& operator*=(T b) {
    x *= b;
    y *= b;
    return *this;
  }
  Vec2& operator/=(T b) {
    x /= b;
    y /= b;
    return *this;
  }
  bool operator==(Vec2 const& b) const { return x == b.x && y == b.y; }
  bool operator!=(Vec2 const& b) const { return x != b.x && y != b.y; }
  bool operator<(Vec2 const& b) const { return x == b.x ? y < b.y : x < b.x; }
  bool operator<=(Vec2 const& b) const { return !(b < *this); }
  bool operator>(Vec2 const& b) const { return b < *this; }
  bool operator>=(Vec2 const& b) const { return !(*this < b); }
};
template <typename T>
typename enable_if<numeric_limits<T>::is_integer, Vec2<T>>::type operator%(
    Vec2<T> const& a, T b) {
  return {a.x % b, a.y % b};
}
template <typename T>
typename enable_if<numeric_limits<T>::is_integer, Vec2<T>&>::type operator%=(
    Vec2<T>& a, T b) {
  a.x %= b;
  a.y %= b;
  return a;
}
template <typename T>
istream& operator>>(istream& in, Vec2<T>& v) {
  return in >> v.x >> v.y;
}
template <typename T>
ostream& operator<<(ostream& out, Vec2<T> const& v) {
  return out << v.x << " " << v.y;
}
template <typename T>
Vec2<T> operator*(T b, Vec2<T> const& a) {
  return a * b;
}
template <typename T>
T dot(Vec2<T> const& a, Vec2<T> const& b) {
  return a.x * b.x + a.y * b.y;
}
template <typename T>
T cross(Vec2<T> const& a, Vec2<T> const& b) {
  return a.x * b.y - a.y * b.x;
}
template <typename T>
T length2(Vec2<T> const& a) {
  return a.x * a.x + a.y * a.y;
}
template <typename T>
Vec2<T> rotate90(Vec2<T> const& a) {
  return {-a.y, a.x};
}
template <typename T>
typename enable_if<!numeric_limits<T>::is_integer, Vec2<T>>::type normalize(
    Vec2<T> const& a) {
  return a / sqrt(a.x * a.x + a.y * a.y);
}
template <typename T>
typename enable_if<!numeric_limits<T>::is_integer, Vec2<T>>::type rotate(
    Vec2<T> const& a, T b) {
  T c = cos(b), s = sin(b);
  return {a.x * c - a.y * s, a.y * c + a.x * s};
}
template <typename T>
typename enable_if<!numeric_limits<T>::is_integer, Vec2<T>>::type ang2vec(T a) {
  return {cos(a), sin(a)};
}
template <typename T>
using myDouble =
    typename conditional<numeric_limits<T>::is_integer, double, T>::type;
template <typename T, typename D = myDouble<T>>
D getAngle(Vec2<T> const& a) {
  return atan2((D)a.y, (D)a.x);
}
template <typename T, typename D = myDouble<T>>
D length(Vec2<T> const& a) {
  return sqrt((D)a.x * a.x + (D)a.y * a.y);
}
template <typename T>
bool cmpAng(Vec2<T> const& v1, Vec2<T> const& v2) {
  bool h1 = v1.y > 0 || (v1.y == 0 && v1.x > 0);
  bool h2 = v2.y > 0 || (v2.y == 0 && v2.x > 0);
  if (h1 != h2) return h1 > h2;
  return cross(v1, v2) > 0;
}
template <typename T>
typename enable_if<numeric_limits<T>::has_quiet_NaN, bool>::type isnan(
    Vec2<T> const& a) {
  return isnan(a.x) || isnan(a.y);
}
template <typename T>
typename enable_if<!numeric_limits<T>::has_quiet_NaN, bool>::type isnan(
    Vec2<T> const&) {
  return false;
}
template <typename T>
bool isZero(Vec2<T> const& a) {
  return isZero(a.x) && isZero(a.y);
}
int main() {
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  ++k;
  vector<Vec2<long long>> ps(n);
  cin >> ps;
  vector<long long> asum(n + 1, 0);
  for (int i = 0; i < n; ++i)
    asum[i + 1] = asum[i] + cross(ps[i], ps[(i + 1) % n]);
  auto check = [&](long long t) -> bool {
    vector<vector<pair<int, long long>>> d(
        n, vector<pair<int, long long>>(n, {-IINF, -LINF}));
    vector<vector<pair<int, long long>>> da(
        n, vector<pair<int, long long>>(n, {-IINF, -LINF}));
    for (int l = n - 1; l >= 0; --l) {
      for (int r = l + 1; r < n; ++r) {
        long long area = asum[r] - asum[l] + cross(ps[r], ps[l]);
        if (area == 0) {
          d[l][r] = {0, 0};
          da[l][r] = {0, 0};
          continue;
        }
        if (area >= t) {
          d[l][r] = {1, area};
        }
        da[l][r] = {1, area};
        if (r - l <= 2) continue;
        for (int v = l + 1; v < r; ++v) {
          long long triag =
              cross(ps[l], ps[v]) + cross(ps[v], ps[r]) + cross(ps[r], ps[l]);
          if (triag >= t) {
            updMax(d[l][r],
                   make_pair(d[l][v].first + d[v][r].first + 1, triag));
          }
          updMax(da[l][r], make_pair(d[l][v].first + d[v][r].first + 1, triag));
          if (l + 1 != v) {
            updMax(da[l][r], make_pair(da[l][v].first + d[v][r].first,
                                       triag + da[l][v].second));
          }
        }
        if (da[l][r].second >= t) updMax(d[l][r], da[l][r]);
      }
    }
    return d[0][n - 1].first >= k;
  };
  long long cl = 0, cr = 1e18;
  while (cr - cl > 1) {
    long long mid = (cl + cr) / 2;
    if (check(mid))
      cl = mid;
    else
      cr = mid;
  }
  cout << cl << "\n";
  return 0;
}
