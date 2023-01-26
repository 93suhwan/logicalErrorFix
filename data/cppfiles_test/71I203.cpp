#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
const long double eps = 1e-8;
bool check(long double x) { return abs(x) < eps; }
int n, k;
struct P {
  long double x, y;
  int id;
  P(long double x = 0, long double y = 0) : x(x), y(y) {}
  long double norm() { return sqrtl(x * x + y * y); }
  P operator-(const P t) const { return P(x - t.x, y - t.y); }
} p[N + 5], tp, pk;
int sp;
long double diss;
long double dis(P x, P y) { return (x - y).norm(); }
long double cross(P t1, P t2) { return t1.x * t2.y - t1.y * t2.x; }
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
bool cmp(P x, P y) { return check(x.x - y.x) ? x.y < y.y : x.x < y.x; }
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%LF %LF", &p[i].x, &p[i].y);
    p[i].id = i;
  }
  prep();
  tp = p[sp];
  pk = p[k];
  for (int i = sp; i < n; i++) p[i] = p[i + 1];
  sort(p + 1, p + n, cmp);
  diss = dis(p[1], p[n - 1]) + min(dis(tp, p[1]), dis(tp, p[n - 1]));
  if (k == sp)
    printf("%.10LF\n", diss);
  else {
    long double ans =
        min(dis(pk, tp) + diss,
            dis(p[1], p[n - 1]) + min(dis(pk, p[1]) + dis(p[1], tp),
                                      dis(pk, p[n - 1]) + dis(p[n - 1], tp)));
    for (int i = 2; i < n; i++)
      ans =
          min(ans, dis(pk, p[n - 1]) + dis(p[1], p[n - 1]) -
                       dis(p[i], p[i - 1]) + dis(p[i - 1], tp) + dis(p[i], tp));
    for (int i = 1; i < n - 1; i++)
      ans = min(ans, dis(pk, p[1]) + dis(p[1], p[n - 1]) - dis(p[i], p[i + 1]) +
                         dis(p[i], tp) + dis(p[i + 1], tp));
    for (int i = 1; i < n - 1; i++)
      if (p[i].id == k)
        ans = min(ans, dis(pk, p[1]) + dis(p[1], tp) +
                           min(dis(tp, p[i + 1]), dis(tp, p[n - 1])) +
                           dis(p[i + 1], p[n - 1]));
    if (p[n - 1].id == k) {
      for (int i = 2; i < n; i++)
        ans = min(ans, dis(pk, p[i]) + dis(p[i], tp) +
                           min(dis(p[i - 1], tp), dis(p[1], tp)) +
                           dis(p[i - 1], p[1]));
      ans = min(ans, dis(pk, p[1]) + dis(p[1], tp));
    }
    for (int i = n - 1; i > 1; i--)
      if (p[i].id == k)
        ans = min(ans, dis(pk, p[n - 1]) + dis(p[n - 1], tp) +
                           min(dis(tp, p[i - 1]), dis(tp, p[1])) +
                           dis(p[i - 1], p[1]));
    if (p[1].id == k) {
      for (int i = 1; i < n - 1; i++)
        ans = min(ans, dis(pk, p[i]) + dis(p[i], tp) +
                           min(dis(p[i + 1], tp), dis(p[n - 1], tp)) +
                           dis(p[i + 1], p[n - 1]));
      ans = min(ans, dis(pk, p[n - 1]) + dis(p[n - 1], tp));
    }
    printf("%.10LF\n", ans);
  }
  return 0;
}
