#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1.01e9;
const long long infll = (long long)1.01e18;
const long double eps = 1e-9;
const long double pi = acos((long double)-1);
mt19937 mrand(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x) { return mrand() % x; }
void precalc() {}
const int maxn = 6005;
int n;
int xs[maxn], ys[maxn];
bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &xs[i], &ys[i]);
    xs[i] /= 2;
    ys[i] /= 2;
  }
  return true;
}
void solve() {
  long long x = 0, y = 0;
  for (int i = 0; i < n; ++i) {
    int cnt[2] = {0, 0};
    for (int j = 0; j < n; ++j) {
      if (j == i) {
        continue;
      }
      int dx = xs[j] - xs[i], dy = ys[j] - ys[i];
      if ((dx & 1) || (dy & 1)) {
        ++cnt[1];
      } else {
        ++cnt[0];
      }
    }
    x += cnt[0] * (cnt[0] - 1) / 2;
    y += cnt[0] * cnt[1];
  }
  x /= 3;
  y /= 2;
  printf("%lld\n", x + y);
}
int main() {
  precalc();
  while (read()) {
    solve();
  }
  return 0;
}
