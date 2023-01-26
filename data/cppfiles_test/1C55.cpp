#include <bits/stdc++.h>
using namespace std;
void read(int& x) { scanf("%d", &x); }
void read(long long& x) { scanf("%lld", &x); }
void read(double& x) { scanf("%lf", &x); }
long long gcd(long long x, long long y) {
  while (y) {
    long long t = x % y;
    x = y;
    y = t;
  }
  return x;
}
const double pi = 3.1415926535897932384626433832795;
struct point {
  double x, y;
  double an;
  double dist;
};
bool ok(vector<point>& a, double r, int k) {
  vector<pair<double, int>> angs;
  for (int i = 0; i < a.size(); i++) {
    if (a[i].dist > 2 * r) continue;
    double theta = acos(a[i].dist / (2.0 * r));
    angs.push_back({a[i].an - theta, 1});
    angs.push_back({a[i].an + theta, -1});
  }
  {
    int asz = angs.size();
    for (int i = 0; i < asz; i++)
      angs.push_back({angs[i].first + 2 * pi, angs[i].second});
  }
  sort(angs.begin(), angs.end());
  int acc = 0;
  int ret = 0;
  for (auto& p : angs) {
    acc += p.second;
    if (acc >= k) return true;
  }
  return false;
}
void solve() {
  int n, k;
  scanf("%d%d", &n, &k);
  vector<point> a(n);
  for (int i = 0; i < n; i++) {
    scanf("%lf%lf", &a[i].x, &a[i].y);
    a[i].an = atan2(a[i].y, a[i].x);
    a[i].dist = hypot(a[i].x, a[i].y);
  }
  double s = 0, e = 200000;
  double eps = 1e-5;
  while (e - s > eps) {
    double r = (s + e) / 2.0;
    if (ok(a, r, k))
      e = r;
    else
      s = r;
  }
  printf("%.10lf\n", (s + e) / 2.0);
}
int main() {
  { solve(); }
  return 0;
}
