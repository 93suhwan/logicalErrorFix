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
const int N = 4011;
long long a[N];
vector<long long> solve(int l, int r, int m) {
  int cm = min(m, r - l);
  if (l == r) return {0};
  int mid = min_element(a + l, a + r) - a;
  long long mx = a[mid];
  vector<long long> d1 = solve(l, mid, m);
  vector<long long> d2 = solve(mid + 1, r, m);
  vector<long long> d(cm + 1, -LINF);
  for (int m1 = 0; m1 < ((int)((d1).size())); ++m1)
    for (int m2 = 0; m2 < ((int)((d2).size())) && m1 + m2 <= cm; ++m2) {
      updMax(d[m1 + m2], d1[m1] + d2[m2] - 2LL * m1 * m2 * mx);
    }
  for (int m1 = 0; m1 < ((int)((d1).size())); ++m1)
    for (int m2 = 0; m2 < ((int)((d2).size())) && m1 + m2 + 1 <= cm; ++m2) {
      updMax(d[m1 + m2 + 1], d1[m1] + d2[m2] + mx * m -
                                 mx * (1 + 2 * m1 + 2 * m2 + 2LL * m1 * m2));
    }
  return d;
}
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> a[i];
  cout << solve(0, n, m)[m] << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  int t = 1;
  for (int i = 0; i < t; ++i) solve();
  return 0;
}
