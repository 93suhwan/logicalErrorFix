#include <bits/stdc++.h>
using namespace std;
int n;
int k;
vector<pair<long double, long double> > vp;
const long double PI = 2 * acos(0.0);
bool check(long double r) {
  vector<pair<long double, int> > events;
  for (int i = 0; i < n; ++i) {
    long double ang = atan2(vp[i].second, vp[i].first);
    long double d =
        sqrt(vp[i].first * vp[i].first + vp[i].second * vp[i].second);
    if (d > 2 * r) continue;
    long double alph = (PI - acos(1 - (d * d) / (2 * (r * r)))) / 2;
    long double ang_in = ang - alph;
    long double ang_out = ang + alph;
    if (ang_in < 0) {
      ang_in += 2 * PI;
      ang_out += 2 * PI;
    }
    events.emplace_back(ang_in, 1);
    events.emplace_back(ang_out, -1);
    events.emplace_back(ang_in + 2 * PI, 1);
    events.emplace_back(ang_out + 2 * PI, -1);
  }
  sort(events.begin(), events.end());
  int ck = 0;
  for (int i = 0; i < (int)events.size(); ++i) {
    ck += events[i].second;
    if (ck >= k) return true;
  }
  return false;
}
int main() {
  cout.setf(ios::fixed);
  cout << setprecision(10);
  cin >> n;
  cin >> k;
  for (int i = 0; i < n; ++i) {
    int first, second;
    cin >> first >> second;
    vp.emplace_back(first, second);
  }
  long double l = 0;
  long double r = 2e5;
  while (r - l > 1e-6) {
    long double mid = (l + r) / 2;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << l << endl;
}
