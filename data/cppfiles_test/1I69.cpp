#include <bits/stdc++.h>
using namespace std;
int n, k;
int x[100010], y[100010];
vector<pair<int, int> > p;
const double pi = acos(-1);
const double eps = 1e-6;
bool check(double R) {
  vector<pair<double, int> > e;
  int S = 0;
  for (auto &t : p) {
    double dis = 1.0 * t.first * t.first + 1.0 * t.second * t.second;
    if (dis > 4 * R * R + eps) continue;
    double theta = acos(sqrt(dis) / 2 / R);
    double alpha = atan2(t.second, t.first);
    if (alpha < 0) alpha += 2 * pi;
    double lo = alpha - theta;
    if (alpha - theta < -eps) {
      S++;
      lo += 2 * pi;
    }
    e.push_back(pair<double, int>(lo, 1));
    e.push_back(pair<double, int>(alpha + theta, -1));
  }
  sort(e.begin(), e.end());
  if (S >= k) return true;
  for (auto &t : e) {
    S += t.second;
    if (S >= k) return true;
  }
  return false;
}
int main() {
  int o = 0;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x == 0 && y == 0)
      o++;
    else
      p.emplace_back(x, y);
  }
  if (o >= k) {
    puts("0.000000000");
    return 0;
  }
  k -= o;
  n = p.size();
  double L = 0.00, R = 200010;
  for (int _ = 0; _ < 50; _++) {
    double mid = (L + R) / 2;
    if (check(mid)) {
      R = mid;
    } else {
      L = mid;
    }
  }
  printf("%.10lf\n", R);
}
