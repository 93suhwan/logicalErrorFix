#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;
const int mod = 1e9 + 7;
const int MOD = 998244353;
const double EPS = 1e-15;
struct point {
  double x;
  double y;
};
struct point3D {
  double x;
  double y;
  double z;
};
bool doubleEqual(double a, double b) { return abs(a - b) <= EPS; }
bool doubleGreater(double a, double b) {
  if (a > b && !doubleEqual(a, b))
    ;
}
bool doubleLess(double a, double b) {
  if (a < b && !doubleEqual(a, b))
    ;
}
bool doubleEqualOrLess(double a, double b) {
  if (a < b || doubleEqual(a, b))
    ;
}
bool doubleEqualOrGreater(double a, double b) {
  if (a > b || doubleEqual(a, b))
    ;
}
point3D Vect3D(point3D A, point3D B) {
  point3D res;
  res.x = B.x - A.x;
  res.y = B.y - A.y;
  res.z = B.z - A.z;
  return res;
}
point Vect(point A, point B) {
  point res;
  res.x = B.x - A.x;
  res.y = B.y - A.y;
  return res;
}
double Length(point v) { return sqrt(v.x * v.x + v.y * v.y); }
double Length3D(point3D v) { return sqrt(v.x * v.x + v.y * v.y + v.z * v.z); }
point Opposite(point v) {
  v.x = -v.x;
  v.y = -v.y;
  return v;
}
point3D Opposite(point3D v) {
  v.x = -v.x;
  v.y = -v.y;
  v.z = -v.z;
  return v;
}
point vectAdd(point v, point w) {
  point res;
  res.x = w.x + v.x;
  res.y = w.y + v.y;
  return res;
}
point3D vect3DAdd(point3D v, point3D w) {
  point3D res;
  res.x = v.x + w.x;
  res.y = v.y + w.y;
  res.z = v.z + w.z;
  return res;
}
point vectSub(point v, point w) {
  point res;
  res.x = v.x - w.x;
  res.y = v.y - w.y;
  return res;
}
point3D vect3DSub(point3D v, point3D w) {
  point3D res;
  res.x = v.x - w.x;
  res.y = v.y - w.y;
  res.z = v.z - w.y;
}
point vectMul(point v, double k) {
  point res;
  res.x = v.x * k;
  res.y = v.y * k;
  return res;
}
point3D vect3DMul(point3D v, double k) {
  point3D res;
  res.x = v.x * k;
  res.y = v.y * k;
  res.z = v.z * k;
  return res;
}
point vectNorm(point v, double k) {
  point res;
  double len = 1 / Length(v);
  res.x = len * v.x;
  res.y = len * v.y;
  return res;
}
point3D vectNorm3D(point3D v, double k) {
  point3D res;
  double len = 1 / Length3D(v);
  res.x = len * v.x;
  res.y = len * v.y;
  res.z = len * v.z;
  return res;
}
point relPoint(point v, point w, double r, double q) {
  point res;
  res.x = (q * v.x + r * w.x) / (r + q);
  res.y = (q * v.y + r * w.y) / (r + q);
  return res;
}
point3D relPoint3D(point3D v, point3D w, double r, double q) {
  point3D res;
  res.x = (q * v.x + r * w.x) / (r + q);
  res.y = (q * v.y + r * w.y) / (r + q);
  res.z = (q * v.z + r * w.z) / (r + q);
  return res;
}
long long scalarProd(point v, point w) { return v.x * w.x + v.y * w.y; }
long long scalarProd3D(point3D v, point3D w) {
  return v.x * w.x + v.y * w.y + v.z * w.z;
}
double polarAngle(point v) {
  point e;
  e.x = 1;
  e.y = 0;
  double sp = scalarProd(v, e);
  return acos(sp / Length(v));
}
long long crossProd(point v, point w) { return v.x * w.y - v.y * w.x; }
double crossProd3D(point3D v, point3D w) {
  point3D c;
  c.x = v.y * w.z - v.z * w.y;
  c.y = -(v.x * w.z - v.z * w.x);
  c.z = v.x * w.y - v.y * w.x;
  return Length3D(c);
}
point Orthogonal(point v) {
  point res;
  res.x = -v.y;
  res.y = v.x;
  return res;
}
double AreaN(int n, vector<point> &A) {
  double s = 0;
  for (int i = 1; i < n - 1; i++) {
    s += crossProd(Vect(A[0], A[i]), Vect(A[0], A[i + 1]));
  }
  return abs(s) / 2;
}
int angleType(point A, point B, point C) {
  point ab = Vect(A, B);
  point ac = Vect(A, C);
  double sp = scalarProd(ab, ac);
  if (sp == 0LL) return 0;
  if (sp < 0LL) return -1;
  return 1;
}
int angleType(point3D A, point3D B, point3D C) {
  point3D ab = Vect3D(A, B);
  point3D ac = Vect3D(A, C);
  double sp = scalarProd3D(ab, ac);
  if (sp == 0LL) return 0;
  if (sp < 0LL) return -1;
  return 1;
}
ll gcd(ll a, ll b) {
  if (a < b) swap(a, b);
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int bin_pow_mod(ll a, ll n, int mod) {
  int res = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      res = (res * a) % mod;
    }
    a = (a * a) % mod;
    n /= 2;
  }
  return res;
}
ll extended_gcd(ll a, ll b, ll &x, ll &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  ll x1, y1;
  ll d = extended_gcd(b % a, a, x1, y1);
  x = (y1 - (b / a) * x1);
  y = x1;
  return d;
}
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
double distanceDotLine(point O, point A, point B) {
  if (angleType(A, O, B) == -1 || angleType(B, O, A) == -1) {
    return min(Length(Vect(O, A)), Length(Vect(O, B)));
  } else {
    if (doubleEqual(Length(Vect(A, B)), 0))
      return Length(Vect(O, A));
    else
      return fabs(crossProd(Vect(O, A), Vect(O, B))) / Length(Vect(A, B));
  }
}
bool dotEqual(pair<double, double> a, pair<double, double> b) {
  double x1 = a.first;
  double y1 = a.second;
  double x2 = b.first;
  double y2 = b.second;
  if (doubleEqual(x1, x2) && doubleEqual(y1, y2))
    return 1;
  else
    return 0;
}
ll euler(ll n) {
  ll res = n;
  for (int i = 2; i * i <= n; i++) {
    if (n % i != 0) continue;
    while (n % i == 0) {
      res = (res - res / i);
    }
  }
  if (n > 1) {
    res = (res - res / n);
  }
  return res;
}
set<int> a;
void preculc() {
  int i = 1;
  int j = 1;
  while (i * i <= 1e9) {
    a.insert(i * i);
    i++;
  }
  while (j * j * j <= 1e9) {
    a.insert(j * j * j);
    j++;
  }
}
void solve() {
  int n;
  cin >> n;
  int k = 0;
  for (int r : a) {
    if (r <= n) {
      k++;
    } else
      break;
  }
  cout << k << "\n";
}
int main() {
  preculc();
  cout.precision(14);
  int t;
  cin >> t;
  while (t--) solve();
}
