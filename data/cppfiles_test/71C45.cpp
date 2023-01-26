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
long double dist(point a, point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
bool operator<(point a, point b) {
  return (a.x == b.x) ? (a.y < b.y) : (a.x < b.x);
}
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
  long double ans = 1e18;
  if (k == teshu) {
    for (long long i = (long long)(1); i <= (long long)(n); ++i)
      if (i != k && i != teshu) b[++m] = p[i];
    sort(b + 1, b + m + 1);
    ans = min(dist(b[1], p[teshu]), dist(b[m], p[teshu])) + dist(b[1], b[m]);
  } else {
    for (long long i = (long long)(1); i <= (long long)(n); ++i)
      if (i != k && i != teshu) b[++m] = p[i];
    sort(b + 1, b + m + 1);
    ans = min(dist(b[1], p[teshu]), dist(b[m], p[teshu])) +
          dist(p[k], p[teshu]) + dist(b[1], b[m]);
    for (int i = 1; i < m; ++i) {
      ans =
          min(ans, dist(p[k], b[1]) + dist(b[1], b[i]) + dist(b[i], p[teshu]) +
                       dist(p[teshu], b[i + 1]) + dist(b[i + 1], b[m]));
    }
    for (int i = 2; i <= m; ++i) {
      ans = min(ans, dist(p[k], b[m]) + dist(b[m], b[i + 1]) +
                         dist(b[i + 1], p[teshu]) + dist(p[teshu], b[i]) +
                         dist(b[i], b[1]));
    }
    long long L = 0, R = 0;
    for (long long i = (long long)(1); i <= (long long)(m); ++i)
      if (b[i] < p[k]) L = i;
    for (long long i = (long long)(m); i >= (long long)(1); --i)
      if (p[k] < b[i]) R = i;
    if (L)
      ans = min(ans, dist(p[k], b[1]) + dist(b[1], p[teshu]) +
                         (R ? (dist(b[R], b[m]) +
                               min(dist(b[R], p[teshu]), dist(b[m], p[teshu])))
                            : 0));
    if (R)
      ans = min(ans, dist(p[k], b[m]) + dist(b[m], p[teshu]) +
                         (L ? (dist(b[L], b[1]) +
                               min(dist(b[L], p[teshu]), dist(b[1], p[teshu])))
                            : 0));
    ans = min(ans, dist(b[1], p[k]) + dist(b[1], b[m]) + dist(b[m], p[teshu]));
    ans = min(ans, dist(b[m], p[k]) + dist(b[1], b[m]) + dist(b[1], p[teshu]));
  }
  printf("%.10lf\n", (double)ans);
}
