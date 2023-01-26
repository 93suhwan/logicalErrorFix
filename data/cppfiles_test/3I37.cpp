#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const double pi = acos(-1.0);
const double inf = ~0u >> 2;
struct point {
  double x, y;
  point(double x = 0, double y = 0) : x(x), y(y) {}
} p[100007];
struct node {
  double ang;
  int in;
} arc[100007];
double dis(point a, point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int dcmp(double x) {
  if (fabs(x) < eps)
    return 0;
  else
    return x < 0 ? -1 : 1;
}
bool cmp(node a, node b) {
  if (dcmp(a.ang - b.ang) == 0) return a.in > b.in;
  return dcmp(a.ang - b.ang) < 0;
}
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int i, j;
  p[0] = {0, 0};
  for (i = 1; i <= n; i++) scanf("%lf%lf", &p[i].x, &p[i].y);
  double l = 0, r = 2e5 + 7;
  for (int it = 0; it <= 500; it++) {
    double rad = (l + r) / 2.0;
    int g = 0;
    int ans = 0, maxz = 0;
    i = 0;
    ans = 0;
    g = 0;
    for (j = 1; j <= n; j++) {
      if (dis(p[i], p[j]) > 2 * rad) continue;
      double ang1 = atan2(p[i].y - p[j].y, p[i].x - p[j].x);
      double ang2 = acos(dis(p[i], p[j]) / (2 * rad));
      arc[++g].ang = ang1 - ang2;
      arc[g].in = 1;
      arc[++g].ang = ang1 + ang2;
      arc[g].in = -1;
    }
    sort(arc + 1, arc + g + 1, cmp);
    for (j = 1; j <= g; j++) {
      ans += arc[j].in;
      maxz = max(maxz, ans);
    }
    if (maxz >= k)
      r = rad;
    else
      l = rad;
  }
  printf("%.15lf\n", l);
  return 0;
}
