#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using VI = vector<int>;
using VL = vector<LL>;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
void dout() { cerr << endl; }
template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
  cerr << H << ' ';
  dout(T...);
}
const double PI = acos(-1.0);
const double EPS = 1e-9;
const int MAX = 1 << 17;
struct Point {
  int x, y;
} p[MAX];
int n, k;
double d[MAX], theta[MAX];
bool is[MAX];
pair<double, int> events[2 * MAX];
bool ok(double r) {
  int cnt = 0;
  int sz = 0;
  for (int i = (0); i < (n); ++i) {
    if (p[i].x == 0 && p[i].y == 0) continue;
    if (d[i] < 2 * r - EPS) {
      double alpha = acos(d[i] / (2 * r));
      events[sz++] = {theta[i] - alpha, (i + 1)};
      events[sz++] = {theta[i] + alpha, -(i + 1)};
    }
    is[i] = hypot(p[i].x - r, p[i].y) < r + EPS;
    if (is[i]) cnt++;
  }
  if (cnt >= k) return true;
  for (int i = (0); i < (sz); ++i) {
    while (events[i].first < 0) events[i].first += 2 * PI;
    while (events[i].first >= 2 * PI) events[i].first -= 2 * PI;
  }
  sort(events, events + sz);
  for (int i = (0); i < (sz); ++i) {
    int idx = abs(events[i].second) - 1;
    bool insert = events[i].second > 0;
    if (insert) {
      if (!is[idx]) {
        is[idx] = true;
        cnt++;
      }
    } else {
      if (is[idx]) {
        is[idx] = false;
        cnt--;
      }
    }
    if (cnt >= k) return true;
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);
  cin >> n >> k;
  for (int i = (0); i < (n); ++i) {
    cin >> p[i].x >> p[i].y;
    if (p[i].x == 0 && p[i].y == 0) {
      k--;
      continue;
    }
    d[i] = hypot(p[i].x, p[i].y);
    theta[i] = atan2(p[i].y, p[i].x);
  }
  double l = 0, r = 2e5;
  for (int it = (0); it < (40); ++it) {
    double m = (l + r) / 2;
    if (ok(m))
      r = m;
    else
      l = m;
  }
  cout << l << "\n";
}
