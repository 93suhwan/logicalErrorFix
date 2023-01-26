#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const long double inf = 1e18 + 42;
struct pt {
  long long x, y;
  bool operator<(const pt& o) const { return tie(x, y) < tie(o.x, o.y); }
  bool operator==(const pt& o) const { return tie(x, y) == tie(o.x, o.y); }
  long long dist2(const pt& o) {
    return (x - o.x) * (x - o.x) + (y - o.y) * (y - o.y);
  }
  long double dist(const pt& o) { return sqrt(dist2(o)); }
};
bool on_line(pt& p1, pt& p2, pt& p3);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  vector<pt> pts(n);
  for (auto& p : pts) {
    cin >> p.x >> p.y;
  }
  pt start = pts[k - 1];
  sort(pts.begin(), pts.end());
  int odd_id = 0;
  if (pts.size() > 3) {
    for (int i = 0; i < n; ++i) {
      vector<int> other;
      for (int j = 0; j < n and other.size() < 3; ++j) {
        if (i != j) {
          other.push_back(j);
        }
      }
      bool ok = false;
      ok |= on_line(pts[i], pts[other[0]], pts[other[1]]);
      ok |= on_line(pts[i], pts[other[0]], pts[other[2]]);
      ok |= on_line(pts[i], pts[other[1]], pts[other[2]]);
      if (!ok) {
        odd_id = i;
        break;
      }
    }
  }
  pt odd = pts[odd_id];
  pts.erase(pts.begin() + odd_id);
  n = pts.size();
  for (int i = 0; i < n; ++i) {
    if (pts[i] == start) {
      pts.erase(pts.begin() + i);
      n = pts.size();
      break;
    }
  }
  long double line_length = pts[0].dist(pts.back());
  long double start_odd = pts[0].dist(odd);
  long double start_p1 = pts[0].dist(start);
  long double start_pn = pts.back().dist(start);
  long double odd_p1 = odd.dist(pts[0]);
  long double odd_pn = odd.dist(pts.back());
  long double to_odd_and_back = inf;
  for (int i = 0; i < n - 1; ++i) {
    to_odd_and_back =
        min(to_odd_and_back,
            pts[i].dist(odd) + odd.dist(pts[i + 1]) - pts[i].dist(pts[i + 1]));
  }
  long double ans =
      min({start_odd + odd_p1 + line_length, start_odd + odd_pn + line_length,
           start_p1 + line_length + odd_pn, start_pn + line_length + odd_p1,
           start_p1 + to_odd_and_back + line_length,
           start_p1 + to_odd_and_back + line_length});
  cout << fixed << setprecision(10) << ans << endl;
}
bool on_line(pt& p1, pt& p2, pt& p3) {
  return (p2.x - p1.x) * (p3.y - p2.y) == (p3.x - p2.x) * (p2.y - p1.y);
}
