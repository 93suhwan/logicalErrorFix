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
  int x, y;
  point_t() : x(0), y(0) {}
  point_t(int x, int y) : x(x), y(y) {}
  point_t(const point_t& rhs) : x(rhs.x), y(rhs.y) {}
  int operator<(const point_t& rhs) const {
    return make_pair(y, x) < make_pair(rhs.y, rhs.x);
  }
  int operator==(const point_t& rhs) const {
    return make_pair(y, x) == make_pair(rhs.y, rhs.x);
  }
  int operator!=(const point_t& rhs) const {
    return make_pair(y, x) != make_pair(rhs.y, rhs.x);
  }
  point_t operator-(const point_t& rhs) const {
    return point_t(x - rhs.x, y - rhs.y);
  }
};
long long cross(point_t a, point_t b) {
  return (long long)a.x * b.y - (long long)a.y * b.x;
}
long long area(point_t a, point_t b, point_t c) {
  return cross(a, b) + cross(b, c) + cross(c, a);
}
long long dist(point_t a, point_t b) {
  return (long long)(a.x - b.x) * (a.x - b.x) +
         (long long)(a.y - b.y) * (a.y - b.y);
}
void chemthan() {
  int n, k;
  cin >> n >> k;
  vector<point_t> pts(n);
  for (int i = (0); i < (n); ++i) cin >> pts[i].x >> pts[i].y;
  vector<vector<long long>> f(n, vector<long long>(n));
  for (int i = (0); i < (n); ++i) {
    long long sum = 0;
    for (int jj = (1); jj < (n); ++jj) {
      int u = (i + jj - 1) % n;
      int v = (u + 1) % n;
      sum += cross(pts[u], pts[v]);
      f[i][v] = sum;
    }
  }
  long long area = 0;
  for (int i = (0); i < (n); ++i) {
    int j = (i + 1) % n;
    area += cross(pts[i], pts[j]);
  }
  auto func = [&](int x, int y, int z, int t) {
    long long res = area;
    res -= f[x][y];
    res -= cross(pts[y], pts[x]);
    res -= f[z][t];
    res -= cross(pts[t], pts[z]);
    return res;
  };
  auto check = [&](long long mi) {
    vector<vector<pair<int, long long>>> dp(
        n, vector<pair<int, long long>>(n, make_pair(-1, 0)));
    function<pair<int, long long>(int, int)> calc = [&](int x, int y) {
      if (f[y][x] + cross(pts[x], pts[y]) < mi) {
        return make_pair(0, f[y][x] + cross(pts[x], pts[y]));
      }
      auto& res = dp[x][y];
      if (~res.first) return res;
      res = make_pair(0, f[y][x] + cross(pts[x], pts[y]));
      if (mi <= res.second) {
        res.first++;
        res.second = 0;
      }
      {
        for (int i = (y + 1) % n; i != x; i = (i + 1) % n) {
          auto tmp1 = calc(x, i);
          auto tmp2 = calc(i, y);
          auto tmp =
              make_pair(tmp1.first + tmp2.first,
                        tmp1.second + tmp2.second + cross(pts[x], pts[y]) +
                            cross(pts[y], pts[i]) + cross(pts[i], pts[x]));
          if (mi <= tmp.second) {
            tmp.first++;
            tmp.second = 0;
          }
          chkmax(res, tmp);
        }
      }
      return res;
    };
    return k + 1 <= calc(0, 1).first;
  };
  long long lo = 0, hi = LINF;
  while (lo < hi) {
    long long mi = lo + hi + 1 >> 1;
    if (check(mi)) {
      lo = mi;
    } else {
      hi = mi - 1;
    }
  }
  cout << (lo + hi >> 1) << "\n";
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
