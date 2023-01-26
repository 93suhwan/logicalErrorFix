#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
    ret.push_back(a_plus + 4 * PI);
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
    ret.push_back(a_minus + 4 * PI);
  }
  return ret;
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
  long double st = 0.0, dr = 200000.0, sol = dr;
  while (dr - st > EPS) {
    long double mid = (st + dr) / 2;
    vector<long double> plus = angles_plus(mid);
    vector<long double> minus = angles_minus(mid);
    vector<pair<long double, int>> events;
    for (auto it : plus) {
      events.push_back(make_pair(it, 1));
      events.push_back(make_pair(it + 2 * PI, 1));
    }
    for (auto it : minus) {
      events.push_back(make_pair(it, -1));
      events.push_back(make_pair(it + 2 * PI, -1));
    }
    sort(events.begin(), events.end());
    int nr = 0, nrmax = 0;
    for (auto it : events) {
      nr += it.second;
      nrmax = max(nr, nrmax);
    }
    if (nrmax >= k)
      sol = mid, dr = mid - EPS;
    else
      st = mid + EPS;
  }
  cout << fixed << setprecision(8) << sol / 2 + 1e-6 << "\n";
  return 0;
}
