#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
bool Equal(double a, double b) { return (a - b < EPS) && (b - a < EPS); }
struct Point {
  int x, y;
  int ind;
};
double slope(Point A, Point B) { return 1.0 * (B.y - A.y) / (B.x - A.x); }
bool onLine(Point A, Point B, Point C) {
  return (A.x == B.x && B.x == C.x) || Equal(slope(A, B), slope(A, C));
}
bool operator<(Point A, Point B) {
  if (A.x != B.x) return A.x < B.x;
  return A.y < B.y;
}
double dist(Point A, Point B) {
  return sqrt(1.0 * (A.x - B.x) * (A.x - B.x) +
              1.0 * (A.y - B.y) * (A.y - B.y));
}
int n, k;
Point p[200200];
double getdistsum(int l, int r) {
  if (l > r) return 0;
  return min(dist(p[n - 1], p[l]), dist(p[n - 1], p[r])) + dist(p[l], p[r]);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  k--;
  for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y, p[i].ind = i;
  if (n > 3) {
    if (!onLine(p[0], p[1], p[2])) {
      if (onLine(p[0], p[1], p[3]))
        swap(p[2], p[n - 1]);
      else if (onLine(p[0], p[2], p[3]))
        swap(p[1], p[n - 1]);
      else
        swap(p[0], p[n - 1]);
    } else {
      for (int i = 3; i < n; i++)
        if (!onLine(p[0], p[1], p[i])) {
          swap(p[i], p[n - 1]);
          break;
        }
    }
  }
  sort(p, p + n - 1);
  for (int i = 0; i < n; i++)
    if (p[i].ind == k) {
      k = i;
      break;
    }
  cout << fixed << setprecision(12);
  if (k == n - 1) {
    cout << getdistsum(0, n - 2) << endl;
  } else {
    double ans = dist(p[k], p[n - 1]) + getdistsum(0, n - 2);
    for (int i = 0; i < n - 1; i++) {
      ans =
          min(ans, dist(p[k], p[0]) + dist(p[0], p[i]) + dist(p[i], p[n - 1]) +
                       getdistsum(max(i, k) + 1, n - 2));
    }
    for (int i = 0; i < n - 1; i++) {
      ans = min(ans, dist(p[k], p[n - 2]) + dist(p[n - 2], p[i]) +
                         dist(p[i], p[n - 1]) + getdistsum(0, min(i, k) - 1));
    }
    cout << ans << endl;
  }
  return 0;
}
