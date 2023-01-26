#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 1;
const long long inf = 1e18 + 1;
const long long MOD = 1e9 + 7;
const long long MOD2 = 998244353;
const int MOD3 = 31607;
template <class T>
T _ceil(T a, T b) {
  return (a + b - 1) / b;
}
template <class T>
T _min(T a, T b) {
  return a > b ? b : a;
};
template <class T>
T _max(T a, T b) {
  return a > b ? a : b;
};
template <class T>
T _abs(T a) {
  return a > 0 ? a : -a;
};
template <class T>
T _gcd(T a, T b) {
  return a ? _gcd(b % a, a) : b;
};
const double PI = 3.1415926535;
double sq(double x) { return x * x; }
double func(double p, double q, double m, double t) {
  return sq(p - m * cos(t)) + sq(q - m * sin(t)) - sq(m);
}
int solve() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> vec;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (x == 0 and y == 0) {
      k--;
      continue;
    }
    vec.push_back({x, y});
  }
  int N = (int)vec.size();
  if (N == 0) {
    cout << 0.0 << "\n";
    return 0;
  }
  double l = 0, r = 2e5 + 1.000001;
  while (_abs(l - r) >= 1e-5) {
    double m = (l + r) / 2;
    vector<pair<double, int>> temp;
    for (int i = 0; i < N; i++) {
      double p = (double)vec[i].first, q = (double)vec[i].second;
      double s = sqrt(p * p + q * q);
      if (s > 2 * m) continue;
      double a = _abs(acos(p / s));
      if (q / s > 0) a *= -1;
      double t1 = acos(s / (2 * m)) - a;
      while (t1 > 2 * PI) t1 -= 2 * PI;
      while (t1 < 0) t1 += 2 * PI;
      double t2 = -acos(s / (2 * m)) - a;
      while (t2 < 0) t2 += 2 * PI;
      while (t2 > 2 * PI) t2 -= 2 * PI;
      assert(t1 < 2 * PI and t2 < 2 * PI);
      if (t1 > t2) {
        double t = t1;
        t1 = t2;
        t2 = t;
      }
      if ((p - m) * (p - m) + q * q < m * m) {
        temp.push_back({0, 1});
        temp.push_back({t1, -1});
        temp.push_back({t2, 1});
        temp.push_back({2 * PI, -1});
      } else {
        temp.push_back({t1, 1});
        temp.push_back({t2, -1});
      }
    }
    sort(temp.begin(), temp.end());
    int count = 0;
    bool canDone = false;
    for (auto u : temp) {
      count += u.second;
      if (count >= k) {
        canDone = true;
        break;
      }
    }
    if (canDone)
      r = m;
    else
      l = m;
  }
  cout << (l + r) / 2 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
  }
}
