#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const double eps = 1e-10, pi = acos(-1);
int n, k;
double x[N], y[N];
long double dis[N];
int cnt, t, c[N];
struct node {
  long double p;
  int v;
  inline node(long double P = 0, int V = 0) : p(P), v(V) {}
  inline bool operator<(const node &a) const { return p < a.p; }
} w[N * 10];
inline void push(long double d, long double u) {
  ++cnt, w[cnt] = node(d, 1);
  ++cnt, w[cnt] = node(u, -1);
}
inline bool check(long double r) {
  cnt = 0;
  for (int i = 1; i <= n; ++i)
    if (dis[i] <= 2 * r) {
      long double a = atan2((long double)y[i], (long double)x[i]),
                  b = acos((long double)0.5 * dis[i] / r);
      long double up = a + b, dn = a - b;
      if (dn < -pi)
        push(dn + 2 * pi, pi), push(-pi, up);
      else if (up > pi)
        push(dn, pi), push(-pi, up - 2 * pi);
      else
        push(dn, up);
    }
  sort(w + 1, w + cnt + 1);
  int mx = 0, d = 0;
  for (int i = 1; i <= cnt; ++i) d += w[i].v, mx = max(mx, d);
  return mx >= k;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i)
    scanf("%lf%lf", &x[i], &y[i]), dis[i] = sqrt(x[i] * x[i] + y[i] * y[i]);
  double l = 0, r = 200000;
  while (r - l > eps) {
    double mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%.10lf", l);
  return 0;
}
