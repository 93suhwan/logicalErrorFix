#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long long INF = 0x3f3f3f3f;
const long long inf = pow(10, 18);
long long modulo = pow(10, 9) + 7;
double todeg(double a) { return a * 180 / acos(-1.0); }
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
      double ang = atan2(arr[j].second, arr[j].first);
      double lef, rig;
      double lo1 = ang - acos(-1.0), hi1 = ang;
      for (long long k = 0; k < 12; k++) {
        double mid1 = (lo1 + hi1) / 2;
        double x = cos(mid1) * r, y = sin(mid1) * r;
        if ((x - arr[j].first) * (x - arr[j].first) +
                (y - arr[j].second) * (y - arr[j].second) <=
            r * r) {
          hi1 = mid1;
        } else {
          lo1 = mid1;
        }
      }
      lef = (lo1 + hi1) / 2;
      lo1 = ang, hi1 = ang + acos(-1.0);
      for (long long k = 0; k < 12; k++) {
        double mid1 = (lo1 + hi1) / 2;
        double x = cos(mid1) * r, y = sin(mid1) * r;
        if ((x - arr[j].first) * (x - arr[j].first) +
                (y - arr[j].second) * (y - arr[j].second) <=
            r * r) {
          lo1 = mid1;
        } else {
          hi1 = mid1;
        }
      }
      rig = (lo1 + hi1) / 2;
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
