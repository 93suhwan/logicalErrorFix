#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x;
  scanf("%lld", &x);
  return x;
}
const long long N = 1000010;
double eps = 1e-9, pi = acos(-1);
pair<double, long long> q[N];
long long n, k, x[N], y[N], tot;
bool cmp(pair<double, long long> a, pair<double, long long> b) {
  return a.first < b.first;
}
bool check(double R) {
  tot = 0;
  for (long long i = (long long)(1); i <= (long long)(n); ++i) {
    double d = sqrt(x[i] * x[i] + y[i] * y[i]);
    if (R * 2 + eps < d) continue;
    double dlt = acos(d / 2 / R);
    double phi;
    if (y[i] >= 0)
      phi = acos(x[i] / d);
    else
      phi = pi * 2 - acos(x[i] / d);
    double l = phi - dlt, r = phi + dlt;
    if (r > pi * 2) {
      q[++tot].first = 0;
      q[tot].second = 1;
      q[++tot].first = r - 2 * pi;
      q[tot].second = -1;
      q[++tot].first = l;
      q[tot].second = 1;
    } else {
      if (l < 0) {
        q[++tot].first = 0;
        q[tot].second = 1;
        q[++tot].first = r;
        q[tot].second = -1;
        q[++tot].first = l + pi * 2;
        q[tot].second = 1;
      } else {
        q[++tot].first = l;
        q[tot].second = 1;
        q[++tot].first = r;
        q[tot].second = -1;
      }
    }
  }
  for (long long i = (long long)(1); i <= (long long)(tot); ++i)
    if (q[i].second == 1) q[i].first -= eps;
  sort(q + 1, q + tot + 1, cmp);
  long long inf = 0;
  for (long long i = (long long)(1); i <= (long long)(tot); ++i) {
    inf += q[i].second;
    if (inf >= k) return 1;
  }
  return 0;
}
int main() {
  n = read();
  k = read();
  for (long long i = (long long)(1); i <= (long long)(n); ++i) {
    x[i] = read(), y[i] = read();
    if (x[i] == 0 && y[i] == 0) {
      --i;
      --k;
      --n;
    }
  }
  if (k <= 0) {
    puts("0.0000000000");
    return 0;
  }
  double l = 0, r = 200000, mid;
  for (long long ci = (long long)(1); ci <= (long long)(50); ++ci) {
    mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%.10lf\n", mid);
}
