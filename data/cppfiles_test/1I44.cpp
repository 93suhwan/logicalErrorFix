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
vector<pair<long double, int>> events;
void getangles(long double rad) {
  for (auto pt : points) {
    if (dist(pt.first, pt.second) > rad) {
      continue;
    }
    long double angle_pt = angle(pt.first, pt.second);
    long double alpha = (PI - 2 * asin(dist(pt.first, pt.second) / rad)) / 2.0;
    events.push_back(make_pair(angle_pt + 2 * PI - alpha, 1));
    events.push_back(make_pair(angle_pt + 2 * PI + alpha + EPS, -1));
    events.push_back(make_pair(angle_pt + 4 * PI - alpha, 1));
    events.push_back(make_pair(angle_pt + 4 * PI + alpha + EPS, -1));
  }
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
    events.clear();
    getangles(mid);
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
