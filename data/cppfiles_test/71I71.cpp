#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
const double eps = 1e-8;
bool check(double x) { return abs(x) < eps; }
int n, k;
struct P {
  double x, y;
  int id;
  P(double x = 0, double y = 0) : x(x), y(y) {}
  double norm() { return sqrt(x * x + y * y); }
  P operator-(const P t) const { return P(x - t.x, y - t.y); }
} p[N + 5], tp, pk;
int sp;
double diss;
double dis(P x, P y) { return (x - y).norm(); }
double cross(P t1, P t2) { return t1.x * t2.y - t1.y * t2.x; }
bool chk(P a, P b) {
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    if (!check(cross(p[i] - a, p[i] - b))) {
      sp = i;
      cnt++;
    }
  return cnt == 1;
}
void prep() {
  if (chk(p[1], p[2])) return;
  if (chk(p[1], p[3])) return;
  chk(p[2], p[3]);
}
bool cmp(P x, P y) { return x.x < y.x; }
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%lf %lf", &p[i].x, &p[i].y);
    p[i].id = i;
  }
  prep();
  tp = p[sp];
  pk = p[k];
  for (int i = sp; i < n; i++) p[i] = p[i + 1];
  sort(p + 1, p + n, cmp);
  diss = dis(tp, p[1]);
  for (int i = 1; i < n; i++)
    diss = min(diss, dis(tp, p[i]) + min(dis(p[i], p[1]), dis(p[i], p[n - 1])));
  diss += dis(p[1], p[n - 1]);
  if (k == sp)
    printf("%lf\n", diss);
  else {
    double ans = dis(pk, tp) + diss;
    for (int i = 1; i < n - 1; i++)
      if (p[i].id == k) {
        double td = dis(tp, p[i + 1]);
        for (int j = i + 1; j < n; j++)
          td = min(td, dis(tp, p[j]) +
                           min(dis(p[j], p[i + 1]), dis(p[j], p[n - 1])));
        ans = min(ans,
                  dis(pk, p[1]) + dis(p[1], tp) + td + dis(p[i + 1], p[n - 1]));
      }
    if (p[n - 1].id == k) ans = min(ans, dis(pk, p[1]) + dis(p[1], tp));
    for (int i = n - 1; i > 1; i--) {
      if (p[i].id == k) {
        double td = dis(tp, p[i - 1]);
        for (int j = i - 1; j; j--)
          td = min(td,
                   dis(tp, p[j]) + min(dis(p[j], p[i - 1]), dis(p[j], p[1])));
        ans = min(ans,
                  dis(pk, p[n - 1]) + dis(p[n - 1], tp) + dis(p[1], p[i - 1]));
      }
    }
    if (p[1].id == k) ans = min(ans, dis(pk, p[n - 1]) + dis(p[n - 1], tp));
    printf("%lf\n", ans);
  }
  return 0;
}
