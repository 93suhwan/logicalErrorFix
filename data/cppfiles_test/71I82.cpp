#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char c = getchar();
  long long first = 0;
  bool f = 0;
  for (; !isdigit(c); c = getchar()) f ^= !(c ^ 45);
  for (; isdigit(c); c = getchar())
    first = (first << 1) + (first << 3) + (c ^ 48);
  if (f) first = -first;
  return first;
}
const long long inf = 1e18;
const double eps = 1e-12;
const long long M = 2e5 + 10;
long long n, s;
double sum[M];
pair<long long, long long> d[M];
double dis(pair<long long, long long> d1, pair<long long, long long> d2) {
  double p = (d1.first - d2.first) * (d1.first - d2.first) +
             (d1.second - d2.second) * (d1.second - d2.second);
  return sqrt(p);
}
void SWAP(long long first, long long second) {
  swap(d[first], d[second]);
  if (first == s) s = second;
}
pair<double, double> get(pair<long long, long long> a,
                         pair<long long, long long> b) {
  long long dx = a.first - b.first, dy = a.second - b.second;
  if (dy == 0)
    return make_pair(inf, 0.0);
  else
    return make_pair(dx * 1.0 / dy, a.second - dx * 1.0 / dy * a.first);
}
bool check(long long a, long long b, long long c) {
  pair<double, double> x1 = get(d[a], d[b]), x2 = get(d[b], d[c]);
  return fabs(x1.first - x2.first) <= eps && fabs(x1.second - x2.second) <= eps;
}
signed main() {
  n = read(), s = read();
  for (long long i = 1; i <= n; i++) d[i].first = read(), d[i].second = read();
  if (n > 3) {
    if (check(1, 2, 4))
      SWAP(3, 4);
    else if (check(1, 3, 4))
      SWAP(2, 4);
    else if (check(2, 3, 4))
      SWAP(1, 4);
    for (long long i = 4; i <= n; i++)
      if (!check(1, 2, i)) SWAP(i, n);
  }
  if (s == n) {
    sort(d + 1, d + n);
    double ans = inf;
    for (long long i = 2; i < n; i++) sum[i] = sum[i - 1] + dis(d[i], d[i - 1]);
    for (long long i = 1; i < n; i++)
      ans = min(ans, sum[n - 1] + min(sum[i], sum[n - 1] - sum[i - 1]) +
                         dis(d[n], d[i]));
    printf("%.12lf", ans);
    return 0;
  }
  pair<long long, long long> first = d[s];
  sort(d + 1, d + n);
  for (long long i = 1; i < n; i++) {
    if (first == d[i]) s = i;
    if (i != 1) sum[i] = sum[i - 1] + dis(d[i], d[i - 1]);
  }
  pair<double, double> X = get(d[1], d[2]);
  double k = X.first <= eps ? inf : 1.0 / X.first;
  double ans = min(
      sum[n - 1] - sum[s] + dis(d[n], d[n - 1]) +
          (s == 1 ? 0 : min(dis(d[n], d[s - 1]), dis(d[n], d[1])) + sum[s - 1]),
      sum[s] + dis(d[1], d[n]) +
          (s == n ? 0
                  : (min(dis(d[n], d[s + 1]), dis(d[n], d[n - 1])) +
                     sum[n - 1] - sum[s + 1])));
  double b = d[n].second - k * d[n].first;
  double dx = (b - X.second) * 1.0 / (X.first - k);
  long long l = 0;
  for (long long i = 1; i < n; i++)
    if ((fabs(dx - d[i].first) < eps) || dx < d[i].first) l = i;
  if (l != 0 && l != n - 1) {
    double val = inf;
    if (fabs(dx - d[l].first) < eps)
      val = min(dis(d[n], d[l + 1]) - dis(d[l], d[l + 1]),
                dis(d[n], d[l - 1]) - dis(d[l], d[l - 1])) +
            dis(d[n], d[l]);
    else
      val = dis(d[n], d[l]) + dis(d[n], d[l + 1]) - dis(d[l], d[l + 1]);
    ans = min(ans, val + sum[n - 1] + min(sum[s], sum[n - 1] - sum[s - 1]));
  }
  printf("%.12lf", ans);
  return 0;
}
