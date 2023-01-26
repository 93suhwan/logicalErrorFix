#include <bits/stdc++.h>
inline double dis(std::pair<double, double> x, std::pair<double, double> y) {
  return std::sqrt((x.first - y.first) * (x.first - y.first) +
                   (x.second - y.second) * (x.second - y.second));
}
inline bool chk(std::pair<double, double> x, std::pair<double, double> y,
                std::pair<double, double> z) {
  return std::fabs((y.first - x.first) * (z.second - x.second) -
                   (z.first - x.first) * (y.second - x.second)) < 1e-9;
}
int n, m;
std::pair<double, double> a[200005], b;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%lf%lf", &a[i].first, &a[i].second);
  b = a[m];
  if (chk(a[1], a[2], a[3])) {
    for (int i = 4; i <= n; i++)
      if (!chk(a[1], a[2], a[i])) {
        std::swap(a[i], a[n]);
        break;
      }
  } else if (n > 3) {
    if (chk(a[1], a[2], a[4]))
      std::swap(a[3], a[n]);
    else if (chk(a[1], a[3], a[4]))
      std::swap(a[2], a[n]);
    else
      std::swap(a[1], a[n]);
  }
  std::sort(a + 1, a + n);
  for (int i = 1; i <= n; i++)
    if (a[i] == b) m = i;
  if (m == n)
    return printf("%.11lf\n", std::min(dis(a[n], a[1]), dis(a[n], a[n - 1])) +
                                  dis(a[1], a[n - 1])),
           0;
  double ans =
      dis(a[1], a[n - 1]) + std::min(dis(a[m], a[1]) + dis(a[n - 1], a[n]),
                                     dis(a[m], a[n - 1]) + dis(a[1], a[n]));
  for (int i = 1; i < n - 1; i++) {
    std::pair<double, double> A = a[i], B = a[i + 1], C = a[1], D = a[n - 1];
    if (i < m) std::swap(A, B), std::swap(C, D);
    ans = std::min(ans, std::min(dis(a[m], A) + dis(A, C) + dis(C, a[n]) +
                                     dis(a[n], B) + dis(B, D),
                                 dis(a[m], C) + dis(C, A) + dis(A, a[n]) +
                                     dis(a[n], B) + dis(B, D)));
  }
  printf("%.11lf\n", ans);
}
