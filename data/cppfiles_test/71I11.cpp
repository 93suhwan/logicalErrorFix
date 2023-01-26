#include <bits/stdc++.h>
using namespace std;
int n, k, l;
pair<long, long> p[200020], now;
double dis(pair<long, long> x, pair<long, long> y) {
  return sqrt((x.first - y.first) * (x.first - y.first) +
              (x.second - y.second) * (x.second - y.second));
}
int check() {
  for (int i = 1; i < 4; i++)
    for (int j = i + 1; j < 4; j++)
      if ((p[i].second - p[0].second) * (p[j].first - p[0].first) ==
          (p[i].first - p[0].first) * (p[j].second - p[0].second))
        return true;
  return false;
}
int find() {
  int o;
  for (int i = 1; i < 4; i++)
    for (int j = i + 1; j < 4; j++)
      if ((p[i].second - p[0].second) * (p[j].first - p[0].first) ==
          (p[i].first - p[0].first) * (p[j].second - p[0].second))
        o = i;
  for (int i = 1; i < n; i++)
    if ((p[i].second - p[0].second) * (p[o].first - p[0].first) !=
        (p[i].first - p[0].first) * (p[o].second - p[0].second))
      return i;
}
double calc(pair<long, long> x, pair<long, long> y, pair<long, long> z) {
  return min(dis(x, y), dis(x, z)) + dis(y, z);
}
int main() {
  scanf("%d%d", &n, &k);
  double res = 1e+12;
  k--;
  for (int i = 0; i < n; i++) scanf("%lld%lld", &p[i].first, &p[i].second);
  if (n == 3) {
    swap(p[0], p[k]);
    res = calc(p[0], p[1], p[2]);
  } else {
    if (!check()) {
      swap(p[0], p[1]);
      if (k < 2) k = k ^ 1;
    }
    int tmp = find();
    swap(p[tmp], p[n - 1]);
    if (k == tmp)
      k = n - 1;
    else if (k == n - 1)
      k = tmp;
    now = p[k];
    sort(p, p + n - 1);
    l = n;
    for (int i = 0; i < n; i++)
      if (p[i] == now) {
        l = min(l, i);
        k = i;
      }
    if (k == n - 1) {
      res = calc(p[k], p[0], p[n - 2]);
    } else {
      res = dis(p[k], p[n - 1]) + calc(p[n - 1], p[0], p[n - 2]);
      res = min(res, dis(p[k], p[0]) + dis(p[0], p[n - 1]) +
                         (k != n - 2) * (calc(p[n - 1], p[k + 1], p[n - 2])));
      res = min(res, dis(p[k], p[n - 2]) + dis(p[n - 2], p[n - 1]) +
                         (l != 0) * (calc(p[n - 1], p[l - 1], p[0])));
      for (int i = 0; i < l; i++) {
        res = min(res, dis(p[k], p[n - 2]) + dis(p[n - 2], p[i]) +
                           dis(p[i], p[n - 1]) +
                           (i != 0) * (calc(p[n - 1], p[0], p[i - 1])));
      }
      for (int i = k + 1; i < n - 1; i++) {
        res = min(res, dis(p[k], p[0]) + dis(p[0], p[i]) + dis(p[i], p[n - 1]) +
                           (i != n - 2) * (calc(p[n - 1], p[i + 1], p[n - 2])));
      }
    }
  }
  printf("%.6lf\n", res);
}
