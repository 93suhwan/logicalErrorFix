#include <bits/stdc++.h>
using namespace std;
int x[200010], y[200010];
pair<int, int> p[200010];
int a[200010];
long long det(int i, int j, int k) {
  return 1ll * (x[j] - x[i]) * (y[k] - y[i]) -
         1ll * (x[k] - x[i]) * (y[j] - y[i]);
}
double dist(int i, int j) {
  return sqrt(1ll * (x[i] - x[j]) * (x[i] - x[j]) +
              1ll * (y[i] - y[j]) * (y[i] - y[j]));
}
int mls(int i, int j) { return x[i] == x[j] ? y[i] < y[j] : x[i] < x[j]; }
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &x[i], &y[i]);
  }
  --k;
  if (n == 3) {
    double ans = 1e40;
    for (int i = 0; i < n; i++) {
      if (i == k) continue;
      int j = 3 - i - k;
      double t = dist(k, i) + dist(i, j);
      if (ans > t) ans = t;
    }
    printf("%.12f\n", ans);
    return 0;
  }
  int f;
  if (det(0, 1, 2) == 0 || det(0, 1, 3) == 0) {
    for (int i = 2; i < n; i++) {
      if (det(0, 1, i)) f = i;
    }
  } else if (det(0, 2, 1) == 0 || det(0, 2, 3) == 0) {
    for (int i = 1; i < n; i++) {
      if (i != 2 && det(0, 2, i)) f = i;
    }
  } else {
    for (int i = 0; i < n; i++) {
      if (i != 1 && i != 2 && det(1, 2, i)) f = i;
    }
  }
  for (int i = 0; i < n; i++) {
    a[i] = i;
  }
  swap(a[f], a[n - 1]);
  sort(a, a + n - 1, mls);
  double w = dist(a[0], a[n - 2]);
  if (f == k) {
    w += min(dist(a[0], f), dist(a[n - 2], f));
    printf("%.12f\n", w);
    return 0;
  }
  int j;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] == k) j = i;
  }
  double ans = dist(k, f) + min(dist(a[0], f), dist(a[n - 2], f)) + w;
  if (j < n - 2) {
    ans =
        min(ans, w - dist(a[j + 1], a[j]) + dist(a[0], f) + dist(a[n - 2], f));
    ans =
        min(ans, w - dist(a[j + 1], a[j]) + dist(a[0], f) + dist(a[j + 1], f));
  } else {
    ans = min(ans, w + dist(a[0], f));
  }
  if (j) {
    ans =
        min(ans, w - dist(a[j - 1], a[j]) + dist(a[0], f) + dist(a[n - 2], f));
    ans = min(ans,
              w - dist(a[j - 1], a[j]) + dist(a[n - 2], f) + dist(a[j - 1], f));
  } else {
    ans = min(ans, w + dist(a[n - 2], f));
  }
  for (int i = 1; i < n - 2; i++) {
    ans =
        min(ans, w - dist(a[i - 1], a[i]) + dist(f, a[i - 1]) + dist(f, a[i]) +
                     min(dist(a[j], a[0]), dist(a[j], a[n - 2])));
  }
  ans = min(ans, w + min(dist(a[0], f) + dist(a[n - 2], a[j]),
                         dist(a[n - 2], f) + dist(a[0], a[j])));
  printf("%.12f\n", ans);
  return 0;
}
