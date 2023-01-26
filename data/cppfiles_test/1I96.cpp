#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int FFTMOD = 119 << 23 | 1;
const int INF = (int)1e9 + 23111992;
const long long LINF = (long long)1e18 + 23111992;
const long double PI = acos((long double)-1);
const long double EPS = 1e-9;
inline long long gcd(long long a, long long b) {
  long long r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
inline long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
inline long long fpow(long long n, long long k, int p = MOD) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
template <class T>
inline int chkmin(T& a, const T& val) {
  return val < a ? a = val, 1 : 0;
}
template <class T>
inline int chkmax(T& a, const T& val) {
  return a < val ? a = val, 1 : 0;
}
inline unsigned long long isqrt(unsigned long long k) {
  unsigned long long r = sqrt(k) + 1;
  while (r * r > k) r--;
  return r;
}
inline long long icbrt(long long k) {
  long long r = cbrt(k) + 1;
  while (r * r * r > k) r--;
  return r;
}
inline void addmod(int& a, int val, int p = MOD) {
  if ((a = (a + val)) >= p) a -= p;
}
inline void submod(int& a, int val, int p = MOD) {
  if ((a = (a - val)) < 0) a += p;
}
inline int mult(int a, int b, int p = MOD) { return (long long)a * b % p; }
inline int inv(int a, int p = MOD) { return fpow(a, p - 2, p); }
inline int sign(long double x) { return x < -EPS ? -1 : x > +EPS; }
inline int sign(long double x, long double y) { return sign(x - y); }
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int mrand() { return abs((int)mt()); }
inline int mrand(int k) { return abs((int)mt()) % k; }
struct point_t {
  double x, y;
  point_t() : x(0), y(0) {}
  point_t(double x, double y) : x(x), y(y) {}
  point_t(const point_t& p) : x(p.x), y(p.y) {}
  int operator<(const point_t& rhs) const {
    return make_pair(y, x) < make_pair(rhs.y, rhs.x);
  }
  int operator==(const point_t& rhs) const {
    return make_pair(y, x) == make_pair(rhs.y, rhs.x);
  }
  point_t operator+(const point_t& p) const {
    return point_t(x + p.x, y + p.y);
  }
  point_t operator-(const point_t& p) const {
    return point_t(x - p.x, y - p.y);
  }
  point_t operator*(double c) const { return point_t(x * c, y * c); }
  point_t operator/(double c) const { return point_t(x / c, y / c); }
};
double cross(point_t p, point_t q) { return p.x * q.y - p.y * q.x; }
double area(point_t a, point_t b, point_t c) {
  return fabs(cross(a, b) + cross(b, c) + cross(c, a)) / 2;
}
double area2(point_t a, point_t b, point_t c) {
  return cross(a, b) + cross(b, c) + cross(c, a);
}
double dot(point_t p, point_t q) { return p.x * q.x + p.y * q.y; }
double dist(point_t p, point_t q) { return sqrt(dot(p - q, p - q)); }
double dist2(point_t p, point_t q) { return dot(p - q, p - q); }
point_t RotateCCW90(point_t p) { return point_t(-p.y, p.x); }
point_t RotateCW90(point_t p) { return point_t(p.y, -p.x); }
point_t RotateCCW(point_t p, double t) {
  return point_t(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t));
}
int sign(double x) { return x < -1e-9 ? -1 : x > 1e-9; }
int sign(double x, double y) { return sign(x - y); }
ostream& operator<<(ostream& os, const point_t& p) {
  os << "(" << p.x << "," << p.y << ")";
  return os;
}
vector<point_t> CircleLineIntersection(point_t a, point_t b, point_t c,
                                       double r) {
  vector<point_t> res;
  b = b - a;
  a = a - c;
  double A = dot(b, b);
  double B = dot(a, b);
  double C = dot(a, a) - r * r;
  double D = B * B - A * C;
  if (D < -1e-9) return res;
  res.push_back(c + a + b * (-B + sqrt(D + 1e-9)) / A);
  if (D > 1e-9) res.push_back(c + a + b * (-B - sqrt(D)) / A);
  if (int((res).size()) == 1) res.push_back(res[0]);
  return res;
}
void chemthan() {
  int n, k;
  cin >> n >> k;
  vector<pair<point_t, point_t>> lines;
  for (int i = (0); i < (n); ++i) {
    int x, y;
    cin >> x >> y;
    if (make_pair(x, y) == make_pair(0, 0)) {
      k--;
    } else {
      auto p = point_t(x, y);
      auto q = p / 2;
      auto v = RotateCCW90(p);
      lines.push_back({q, q + v});
    }
  }
  double lo = 0, hi = 2e5;
  for (int it = (0); it < (75); ++it) {
    double mi = (lo + hi) / 2;
    vector<pair<double, int>> events;
    for (auto line : lines) {
      auto pts = CircleLineIntersection(line.first, line.second, point_t(), mi);
      if (int((pts).size())) {
        if (0 < cross(pts[1], pts[0])) {
          swap(pts[0], pts[1]);
        }
        double l = atan2(pts[0].y, pts[0].x);
        double r = atan2(pts[1].y, pts[1].x);
        if (sign(l, r) <= 0) {
          if (l < r) {
            events.push_back({l, +1});
            events.push_back({r, -1});
          }
        } else {
          events.push_back({l, +1});
          events.push_back({0, +1});
          events.push_back({r, -1});
        }
      }
    }
    sort((events).begin(), (events).end());
    int cnt = 0;
    int found = k <= cnt;
    for (auto [x, s] : events) {
      cnt += s;
      if (k <= cnt) {
        found = 1;
        break;
      }
    }
    if (!found) {
      lo = mi;
    } else {
      hi = mi;
    }
  }
  cout << fixed << setprecision(9) << lo << "\n";
}
int32_t main(int32_t argc, char* argv[]) {
  ios_base::sync_with_stdio(0), cin.tie(0);
  if (argc > 1) {
    assert(freopen(argv[1], "r", stdin));
  }
  if (argc > 2) {
    assert(freopen(argv[2], "wb", stdout));
  }
  chemthan();
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
