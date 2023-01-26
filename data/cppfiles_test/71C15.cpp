#include <bits/stdc++.h>
using namespace std;
struct Point {
  long long first, second, ind;
  Point(long long first = 0, long long second = 0, long long id = 0)
      : first(first), second(second), ind(id) {}
};
long double dist(Point a, Point b) {
  return sqrtl((long double)((a.first - b.first) * (a.first - b.first) +
                             (a.second - b.second) * (a.second - b.second)));
}
struct Line {
  long long a, b, c;
  Line(long long a, long long b, long long c) : a(a), b(b), c(c) {}
  Line(Point p, Point q) {
    a = p.second - q.second;
    b = q.first - p.first;
    c = -a * p.first - b * p.second;
  }
  long long operator()(Point p) { return a * p.first + b * p.second + c; }
};
long double solve_from_out(Point p, vector<Point> v) {
  return min(dist(p, v[0]), dist(p, v.back())) + dist(v[0], v.back());
}
long double solve_from_first(Point p, vector<Point> v) {
  long double ans = dist(v[0], v.back()) + dist(v.back(), p);
  for (int i = 0; i + 1 < (static_cast<int>((v).size())); i++) {
    ans = min(ans, dist(v[0], v[i]) + dist(v[i], p) + dist(p, v[i + 1]) +
                       dist(v[i + 1], v.back()));
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  mt19937 rnd(239);
  cin >> n >> k;
  vector<Point> v;
  for (int i = 0; i < n; i++) {
    long long a, b, id = i + 1;
    cin >> a >> b;
    v.emplace_back(a, b, id);
  }
  sort(v.begin(), v.end(), [&](const Point& p, const Point& q) -> bool {
    if (p.first != q.first) {
      return p.first < q.first;
    } else {
      return p.second < q.second;
    }
  });
  Line opt(v[0], v[1]);
  int pos = -1;
  while (true) {
    int cnt = 0;
    pos = 0;
    for (int i = 0; i < n; i++) {
      if (opt(v[i]) != 0) {
        cnt++;
        pos = i;
      }
    }
    if (cnt > 1) {
      int first = rnd() % (static_cast<int>((v).size()));
      int second = first;
      while (second == first) {
        second = rnd() % (static_cast<int>((v).size()));
      }
      opt = Line(v[first], v[second]);
    } else {
      break;
    }
  }
  Point p = v[pos];
  v.erase(v.begin() + pos);
  cout << fixed << setprecision(30);
  if (k == p.ind) {
    cout << solve_from_out(p, v) << endl;
    return 0;
  }
  if (k == v[0].ind) {
    cout << solve_from_first(p, v) << endl;
    return 0;
  }
  reverse(v.begin(), v.end());
  if (k == v[0].ind) {
    cout << solve_from_first(p, v) << endl;
    return 0;
  }
  long double ans = 1e18;
  int st = 0;
  while (v[st].ind != k) {
    st++;
  }
  ans = min(ans, dist(v[st], p) + solve_from_out(p, v));
  vector<Point> u;
  u.push_back(v[0]);
  for (int i = st + 1; i < (static_cast<int>((v).size())); i++) {
    u.push_back(v[i]);
  }
  ans = min(ans, dist(v[0], v[st]) + solve_from_first(p, u));
  u.clear();
  u.push_back(v.back());
  for (int i = st - 1; i >= 0; i--) {
    u.push_back(v[i]);
  }
  ans = min(ans, dist(v.back(), v[st]) + solve_from_first(p, u));
  cout << ans << endl;
  return 0;
}
