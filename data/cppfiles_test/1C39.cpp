#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const double PI = acos(-1);
struct Vector {
  double x, y;
  Vector(double X = 0, double Y = 0) {
    x = X;
    y = Y;
  }
  Vector operator+(const Vector &p) const { return Vector(x + p.x, y + p.y); }
  Vector operator-(const Vector &p) const { return Vector(x - p.x, y - p.y); }
  double arc() { return atan2(y, x); }
  double len() { return sqrt(x * x + y * y); }
} p[MAXN];
int n, k;
vector<pair<double, int> > event;
bool ok(double r) {
  event.clear();
  for (int i = 1; i <= n; i++) {
    if (p[i].len() <= 2 * r) {
      double arc = p[i].arc();
      double rot = acos(p[i].len() / (2 * r));
      double l = arc - rot, r = arc + rot;
      event.push_back(make_pair(l, 1));
      event.push_back(make_pair(r, -1));
      event.push_back(make_pair(l + 2 * PI, 1));
      event.push_back(make_pair(r + 2 * PI, -1));
    }
  }
  sort(event.begin(), event.end());
  int sum = 0;
  for (int i = 0; i < event.size(); i++) {
    sum += event[i].second;
    if (sum >= k) return 1;
  }
  return 0;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int x, y, i = 1; i <= n; i++) {
    scanf("%d%d", &x, &y);
    p[i].x = x;
    p[i].y = y;
  }
  double low = 0, high = 200000;
  while (high - low > 1e-6) {
    double mid = (low + high) / 2.;
    if (ok(mid))
      high = mid;
    else
      low = mid;
  }
  printf("%.5lf\n", low);
  return 0;
}
