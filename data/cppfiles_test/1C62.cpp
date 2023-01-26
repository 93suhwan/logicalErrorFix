#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5;
const int ITERATION = 50;
const double EPS = (double)1e-9;
const double PI = (double)acos(-1.0);
pair<int, int> dat[N + 5];
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &dat[i].first, &dat[i].second);
  }
  double lo = (double)0.0;
  double hi = (double)3e5;
  for (int iteration = 0; iteration < ITERATION; iteration++) {
    double mid = (lo + hi) / (double)2.0;
    vector<pair<double, int> > temp;
    temp.clear();
    for (int i = 1; i <= n; i++) {
      const double x = dat[i].first;
      const double y = dat[i].second;
      double dist = hypot(x, y);
      double pivot = atan2(y, x);
      double angle = acos(dist / mid / (double)2.0);
      if (dist - (double)2.0 * mid > EPS) {
        continue;
      }
      for (int xxx = 0; xxx < 2; xxx++) {
        temp.push_back(make_pair(pivot - angle + (double)(2 * xxx) * PI, -1));
        temp.push_back(make_pair(pivot + angle + (double)(2 * xxx) * PI, 1));
      }
    }
    sort(temp.begin(), temp.end());
    int cnt = 0, maxx = 0;
    for (const auto& x : temp) {
      maxx = max(maxx, cnt -= x.second);
    }
    if (maxx < k) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  printf("%.10lf\n", (lo + hi) / (double)2.0);
  return 0;
}
