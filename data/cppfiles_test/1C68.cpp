#include <bits/stdc++.h>
const double pi = acos(-1.0);
using namespace std;
int n, k;
struct Point {
  double x, y;
  Point(){};
  Point(double x, double y) : x(x), y(y){};
  Point operator+(Point a) { return Point(x + a.x, y + a.y); }
  Point operator-(Point a) { return Point(x - a.x, y - a.y); }
  Point operator*(double r) { return Point(x * r, y * r); }
  Point operator/(double r) { return Point(x / r, y / r); }
  double len2() { return x * x + y * y; }
  double len() { return sqrt(x * x + y * y); }
  Point rotateleft() { return Point(-y, x); }
  Point rotateright() { return Point(y, -x); }
  Point norm() { return *this / len(); }
} p[1000007];
vector<pair<double, int> > tp;
void deal(Point p, double R) {
  if (p.len() >= 2 * R) return;
  double delt = p.len() / (2 * R);
  delt = acos(delt);
  double al, ar;
  al = atan2(p.y, p.x) - delt;
  ar = atan2(p.y, p.x) + delt;
  if (al > pi) al -= 2 * pi;
  if (al < -pi) al += 2 * pi;
  if (ar > pi) ar -= 2 * pi;
  if (ar < -pi) ar += 2 * pi;
  if (al <= ar) {
    tp.emplace_back(al, 1);
    tp.emplace_back(ar, -1);
  } else {
    tp.emplace_back(-pi, 1);
    tp.emplace_back(ar, -1);
    tp.emplace_back(al, 1);
    tp.emplace_back(pi, -1);
  }
  return;
}
bool check(double r) {
  tp.clear();
  for (int i = 1; i <= n; i++) {
    deal(p[i], r);
  }
  int maxx = 0;
  sort(tp.begin(), tp.end(), [](pair<double, int> a, pair<double, int> b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second > b.second;
  });
  int now = 0;
  for (auto [x, y] : tp) {
    now += y;
    maxx = max(maxx, now);
  }
  return maxx >= k;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%lf%lf", &p[i].x, &p[i].y);
  }
  double l = 0, r = 2e5;
  for (int i = 1; i <= 100; i++) {
    double mid = (l + r) / 2;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  printf("%.10f\n", l);
  return 0;
}
