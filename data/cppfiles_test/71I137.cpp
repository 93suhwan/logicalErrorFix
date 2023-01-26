#include <bits/stdc++.h>
using namespace std;
struct point {
  long long x, y;
  point(long long _x = 0, long long _y = 0) : x(_x), y(_y) {}
  point operator+(point a) { return point(x + a.x, y + a.y); }
  point operator-(point a) { return point(x - a.x, y - a.y); }
  long long operator*(point a) { return x * a.y - a.x * y; }
  long long operator^(point a) { return x * a.x + y * a.y; }
  bool operator<(point a) const { return x < a.x or (x == a.x and y < a.y); }
  bool operator==(point a) { return x == a.x and y == a.y; }
  long long len2() { return ((*this) ^ (*this)); }
};
istream& operator>>(istream& in, point& a) {
  cin >> a.x >> a.y;
  return in;
}
double dist(point a, point b) { return sqrt((a - b).len2()); }
double dist(point a, point b, point c) {
  return abs((a - b) * (a - c)) / dist(b, c);
}
double area(point a, point b, point c) { return abs((b - a) * (c - a)) / 2.0; }
using line = pair<long long, long long>;
bool cmp(line a, line b) { return a.first * b.second == a.second * b.first; }
line get(point a, point b) { return make_pair(a.x - b.x, a.y - b.y); }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  --k;
  vector<point> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; ++i) {
    int j = (i - 1 + n) % n;
    int g = (i + 1) % n;
    if (!cmp(get(a[j], a[i]), get(a[i], a[g]))) {
      auto tmp = a[i];
      a.erase(a.begin() + i);
      a.push_back(tmp);
      if (i == k) {
        k = n - 1;
      } else if (i < k) {
        --k;
      }
      break;
    }
  }
  if (k == n - 1) {
    cout << dist(a[0], a[n - 2]) +
                min(dist(a[0], a[n - 1]), dist(a[n - 2], a[n - 1]));
    return 0;
  }
  double ans = 1e18;
  for (int i = 0; i < n - 1; ++i) {
    if (i >= k) {
      ans = min(ans, min(dist(a[k], a[i]) + dist(a[0], a[n - 1]),
                         dist(a[k], a[0]) + dist(a[i], a[n - 1])) +
                         dist(a[0], a[i]) +
                         (i + 1 < n - 1 ? dist(a[n - 1], a[i + 1]) +
                                              dist(a[i + 1], a[n - 2])
                                        : 0));
    }
    if (i <= k) {
      ans = min(
          ans,
          min(dist(a[k], a[i]) + dist(a[n - 2], a[n - 1]),
              dist(a[k], a[n - 2]) + dist(a[i], a[n - 1])) +
              dist(a[i], a[n - 2]) +
              (i > 0 ? dist(a[n - 1], a[i - 1]) + dist(a[i - 1], a[0]) : 0));
    }
  }
  cout << fixed << setprecision(10) << ans;
  return 0;
}
