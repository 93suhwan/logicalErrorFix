#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const double pi = acos(-1.0);
double l, r, mid;
int n, k, a[maxn], b[maxn];
struct node {
  double x;
  int val;
};
bool cmp(node u, node v) { return u.x < v.x; }
double f(double x) {
  while (x < 0) x += pi * 2;
  while (x > pi) x -= pi * 2;
  return x;
}
vector<node> event;
void ins(double L, double R) {
  event.push_back((node){L, 1});
  event.push_back((node){R, -1});
}
int solve(double R) {
  event.clear();
  for (int i = 1; i <= n; i++) {
    if (!a[i] && !b[i]) continue;
    double x = a[i], y = b[i];
    double d = sqrt(x * x + y * y);
    if (d / 2 >= R) continue;
    double p = atan2(x, y);
    double q = acos(d / 2 / R);
    double L = f(p - q), R = f(p + q);
    if (L < R)
      ins(L, R), ins(L + pi * 2, R + pi * 2);
    else
      ins(L, R + pi * 2);
  }
  sort(event.begin(), event.end(), cmp);
  int now = 0, ret = 0;
  for (auto x : event) {
    now += x.val;
    ret = max(ret, now);
  }
  return ret;
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    if (!a[i] && !b[i]) --k;
  }
  l = 0;
  r = 2e5;
  for (int i = 0; i < 40; i++) {
    mid = (l + r) * 0.5;
    if (solve(mid) >= k)
      r = mid;
    else
      l = mid;
  }
  printf("%.10f\n", l);
  return 0;
}
