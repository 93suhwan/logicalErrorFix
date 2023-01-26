#include <bits/stdc++.h>
using namespace std;
const long double PI = 2 * acos(0.0);
vector<pair<long double, long double>> pts;
long double angle(long double x, long double y) {
  long double ret = atan2(y, x);
  if (ret < 0.0) ret += 2 * PI;
  return ret;
}
int ok(long double rad) {
  vector<pair<long double, int>> events;
  for (auto pt : pts) {
    long double dist = sqrt(pt.first * pt.first + pt.second * pt.second);
    if (dist > rad) continue;
    long double angle_pt = angle(pt.first, pt.second);
    long double alpha = (PI - 2 * asin(dist / rad)) / 2.0;
    events.push_back({angle_pt - alpha, +1});
    events.push_back({angle_pt + alpha + 1e-12, -1});
    events.push_back({angle_pt - alpha + 2 * PI, +1});
    events.push_back({angle_pt + alpha + 1e-12 + 2 * PI, -1});
  }
  sort(events.begin(), events.end());
  int ret = 0, ret_max = 0;
  for (auto e : events) {
    ret += e.second;
    ret_max = max(ret_max, ret);
  }
  return ret_max;
}
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int _x, _y;
    cin >> _x >> _y;
    long double x, y;
    x = _x;
    y = _y;
    if (_x == 0 && _y == 0)
      k--;
    else
      pts.push_back({x, y});
  }
  long double st = 1e-12, dr = 200000.0;
  long double sol = dr;
  while (dr - st > 1e-8) {
    long double mid = (st + dr) / 2;
    if (ok(mid) >= k)
      sol = mid, dr = mid - 1e-8;
    else
      st = mid + 1e-8;
  }
  cout << fixed << setprecision(12) << sol / 2 << endl;
  return 0;
}
