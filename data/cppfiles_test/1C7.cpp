#include <bits/stdc++.h>
using namespace std;
const int sz = 4e5 + 5;
pair<int, int> bb[sz];
pair<double, double> a[sz];
bool ya[sz];
inline double dis(pair<double, double> a, pair<double, double> b) {
  double first = a.first - b.first, second = a.second - b.second;
  return first * first + second * second;
}
const double eps = 1e-10;
bool cmp(pair<pair<double, double>, int> a, pair<pair<double, double>, int> b) {
  if (abs(a.first.first - b.first.first) < eps and
      abs(a.first.second - b.first.second) < eps)
    return a.second > b.second;
  if (a.first.second * b.first.second < 0)
    return a.first.second < b.first.second;
  if (a.first.second <= 0) return a.first.first < b.first.first;
  return a.first.first > b.first.first;
}
pair<pair<double, double>, int> ara[sz];
int main() {
  int n, need;
  cin >> n >> need;
  for (int i = 0; i < n; i++) scanf("%d %d", &bb[i].first, &bb[i].second);
  int nc = 0;
  for (int i = 0; i < n; i++) {
    if (!bb[i].first and !bb[i].second) {
      need--;
      continue;
    }
    a[nc++] = bb[i];
  }
  n = nc;
  double lo = 0, hi = 2e5;
  int cc = 32;
  while (cc--) {
    double r = (lo + hi) / 2;
    int z = 0;
    for (int i = 0; i < n; i++) {
      pair<double, double> c = a[i], m = a[i];
      double val = r * r - dis(m, {0, 0}) / 4;
      if (val < 0) continue;
      double d = sqrtl(val);
      c.first /= 2;
      c.second /= 2;
      swap(m.first, m.second);
      double hmm = hypot(m.first, m.second);
      m.second *= -1;
      pair<double, double> a1 = c;
      a1.first += m.first * d / hmm;
      a1.second += m.second * d / hmm;
      ara[z++] = {a1, +(i + 1)};
      m.second *= -1;
      m.first *= -1;
      pair<double, double> a2 = c;
      a2.first += m.first * d / hmm;
      a2.second += m.second * d / hmm;
      ara[z++] = {a2, -(i + 1)};
    }
    sort(ara, ara + z, cmp);
    for (int i = 0; i < z; i++) ara[z + i] = ara[i];
    z <<= 1;
    int cnt = 0, res = 0;
    memset(ya, 0, sizeof ya);
    for (int i = 0; i < z; i++) {
      int k = ara[i].second;
      if (k > 0 and !ya[k]) cnt++, ya[k] = 1;
      if (k < 0 and ya[-k]) cnt--, ya[-k] = 0;
      res = max(res, cnt);
    }
    if (res >= need)
      hi = r;
    else
      lo = r;
  }
  printf("%.10f\n", (double)lo);
}
