#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x;
  scanf("%lld", &x);
  return x;
}
const long long N = 200010;
struct point {
  long long x, y;
} p[N], b[N];
double dist(point a, point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
bool operator<(point a, point b) {
  return (a.x == b.x) ? (a.y < b.y) : (a.x < b.x);
}
bool same(point a, point b) { return (a.x == b.x) && (a.y == b.y); }
long long n, m, k, teshu;
long long cha(long long x1, long long yeeeeeeeeeeeeee, long long x2,
              long long y2) {
  return x1 * y2 - x2 * yeeeeeeeeeeeeee;
}
long long count(long long x, long long y) {
  long long sum = 0;
  for (long long i = (long long)(1); i <= (long long)(n); ++i)
    if (i != x && i != y) {
      if (cha(p[i].x - p[x].x, p[i].y - p[x].y, p[i].x - p[y].x,
              p[i].y - p[y].y) == 0)
        ++sum;
      else
        teshu = i;
    }
  return sum;
}
int main() {
  n = read();
  k = read();
  for (long long i = (long long)(1); i <= (long long)(n); ++i)
    p[i].x = read(), p[i].y = read();
  if (count(1, 2) != n - 3) {
    if (count(1, 3) != n - 3) {
      if (count(2, 3) != n - 3) {
      }
    }
  }
  double ans = 1e18;
  if (k == teshu) {
    for (long long i = (long long)(1); i <= (long long)(n); ++i)
      if (i != k) b[++m] = p[i];
    sort(b + 1, b + m + 1);
    double answ = 0;
    for (long long i = (long long)(2); i <= (long long)(m); ++i)
      answ += dist(b[i - 1], b[i]);
    ans = min(dist(b[1], p[teshu]), dist(b[m], p[teshu])) + answ;
  } else {
    for (long long i = (long long)(1); i <= (long long)(n); ++i)
      if (i != k && i != teshu) b[++m] = p[i];
    sort(b + 1, b + m + 1);
    double answ = dist(p[k], p[teshu]);
    for (long long i = (long long)(2); i <= (long long)(m); ++i)
      answ += dist(b[i - 1], b[i]);
    ans = min(dist(b[1], p[teshu]), dist(b[m], p[teshu])) + answ;
    answ = 0;
    long long L = 0, R = 0;
    for (long long i = (long long)(1); i <= (long long)(m); ++i)
      if (b[i] < p[k]) {
        if (i > 1) answ += dist(b[i - 1], b[i]);
        L = k;
      }
    for (long long i = (long long)(m); i >= (long long)(1); --i)
      if (p[k] < b[i]) {
        if (i < m) answ += dist(b[i + 1], b[i]);
        R = k;
      }
    if (L)
      ans = min(
          ans, answ + dist(p[k], b[L]) + dist(b[1], p[teshu]) +
                   (R ? (min(dist(b[R], p[teshu]), dist(b[m], p[teshu]))) : 0));
    if (R)
      ans = min(
          ans, answ + dist(p[k], b[R]) + dist(b[m], p[teshu]) +
                   (L ? (min(dist(b[L], p[teshu]), dist(b[1], p[teshu]))) : 0));
  }
  printf("%.10lf\n", ans);
}
