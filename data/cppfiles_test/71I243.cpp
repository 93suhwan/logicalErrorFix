#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f, mod = 1000000007;
const double pi = 3.1415926535897932, eps = 1e-6;
void chmax(int &x, int y) {
  if (x < y) x = y;
}
void chmin(int &x, int y) {
  if (x > y) x = y;
}
int qpow(int x, int y) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = (long long)ret * x % mod;
    x = (long long)x * x % mod;
    y >>= 1;
  }
  return ret;
}
int n, s;
int x[200005], y[200005];
int gcd(int x, int y) {
  if (!y) return x;
  return gcd(y, x % y);
}
double dist(int a, int b) {
  return sqrt((double)(x[a] - x[b]) * (x[a] - x[b]) +
              (double)(y[a] - y[b]) * (y[a] - y[b]));
}
vector<pair<int, int> > p;
pair<int, int> u[5];
int main() {
  scanf("%d%d", &n, &s);
  for (int(i) = (1); (i) <= (n); (i)++) scanf("%d%d", x + i, y + i);
  pair<int, int> k = make_pair(0, 0);
  int id = -1;
  for (int(i) = (2); (i) <= (4); (i)++) {
    int dx = x[1] - x[i], dy = y[1] - y[i];
    int g = gcd(abs(dx), abs(dy));
    dx /= g;
    dy /= g;
    if (dx < 0) dx = -dx, dy = -dy;
    u[i] = make_pair(dx, dy);
  }
  if (u[2] == u[3] && u[3] == u[4]) {
    for (int(i) = (5); (i) <= (n); (i)++) {
      int dx = x[1] - x[i], dy = y[1] - y[i];
      int g = gcd(abs(dx), abs(dy));
      dx /= g;
      dy /= g;
      if (dx < 0) dx = -dx, dy = -dy;
      if (u[2] != make_pair(dx, dy)) {
        id = i;
        break;
      }
    }
  } else if (u[2] != u[3] && u[3] != u[4] && u[4] != u[2]) {
    id = 1;
  } else {
    if (u[2] == u[3]) id = 4;
    if (u[2] == u[4]) id = 3;
    if (u[3] == u[4]) id = 2;
  }
  for (int(i) = (1); (i) <= (n); (i)++)
    if (i != id) p.push_back(make_pair(x[i], y[i]));
  sort(p.begin(), p.end());
  if (s == id)
    s = n;
  else {
    for (int(i) = (0); (i) < (p.size()); (i)++)
      if (p[i] == make_pair(x[s], y[s])) {
        s = i + 1;
        break;
      }
  }
  x[n] = x[id];
  y[n] = y[id];
  id = n;
  for (int(i) = (0); (i) < (p.size()); (i)++)
    x[i + 1] = p[i].first, y[i + 1] = p[i].second;
  if (s == id) {
    printf("%.12lf\n",
           min(dist(s, 1) + dist(1, n - 1), dist(s, n - 1) + dist(1, n - 1)));
    return 0;
  }
  double ans = 1e18;
  ans = min(ans, dist(s, 1) + dist(1, n) +
                     (s == n - 1 ? 0 : dist(n, s + 1) + dist(s + 1, n - 1)));
  ans = min(ans, dist(s, 1) + dist(1, n) +
                     (s == n - 1 ? 0 : dist(n, s + 1) + dist(s + 1, n - 1)));
  ans = min(ans, dist(s, n - 1) + dist(n - 1, n) +
                     (s == 1 ? 0 : dist(n, 1) + dist(1, s - 1)));
  ans = min(ans, dist(s, n - 1) + dist(n - 1, n) +
                     (s == 1 ? 0 : dist(n, s - 1) + dist(s - 1, 1)));
  for (int(i) = (1); (i) <= (n - 1); (i)++) {
    ans = min(ans, dist(s, 1) + dist(1, i) + dist(i, n) +
                       (i < n - 1 ? dist(n, i + 1) + dist(i + 1, n - 1) : 0));
    ans = min(ans, dist(s, i) + dist(i, 1) + dist(1, n) +
                       (i < n - 1 ? dist(n, i + 1) + dist(i + 1, n - 1) : 0));
    ans = min(ans, dist(s, n - 1) + dist(n - 1, i) + dist(i, n) +
                       (i > 1 ? dist(n, i - 1) + dist(i - 1, 1) : 0));
    ans = min(ans, dist(s, i) + dist(i, n - 1) + dist(n - 1, n) +
                       (i > 1 ? dist(n, i - 1) + dist(i - 1, 1) : 0));
  }
  printf("%.12lf\n", ans);
  return 0;
}
