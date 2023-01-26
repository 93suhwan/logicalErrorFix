#include <bits/stdc++.h>
double dist(long long x, long long y) { return sqrt(x * x + y * y); }
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int test;
  std::cin >> test;
  double inf = 1000.0 * 1000.0 * 1000.0;
  while (test--) {
    long long w, h;
    std::cin >> w >> h;
    long long x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    long long ww, hh;
    std::cin >> ww >> hh;
    double min_ans = inf;
    int x_intersect = std::max(0ll, ww - x1);
    int y_intersect = std::max(0ll, hh - y1);
    if (x2 + x_intersect <= w) {
      min_ans = std::min(min_ans, dist(x_intersect, 0ll));
    }
    if (y2 + y_intersect <= h) {
      min_ans = std::min(min_ans, dist(y_intersect, 0ll));
    }
    x_intersect = std::max(0ll, ww - x1);
    y_intersect = std::max(0ll, y2 - (h - hh));
    if (x2 + x_intersect <= w) {
      min_ans = std::min(min_ans, dist(x_intersect, 0ll));
    }
    if (y1 - y_intersect >= 0) {
      min_ans = std::min(min_ans, dist(y_intersect, 0ll));
    }
    x_intersect = std::max(0ll, x2 - (w - ww));
    y_intersect = std::max(0ll, hh - y1);
    if (x1 - x_intersect >= 0) {
      min_ans = std::min(min_ans, dist(x_intersect, 0ll));
    }
    if (y2 + y_intersect <= h) {
      min_ans = std::min(min_ans, dist(y_intersect, 0ll));
    }
    x_intersect = std::max(0ll, x2 - (w - ww));
    y_intersect = std::max(0ll, y2 - (h - hh));
    if (x1 - x_intersect >= 0) {
      min_ans = std::min(min_ans, dist(x_intersect, 0ll));
    }
    if (y1 - y_intersect >= 0) {
      min_ans = std::min(min_ans, dist(y_intersect, 0ll));
    }
    std::cout.precision(20);
    if (min_ans == inf) {
      std::cout << "-1\n";
    } else {
      std::cout << min_ans << "\n";
    }
  }
  return 0;
}
