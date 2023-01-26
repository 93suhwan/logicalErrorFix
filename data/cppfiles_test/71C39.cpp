#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool chkmin(T &x, T y) {
  return x > y ? x = y, 1 : 0;
}
template <typename T>
bool chkmax(T &x, T y) {
  return x < y ? x = y, 1 : 0;
}
int readint() {
  int x = 0, f = 1;
  char ch = getchar();
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
int n, k, m;
int b[200005];
pair<int, int> a[200005];
long long sqr(long long x) { return x * x; }
double dist(pair<int, int> x, pair<int, int> y) {
  return sqrt(sqr(x.first - y.first) + sqr(x.second - y.second));
}
pair<int, int> operator-(const pair<int, int> x, const pair<int, int> y) {
  return make_pair(x.first - y.first, x.second - y.second);
}
long long operator*(const pair<int, int> x, const pair<int, int> y) {
  return 1ll * x.first * y.second - 1ll * x.second * y.first;
}
int main() {
  n = readint();
  k = readint();
  for (int i = 1; i <= n; i++) a[i].first = readint(), a[i].second = readint();
  if (n == 3) {
    double ans = 1e18;
    for (int i = 1; i <= n; i++)
      if (i != k) chkmin(ans, dist(a[i], a[k]) + dist(a[i], a[i ^ k]));
    printf("%.10lf\n", ans);
    return 0;
  }
  int t1 = -1, t2;
  for (int i = 1; i <= 4; i++)
    for (int j = i + 1; j <= 4; j++)
      for (int k = j + 1; k <= 4; k++)
        if ((a[j] - a[i]) * (a[k] - a[i]) == 0) t1 = i, t2 = j;
  assert(t1 >= 0);
  int tmp = 0;
  for (int i = 1; i <= n; i++) {
    if ((a[t2] - a[t1]) * (a[i] - a[t1]) == 0)
      b[++m] = i;
    else
      assert(!tmp), tmp = i;
  }
  sort(b + 1, b + m + 1, [&](int x, int y) { return a[x] < a[y]; });
  if (k == tmp) {
    printf("%.10lf\n", min(dist(a[tmp], a[b[1]]) + dist(a[b[1]], a[b[m]]),
                           dist(a[tmp], a[b[m]]) + dist(a[b[1]], a[b[m]])));
    return 0;
  }
  int pl;
  for (int i = 1; i <= m; i++)
    if (b[i] == k) pl = i;
  if (pl == m) reverse(b + 1, b + m + 1), pl = 1;
  if (pl == 1) {
    double ans = 1e18, now = dist(a[b[1]], a[b[m]]);
    chkmin(ans, now + dist(a[b[m]], a[tmp]));
    for (int i = 1; i < m; i++) {
      chkmin(ans, now - dist(a[b[i]], a[b[i + 1]]) + dist(a[b[i]], a[tmp]) +
                      dist(a[tmp], a[b[i + 1]]));
      chkmin(ans, now - dist(a[b[i]], a[b[i + 1]]) + dist(a[b[i]], a[tmp]) +
                      dist(a[tmp], a[b[m]]));
    }
    printf("%.10lf\n", ans);
    return 0;
  }
  double ans = 1e18;
  chkmin(ans, dist(a[b[pl]], a[tmp]) + dist(a[tmp], a[b[1]]) +
                  dist(a[b[1]], a[b[m]]));
  chkmin(ans, dist(a[b[pl]], a[tmp]) + dist(a[tmp], a[b[m]]) +
                  dist(a[b[1]], a[b[m]]));
  double now = dist(a[b[1]], a[b[pl]]);
  chkmin(ans, now + dist(a[b[1]], a[tmp]) + dist(a[tmp], a[b[pl + 1]]) +
                  dist(a[b[pl + 1]], a[b[m]]));
  now += dist(a[b[1]], a[b[m]]);
  chkmin(ans, now + dist(a[b[m]], a[tmp]));
  for (int i = pl + 1; i < m; i++) {
    chkmin(ans, now - dist(a[b[i]], a[b[i + 1]]) + dist(a[b[i]], a[tmp]) +
                    dist(a[tmp], a[b[i + 1]]));
    chkmin(ans, now - dist(a[b[i]], a[b[i + 1]]) + dist(a[b[i]], a[tmp]) +
                    dist(a[tmp], a[b[m]]));
  }
  reverse(b + 1, b + m + 1);
  pl = m - pl + 1;
  now = dist(a[b[1]], a[b[pl]]);
  chkmin(ans, now + dist(a[b[1]], a[tmp]) + dist(a[tmp], a[b[pl + 1]]) +
                  dist(a[b[pl + 1]], a[b[m]]));
  now += dist(a[b[1]], a[b[m]]);
  chkmin(ans, now + dist(a[b[m]], a[tmp]));
  for (int i = pl + 1; i < m; i++) {
    chkmin(ans, now - dist(a[b[i]], a[b[i + 1]]) + dist(a[b[i]], a[tmp]) +
                    dist(a[tmp], a[b[i + 1]]));
    chkmin(ans, now - dist(a[b[i]], a[b[i + 1]]) + dist(a[b[i]], a[tmp]) +
                    dist(a[tmp], a[b[m]]));
  }
  printf("%.10lf\n", ans);
  return 0;
}
