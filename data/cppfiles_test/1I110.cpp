#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int MOD = 1e9;
const int maxN = 1e6;
long double pi = 3.14159265359;
struct myPoint {
  long double angle, radius;
  myPoint();
  myPoint(long double x, long double y) {
    angle = x == 0 ? pi / 2 : atan2(y, x);
    radius = sqrt(x * x + y * y);
  }
};
bool canBeAns(vector<myPoint> &v, long double R, int k) {
  vector<long double> enters;
  vector<long double> leaves;
  int curr = 0;
  for (myPoint p : v) {
    if (p.radius > 2 * R) continue;
    long double theta = acos(p.radius / (2 * R));
    if ((p.angle - theta < -pi and p.angle + theta > -pi) or
        (p.angle - theta < pi and p.angle + theta > pi))
      ++curr;
    long double e =
        p.angle - theta > -pi ? p.angle - theta : p.angle - theta + 2 * pi;
    long double l =
        p.angle + theta < pi ? p.angle + theta : p.angle + theta - 2 * pi;
    enters.push_back(e);
    leaves.push_back(l);
  }
  sort(enters.begin(), enters.end());
  sort(leaves.begin(), leaves.end());
  auto it1 = enters.begin();
  auto it2 = leaves.begin();
  while (it1 != enters.end() and it2 != leaves.end()) {
    if (*it1 < *it2) {
      it1++;
      curr++;
      if (curr >= k) return true;
    } else {
      it2++;
      curr--;
    }
  }
  while (it1 != enters.end()) {
    ++curr;
    it1++;
    if (curr >= k) return true;
  }
  return curr >= k;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  vector<myPoint> v(n, myPoint(0, 0));
  long double x, y;
  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    v[i] = myPoint(x, y);
  }
  pair<long double, long double> r = {0, 200000};
  while ((r.second - r.first) / max((long double)1, min(r.first, r.second)) >
         1e-5) {
    if (canBeAns(v, (r.first + r.second) / 2, k))
      r.second = (r.first + r.second) / 2;
    else
      r.first = (r.first + r.second) / 2;
  }
  cout << (r.first + r.second) / 2 << endl;
}
