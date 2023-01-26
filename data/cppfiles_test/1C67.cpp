#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long long INF = 0x3f3f3f3f;
const long long inf = pow(10, 18);
long long modulo = pow(10, 9) + 7;
double todeg(double a) { return a * 180 / acos(-1.0); }
void fix(double& lef, double& rig) {
  if (rig < lef) {
    swap(lef, rig);
  }
  if (rig - lef > acos(-1.0)) {
    lef += 2 * acos(-1.0);
    swap(lef, rig);
  }
  while ((lef + rig) / 2 > acos(-1.0)) {
    lef -= 2 * acos(-1.0);
    rig -= 2 * acos(-1.0);
  }
  while ((lef + rig) / 2 < -acos(-1.0)) {
    lef += 2 * acos(-1.0);
    rig += 2 * acos(-1.0);
  }
}
void pointOnCircle(double xc, double yc, double x, double y, double r) {
  assert(abs(sqrt((x - xc) * (x - xc) + (y - yc) * (y - yc)) - r) <= 1e-4);
}
void deal() {
  long long n, need;
  cin >> n >> need;
  vector<pair<long long, long long> > arr(n);
  for (long long i = 0; i < n; i++) {
    cin >> arr[i].first >> arr[i].second;
  }
  double lo = 0, hi = 2e5;
  while ((hi - lo) / max(1.0, hi) > 1e-4) {
    double mid = (lo + hi) / 2;
    double r = mid;
    vector<pair<double, long long> > all;
    for (long long j = 0; j < n; j++) {
      if (arr[j].second * arr[j].second + arr[j].first * arr[j].first >
          4 * r * r) {
        continue;
      }
      double lef, rig;
      double x1 = arr[j].first, y1 = arr[j].second;
      if (x1 != 0) {
        double val1 = y1 * y1 + x1 * x1;
        double val2 = 2 * y1;
        double a = -4 * x1 * x1 - val2 * val2;
        double b = 2 * val1 * val2;
        double c = -val1 * val1 + 4 * x1 * x1 * r * r;
        double D = b * b - 4 * a * c;
        double kok = sqrt(D);
        double ya = (-b + kok) / (2 * a), yb = (-b - kok) / (2 * a);
        double xa = (y1 * y1 + x1 * x1 - 2 * ya * y1) / (2 * x1);
        double xb = (y1 * y1 + x1 * x1 - 2 * yb * y1) / (2 * x1);
        lef = atan2(ya, xa);
        rig = atan2(yb, xb);
        fix(lef, rig);
      } else {
        if (y1 != 0) {
          double val1 = x1 * x1 + y1 * y1;
          double val2 = 2 * x1;
          double a = -4 * y1 * y1 - val2 * val2;
          double b = 2 * val1 * val2;
          double c = -val1 * val1 + 4 * y1 * y1 * r * r;
          double D = b * b - 4 * a * c;
          double kok = sqrt(D);
          double xa = (-b + kok) / (2 * a), xb = (-b - kok) / (2 * a);
          double ya = (y1 * y1 + x1 * x1 - 2 * xa * x1) / (2 * y1);
          double yb = (y1 * y1 + x1 * x1 - 2 * xb * x1) / (2 * y1);
          lef = atan2(ya, xa);
          rig = atan2(yb, xb);
          fix(lef, rig);
        } else {
          lef = 0, rig = 2 * acos(-1.0);
        }
      }
      for (long long k = -1; k <= 1; k++) {
        all.push_back(make_pair(lef + 2 * k * acos(-1.0), 1));
        all.push_back(make_pair(rig + 2 * k * acos(-1.0), -1));
      }
    }
    sort(all.begin(), all.end());
    long long mx = 0;
    long long s = 0;
    for (auto& el : all) {
      s += el.second;
      mx = max(mx, s);
    }
    if (mx >= need) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  cout << setprecision(13) << fixed << (lo + hi) / 2;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  deal();
}
