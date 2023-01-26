#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops", \
                     "omit-frame-pointer", "inline")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native", "no-zero-upper")
using namespace std;
const long long mod = (1e9 + 7);
const double eps = (1e-9);
const long long oo = (long long)(1e18 + 5);
complex<double> operator*(complex<double> p, double x) {
  return complex<double>(p.real() * x, p.imag() * x);
}
complex<double> operator/(complex<double> p, double x) { return p * (1 / x); }
int aux(vector<complex<double> >& ps, double x) {
  vector<pair<double, long long> > ts;
  for (auto p : ps) {
    double v = abs(p);
    if (v < x + eps) continue;
    double ang1;
    if (p.imag() >= 0)
      ang1 = acos(p.real() / v);
    else
      ang1 = 2 * acos(-1) - acos(p.real() / v);
    double ang2 = acos(x / v);
    if (ang1 - ang2 < 0) ang1 += 2 * acos(-1);
    ts.push_back(pair<double, long long>(ang1 - ang2, 1));
    ts.push_back(pair<double, long long>(ang1 + ang2, -1));
    ts.push_back(pair<double, long long>(2 * acos(-1) + ang1 - ang2, 1));
    ts.push_back(pair<double, long long>(2 * acos(-1) + ang1 + ang2, -1));
  }
  sort((ts).begin(), (ts).end());
  int res = 0;
  int act = 0;
  for (auto y : ts) {
    act += y.second;
    res = max(act, res);
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<complex<double> > ps;
  double c = 2e9;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (x == 0 && y == 0) {
      k--;
      continue;
    }
    ps.push_back(complex<double>(x, y));
    double d = abs(ps.back());
    complex<double> nor = ps.back() / d;
    complex<double> np = nor * (c / d);
    ps.back() = np;
  }
  double l = 0, r = 1e6;
  while (r - l > 1e-9) {
    double m = (l + r) / 2;
    if (aux(ps, c / m) < k)
      l = m;
    else
      r = m;
  }
  cout.precision(10);
  cout << fixed;
  cout << (l / 2) << '\n';
  return 0;
}
