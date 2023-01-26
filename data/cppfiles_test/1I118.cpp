#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<pair<int, int> > p;
const long double pi = acos(-1);
const long double eps = 1e-15;
bool check(long double R) {
  vector<pair<long double, int> > e;
  int S = 0;
  for (auto &t : p) {
    long double dis = 1.0 * t.first * t.first + 1.0 * t.second * t.second;
    if (dis > 4 * R * R + eps) continue;
    long double theta = acos(sqrt(dis) / 2 / R);
    long double alpha = atan2(t.second, t.first);
    if (alpha < 0) alpha += 2 * pi;
    long double lo = alpha - theta;
    if (alpha - theta < -eps) {
      S++;
      lo += 2 * pi;
    }
    e.push_back(pair<long double, int>(lo, 1));
    e.push_back(pair<long double, int>(alpha + theta + eps, -1));
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
  long double L = 0.00, R = 200010;
  for (int _ = 0; _ < 100; _++) {
    long double mid = (L + R) / 2;
    if (check(mid)) {
      R = mid;
    } else {
      L = mid;
    }
  }
  printf("%.10lf\n", double(R));
}
