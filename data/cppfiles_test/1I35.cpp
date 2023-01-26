#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const double eps = 1e-8, pi = acos(-1);
int n, k, x[N], y[N];
long double dis[N];
long double b[N * 4], L[N * 2], R[N * 2];
int cnt, t, c[N];
inline void push(long double d, long double u) {
  ++cnt;
  L[cnt] = d, R[cnt] = u;
}
inline bool check(long double r) {
  int ct = 0;
  cnt = 0;
  for (int i = 1; i <= n; ++i)
    if (dis[i] == 0)
      ++ct;
    else if (dis[i] <= 2 * r) {
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
  t = 0;
  for (int i = 1; i <= cnt; ++i) b[++t] = L[i], b[++t] = R[i];
  sort(b + 1, b + t + 1);
  t = unique(b + 1, b + t + 1) - b - 1;
  for (int i = 1; i <= t; ++i) c[i] = 0;
  for (int i = 1; i <= cnt; ++i) {
    int l = lower_bound(b + 1, b + t + 1, L[i]) - b,
        r = lower_bound(b + 1, b + t + 1, R[i]) - b;
    ++c[l], --c[r + 1];
  }
  int mx = 0;
  for (int i = 1; i <= t; ++i) c[i] += c[i - 1], mx = max(mx, c[i]);
  return mx + ct >= k;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i)
    scanf("%d%d", &x[i], &y[i]),
        dis[i] = sqrt(1ll * x[i] * x[i] + 1ll * y[i] * y[i]);
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
