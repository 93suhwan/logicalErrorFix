#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1, ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writeln(int x) {
  write(x);
  puts("");
}
const int N = 1e5 + 5;
const double eps = 1e-5, pi = acos(-1);
int n, k;
double x[N], y[N];
inline void init() {
  n = read();
  k = read();
  for (int i = 1; i <= n; i++) {
    x[i] = read();
    y[i] = read();
  }
}
vector<pair<double, int> > vec;
inline bool judge(double r) {
  vec.clear();
  for (int i = 1; i <= n; i++) {
    double d = sqrt(1.0 * x[i] * x[i] + 1.0 * y[i] * y[i]);
    if (d - 2 * r >= eps) continue;
    double p = atan2(y[i], x[i]), q = acos(1.0 * d / (2 * r));
    if (p > q && q > 0) {
      vec.push_back(pair<double, int>(p - q, 1));
      vec.push_back(pair<double, int>(p + q, -1));
    } else {
      if (p < q && p > 0) {
        vec.push_back(pair<double, int>(0, 1));
        vec.push_back(pair<double, int>(p + q, -1));
        vec.push_back(pair<double, int>(p - q + 2 * pi, 1));
        vec.push_back(pair<double, int>(2 * pi, -1));
      } else {
        if (-p > q) {
          p += 2 * pi;
          vec.push_back(pair<double, int>(p - q, 1));
          vec.push_back(pair<double, int>(p + q, -1));
        } else {
          vec.push_back(pair<double, int>(0, 1));
          vec.push_back(pair<double, int>(p + q, -1));
          vec.push_back(pair<double, int>(2 * pi - (q - p), 1));
          vec.push_back(pair<double, int>(2 * pi, -1));
        }
      }
    }
  }
  sort(vec.begin(), vec.end());
  int cnt = 0;
  for (int i = 0; i < vec.size(); i++) {
    int w = vec[i].second;
    cnt += w;
    if (cnt >= k) return 1;
  }
  return 0;
}
inline void solve() {
  double l = 0, r = 2e5;
  while (l + eps < r) {
    double mid = (l + r) / 2;
    if (judge(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%.4lf\n", l);
}
int main() {
  init();
  solve();
  return 0;
}
