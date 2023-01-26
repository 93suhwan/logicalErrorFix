#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;
const double EPS = 0.000000001;
const double Pi = acos(-1.0);
struct ban {
  double x, y;
  ban() { x = y = 0; }
};
double dist(const ban& t1, const ban& t2) {
  return sqrt((t1.x - t2.x) * (t1.x - t2.x) + (t1.y - t2.y) * (t1.y - t2.y));
}
int n, k;
ban a[N];
double d[N];
double ang[N];
bool stg(double R) {
  vector<pair<double, int> > v;
  for (int i = 1; i <= n; ++i) {
    if (d[i] > R * 2) continue;
    double u = acos(d[i] / 2 / R);
    double l = ang[i] - u;
    double r = ang[i] + u;
    if (l < 0) l += 2 * Pi;
    if (r < 0) r += 2 * Pi;
    if (l <= r) {
      v.push_back(make_pair(l, 1));
      v.push_back(make_pair(r + EPS, -1));
    } else {
      v.push_back(make_pair(0, 1));
      v.push_back(make_pair(r + EPS, -1));
      v.push_back(make_pair(l, 1));
      v.push_back(make_pair(2 * Pi + EPS, -1));
    }
  }
  sort((v).begin(), (v).end());
  int q = 0;
  for (int i = 0; i < ((int)(v).size()); ++i) {
    q += v[i].second;
    if (q >= k) return true;
  }
  if (q >= k) return true;
  return false;
}
void solv() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].x >> a[i].y;
    if (a[i].x == 0 && a[i].y == 0) {
      --k;
      a[i].x = 1000000;
      a[i].y = 1000000;
    }
    d[i] = dist(ban(), a[i]);
    ang[i] = atan2(a[i].y, a[i].x);
  }
  double l = 0, r = N * 2;
  for (int ii = 0; ii < 50; ++ii) {
    double m = (l + r) / 2;
    if (stg(m))
      r = m;
    else
      l = m;
  }
  cout << r << "\n";
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(9);
  int tt = 1;
  while (tt--) solv();
  return 0;
}
