#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.14159265358979323846;
const long double EPS = 1e-8;
long double angle(long double x, long double y) {
  long double ret = atan2(y, x);
  if (ret < 0.0) ret += 2 * PI;
  return ret;
}
vector<pair<long double, long double>> points;
long double dist(long double x, long double y) { return sqrt(x * x + y * y); }
vector<long double> angles_plus(long double rad) {
  vector<long double> ret;
  for (auto pt : points) {
    if (dist(pt.first, pt.second) > rad) {
      continue;
    }
    long double angle_pt = angle(pt.first, pt.second);
    long double alpha = (PI - 2 * asin(dist(pt.first, pt.second) / rad)) / 2.0;
    long double a_plus = angle_pt - alpha;
    ret.push_back(a_plus);
  }
  return ret;
}
vector<long double> angles_minus(long double rad) {
  vector<long double> ret;
  for (auto pt : points) {
    if (dist(pt.first, pt.second) > rad) {
      continue;
    }
    long double angle_pt = angle(pt.first, pt.second);
    long double alpha = (PI - 2 * asin(dist(pt.first, pt.second) / rad)) / 2.0;
    long double a_minus = angle_pt + alpha;
    ret.push_back(a_minus);
  }
  return ret;
}
int make_events(long double rad) {
  vector<long double> plus, minus;
  for (auto pt : points) {
    if (dist(pt.first, pt.second) > rad) {
      continue;
    }
    long double angle_pt = angle(pt.first, pt.second);
    long double alpha = (PI - 2 * asin(dist(pt.first, pt.second) / rad)) / 2.0;
    plus.push_back(angle_pt - alpha + 2 * PI);
    minus.push_back(angle_pt + alpha + 2 * PI + EPS);
  }
  sort(plus.begin(), plus.end());
  sort(minus.begin(), minus.end());
  int ret = 0, ret_max = 0;
  int ptr_p = 0, ptr_m = 0;
  while (ptr_p < 2 * plus.size() && ptr_m < 2 * minus.size()) {
    if (plus[ptr_p % plus.size()] + (ptr_p >= plus.size() ? 2 * PI : 0) <
        minus[ptr_m % minus.size()] + (ptr_m >= minus.size() ? 2 * PI : 0)) {
      ret += 1;
      ret_max = max(ret_max, ret);
      ptr_p++;
    } else {
      ret -= 1;
      ptr_m++;
    }
  }
  while (ptr_p < 2 * plus.size()) {
    ret += 1;
    ret_max = max(ret_max, ret);
    ptr_p++;
  }
  return ret_max;
}
bool cmp(pair<long double, long double> a, pair<long double, long double> b) {
  return angle(a.first, a.second) < angle(b.first, b.second);
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    long double x, y;
    cin >> x >> y;
    points.push_back({x, y});
  }
  sort(points.begin(), points.end());
  long double st = 0.0, dr = 200000.0, sol = dr;
  for (int iter = 0; iter < 150; iter++) {
    long double mid = (st + dr) / 2;
    if (make_events(mid) >= k) {
      dr = mid;
      sol = mid;
    } else {
      st = mid;
    }
  }
  cout << fixed << setprecision(12) << sol / 2.0 + 1e-7 << endl;
}
