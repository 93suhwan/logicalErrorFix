#include <bits/stdc++.h>
namespace {
using LL = long long;
struct Point {
  int x, y;
};
Point operator-(const Point& lhs, const Point& rhs) {
  return Point{.x = lhs.x - rhs.x, .y = lhs.y - rhs.y};
}
LL det(const Point& lhs, const Point& rhs) {
  return lhs.x * 1LL * rhs.y - lhs.y * 1LL * rhs.x;
}
LL get_area(const Point& a, const Point& b, const Point& c) {
  return std::abs(det(b - a, c - a));
}
template <typename T>
void enlarge(T& a, T b) {
  if (a < b) a = b;
}
struct Solver {
  int n, k;
  std::vector<Point> points;
  using State = std::pair<LL, LL>;
  std::vector<std::vector<State>> dp;
  int next(int p) const { return (p + 1) % n; }
  static State merge(const State& lhs, const State& rhs, LL extra,
                     LL area_limit) {
    State ret(lhs.first + rhs.first, lhs.second + rhs.second + extra);
    if (ret.second >= area_limit) {
      ret.second = 0;
      ++ret.first;
    }
    return ret;
  }
  State calc(int l, int r, LL area_limit) {
    if (dp[l][r].first >= 0) {
      return dp[l][r];
    }
    assert(l != r);
    if (next(l) == r) {
      return dp[l][r] = State(0, 0);
    }
    for (int i = next(l); i != r; i = next(i)) {
      LL extra = get_area(points[l], points[r], points[i]);
      enlarge(dp[l][r], merge(calc(l, i, area_limit), calc(i, r, area_limit),
                              extra, area_limit));
    }
    return dp[l][r];
  }
  LL check(LL area_limit) {
    std::vector<std::vector<State>>(n, std::vector<State>(n, State(-1ll, 0ll)))
        .swap(dp);
    return calc(0, n - 1, area_limit).first >= k + 1;
  }
  LL solve() {
    LL l = 1, r = 9e18;
    while (l <= r) {
      LL mid = l + (r - l) / 2;
      if (check(mid)) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return l - 1;
  }
  void solve(int ca, std::istream& reader) {
    reader >> n >> k;
    points.resize(n);
    for (int i = 0; i < n; ++i) {
      reader >> points[i].x >> points[i].y;
    }
    printf("%lld\n", solve());
  }
};
}  // namespace
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::istream& reader = std::cin;
  int cas = 1;
  for (int ca = 1; ca <= cas; ++ca) {
    Solver().solve(ca, reader);
  }
}
