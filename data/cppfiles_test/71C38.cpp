#include <bits/stdc++.h>
constexpr double EPS = 1e-8;
constexpr double DOUBLE_INF = 1e40;
constexpr int N = 200000 + 10;
struct Point {
  double x, y;
  Point() : x{0}, y{0} {}
  Point(double _x, double _y) : x{_x}, y{_y} {}
  friend bool operator==(const Point& a, const Point& b) {
    return std::fabs(a.x - b.x) < EPS && std::fabs(a.y - b.y) < EPS;
  }
  static double distance(const Point& a, const Point& b) {
    return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
  }
};
int n, start;
Point p[N];
Point out;
std::vector<Point> line;
void ReadData() {
  scanf("%d %d", &n, &start);
  for (int i = 1; i <= n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    p[i].x = x;
    p[i].y = y;
  }
}
bool CoLine(const Point& a, const Point& b, const Point& c) {
  return std::fabs((b.y - a.y) * (c.x - a.x) - (c.y - a.y) * (b.x - a.x)) < EPS;
}
void FindLine() {
  if (n == 3) {
    out = p[start];
    for (int i = 1; i <= n; ++i) {
      if (i != start) {
        line.push_back(p[i]);
      }
    }
  } else {
    for (int i = 1; i <= n; ++i) {
      std::vector<Point> a;
      for (int j = -3; j <= 3 && a.size() < 3; ++j) {
        if (j != 0 && 1 <= i + j && i + j <= n) {
          a.push_back(p[i + j]);
        }
      }
      if (CoLine(a[0], a[1], a[2]) && !CoLine(p[i], a[0], a[1])) {
        out = p[i];
        for (int j = 1; j <= n; ++j) {
          if (j != i) {
            line.push_back(p[j]);
          }
        }
        bool samex = true;
        for (int j = 1; j < n - 1; ++j) {
          if (std::fabs(line[j].x - line[0].x) >= EPS) {
            samex = false;
            break;
          }
        }
        if (samex) {
          std::sort(line.begin(), line.end(),
                    [](const Point& a, const Point& b) { return a.y < b.y; });
        } else {
          std::sort(line.begin(), line.end(),
                    [](const Point& a, const Point& b) { return a.x < b.x; });
        }
        return;
      }
    }
  }
}
void Solve1() {
  double ans = DOUBLE_INF;
  double base = Point::distance(line[0], line[n - 2]);
  for (int i = 0; i < n - 1; ++i) {
    ans = std::min(ans, Point::distance(p[start], line[i]) + base +
                            std::min(Point::distance(line[i], line[0]),
                                     Point::distance(line[i], line[n - 2])));
  }
  printf("%.10lf\n", ans);
}
void Solve2() {
  double ans = DOUBLE_INF;
  double base = Point::distance(line[0], line[n - 2]);
  int t = -1;
  for (int i = 0; i < n - 1; ++i) {
    if (line[i] == p[start]) {
      t = i;
      break;
    }
  }
  for (int i = t; i > 0; --i) {
    ans = std::min(ans, base + Point::distance(line[t], line[0]) -
                            Point::distance(line[i], line[i - 1]) +
                            Point::distance(line[i], out) +
                            Point::distance(out, line[i - 1]));
  }
  if (t < n - 2) {
    ans = std::min(ans, base - Point::distance(line[t], line[t + 1]) +
                            Point::distance(line[0], out) +
                            Point::distance(out, line[t + 1]));
  }
  for (int i = t; i < n - 2; ++i) {
    ans = std::min(ans, base + Point::distance(line[t], line[0]) -
                            Point::distance(line[i], line[i + 1]) +
                            Point::distance(line[i], out) +
                            Point::distance(out, line[i + 1]));
  }
  ans = std::min(ans, base + Point::distance(line[t], line[0]) +
                          Point::distance(line[n - 2], out));
  for (int i = t; i < n - 2; ++i) {
    ans = std::min(ans, base + Point::distance(line[t], line[n - 2]) -
                            Point::distance(line[i], line[i + 1]) +
                            Point::distance(line[i], out) +
                            Point::distance(out, line[i + 1]));
  }
  if (t > 0) {
    ans = std::min(ans, base - Point::distance(line[t], line[t - 1]) +
                            Point::distance(line[n - 2], out) +
                            Point::distance(out, line[t - 1]));
  }
  for (int i = t; i > 0; --i) {
    ans = std::min(ans, base + Point::distance(line[t], line[n - 2]) -
                            Point::distance(line[i], line[i - 1]) +
                            Point::distance(line[i], out) +
                            Point::distance(out, line[i - 1]));
  }
  ans = std::min(ans, base + Point::distance(line[t], line[n - 2]) +
                          Point::distance(line[0], out));
  printf("%.10lf\n", ans);
}
int main() {
  ReadData();
  FindLine();
  if (out == p[start]) {
    Solve1();
  } else {
    Solve2();
  }
  return 0;
}
