#include <bits/stdc++.h>
using namespace std;
double dis(pair<long long, long long> p) {
  return sqrt(((p.first) * (p.first)) + ((p.second) * (p.second)));
}
void solve() {
  int n, k;
  scanf("%d %d", &n, &k);
  pair<long long, long long> p[100005];
  for (int i = 0; i < n; i++) {
    int first, second;
    scanf("%d %d", &first, &second);
    p[i] = make_pair(first, second);
  }
  double Max = 2e6, Min = 0;
  for (int i = 0; i < 100; i++) {
    double mid = (Max + Min) / 2;
    vector<pair<double, int> > v;
    for (int i = 0; i < n; i++) {
      if (p[i] == make_pair(0ll, 0ll)) {
        v.push_back(make_pair(-acos(-1), 1));
        continue;
      }
      if (dis(p[i]) + 1e-8 < 2 * mid) {
        double theta =
            acos((-dis(p[i]) * dis(p[i]) + mid * mid * 2) / (2 * mid * mid));
        theta = (acos(-1) - theta) / 2;
        double angle = atan2(p[i].second, p[i].first);
        double l = angle - theta, r = angle + theta;
        if (l > -acos(-1) && r < acos(-1)) {
          v.push_back(make_pair(l, 1));
          v.push_back(make_pair(r, -1));
        } else {
          if (l <= -acos(-1)) {
            v.push_back(make_pair(l + 2 * acos(-1), 1));
            v.push_back(make_pair(acos(-1), -1));
            v.push_back(make_pair(-acos(-1), 1));
            v.push_back(make_pair(r, -1));
          } else if (r >= acos(-1)) {
            v.push_back(make_pair(l, 1));
            v.push_back(make_pair(acos(-1), -1));
            v.push_back(make_pair(-acos(-1), 1));
            v.push_back(make_pair(r - 2 * acos(-1), -1));
          } else {
            assert(0);
          }
        }
      }
    }
    sort(v.begin(), v.end());
    int sum = 0;
    int ok = 0;
    for (auto it : v) {
      sum += it.second;
      if (sum >= k) ok = 1;
    }
    if (ok)
      Max = mid;
    else
      Min = mid;
  }
  printf("%.12f\n", Max);
}
int main() {
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
