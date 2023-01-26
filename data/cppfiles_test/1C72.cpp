#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 8;
const double eps = 1e-6;
inline int read() {
  int s = 1, a = 0;
  char c = getchar();
  while (!isdigit(c)) s = (c == '-') ? (-s) : s, c = getchar();
  while (isdigit(c)) a = (a << 3) + (a << 1) + c - '0', c = getchar();
  return s * a;
}
struct vec {
  double angle;
  int opt;
  bool operator<(const vec &fff) const { return angle < fff.angle; }
};
struct node {
  double x, y;
} nd[N];
vector<vec> G;
int n, k;
double mx;
bool check(double mid) {
  double r = mid;
  G.clear();
  for (int i = 1; i <= n; i++) {
    double d = sqrt(nd[i].x * nd[i].x + nd[i].y * nd[i].y);
    if (d - 2 * r >= eps) continue;
    double alpha = atan2(nd[i].y, nd[i].x), beta = acos(d / (2 * r));
    if (alpha > beta && alpha > 0) {
      G.push_back((vec){alpha - beta, 1});
      G.push_back((vec){alpha + beta, -1});
    } else if (alpha > 0 && alpha < beta) {
      G.push_back((vec){0, 1});
      G.push_back((vec){alpha + beta, -1});
      G.push_back((vec){alpha - beta + 2 * acos(-1), 1});
      G.push_back((vec){2 * acos(-1), -1});
    } else if (-alpha > beta) {
      alpha += 2 * acos(-1);
      G.push_back((vec){alpha - beta, 1});
      G.push_back((vec){alpha + beta, -1});
    } else {
      G.push_back((vec){0, 1});
      G.push_back((vec){beta + alpha, -1});
      G.push_back((vec){2 * acos(-1) - (beta - alpha), 1});
      G.push_back((vec){2 * acos(-1), -1});
    }
  }
  int cnt = 0;
  sort(G.begin(), G.end());
  for (auto v : G) {
    cnt += v.opt;
    if (cnt >= k) return 1;
  }
  return 0;
}
int main() {
  n = read(), k = read();
  for (int i = 1; i <= n; i++) {
    int x = read(), y = read();
    nd[i].x = x * 1.0, nd[i].y = y * 1.0;
    mx = max(sqrt(nd[i].x * nd[i].x + nd[i].y * nd[i].y), mx);
  }
  double l = 0.0000, r = 2e5 + 8, ans = 0.0;
  while (r - l > eps) {
    double mid = (l + r) / 2.0;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%.5f", r);
  return 0;
}
