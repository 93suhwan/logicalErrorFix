#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265358979323846;
const double EPS = 1e-8;
double angle(double x, double y) {
  double ret = atan2(y, x);
  if (ret < 0.0) ret += 2 * PI;
  return ret;
}
vector<pair<double, double>> points;
double dist(double x, double y) { return sqrt(x * x + y * y); }
vector<double> angles_plus(double rad) {
  vector<double> ret;
  for (auto pt : points) {
    if (dist(pt.first, pt.second) > rad) {
      continue;
    }
    double angle_pt = angle(pt.first, pt.second);
    double alpha = (PI - 2 * asin(dist(pt.first, pt.second) / rad)) / 2.0;
    double a_plus = angle_pt - alpha;
    ret.push_back(a_plus + 4 * PI);
  }
  return ret;
}
vector<double> angles_minus(double rad) {
  vector<double> ret;
  for (auto pt : points) {
    if (dist(pt.first, pt.second) > rad) {
      continue;
    }
    double angle_pt = angle(pt.first, pt.second);
    double alpha = (PI - 2 * asin(dist(pt.first, pt.second) / rad)) / 2.0;
    double a_minus = angle_pt + alpha;
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
    double x, y;
    cin >> x >> y;
    points.push_back({x, y});
  }
  double st = 0.0, dr = 200000.0, sol = dr;
  while (dr - st > EPS) {
    double mid = (st + dr) / 2;
    vector<double> plus = angles_plus(mid);
    vector<double> minus = angles_minus(mid);
    vector<pair<double, int>> events;
    for (auto it : plus) {
      events.push_back(make_pair(it, 1));
      events.push_back(make_pair(it + 2 * PI, 1));
      events.push_back(make_pair(it + 4 * PI, 1));
    }
    for (auto it : minus) {
      events.push_back(make_pair(it, -1));
      events.push_back(make_pair(it + 2 * PI, -1));
      events.push_back(make_pair(it + 4 * PI, -1));
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
  cout << fixed << setprecision(8) << sol / 2 << "\n";
  return 0;
}
