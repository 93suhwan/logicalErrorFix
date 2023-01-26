#include <bits/stdc++.h>
using namespace std;
struct point {
  int x, y;
  friend point operator-(const point& a, const point& b) {
    return {a.x - b.x, a.y - b.y};
  }
  friend constexpr long long cross(const point& a, const point& b) {
    return (long long)a.x * b.y - (long long)a.y * b.x;
  }
  friend string to_string(point p) {
    return "(" + to_string(p.x) + ", " + to_string(p.y) + ")";
  }
  friend istream& operator>>(istream& stream, point& p) {
    return stream >> p.x >> p.y;
  }
};
long long polygon_area(const vector<point>& p) {
  assert(p.size() >= 3);
  long long area = 0;
  for (int i = 2; i < (int)p.size(); i++) {
    area += cross(p[0] - p[i - 1], p[0] - p[i]);
  }
  return area;
}
void foo() {
  int n, cuts;
  cin >> n >> cuts;
  vector<point> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  auto add = [&](int a, int b) -> int { return (a + b) % n; };
  vector<vector<long long>> area(n, vector<long long>(n, -1));
  for (int i = 0; i < n; i++) {
    for (int j = add(i, 2); j != i; j = add(j, 1)) {
      vector<point> pt;
      for (int k = i;; k = add(k, 1)) {
        pt.push_back(p[k]);
        if (k == j) break;
      }
      area[i][j] = polygon_area(pt);
    }
  }
  const long long INF = 2e18 + 10;
  long long lo = 1, hi = INF;
  while (lo <= hi) {
    const long long m = lo + (hi - lo) / 2;
    const int inf = 1e8 + 5;
    vector<vector<int>> dp(n, vector<int>(n, -inf));
    for (int len = 3; len <= n; len++) {
      for (int i = 0; i < n; i++) {
        const int j = add(i, len - 1);
        int mx = -inf;
        if (area[i][j] >= m) mx = 0;
        for (int k = add(i, 1); k != j; k = add(k, 1)) {
          if (area[i][j] - area[i][k] - area[k][j] >= m) {
            mx = max(mx, dp[i][k] + dp[k][j] + 2);
          }
        }
        int ptr = add(i, 2);
        for (int k = i; k != add(j, n - 1); k = add(k, 1)) {
          if (ptr == add(k, 1)) add(ptr, 1);
          while (ptr != j) {
            if (area[ptr][k] - area[j][i] >= m) {
              mx = max(mx, dp[k][ptr] + 1);
              ptr = add(ptr, 1);
            } else {
              break;
            }
          }
          if (area[ptr][k] - area[j][i] >= m) {
            mx = max(mx, dp[k][ptr] + 1);
          }
        }
        dp[i][j] = mx;
      }
    }
    int best = -1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        best = max(best, dp[i][j] + dp[j][i] + 1);
      }
    }
    if (best >= cuts) {
      lo = m + 1;
    } else {
      hi = m - 1;
    }
  }
  long long ans = lo - 1;
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  foo();
}
