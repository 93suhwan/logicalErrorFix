#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int t, n, m, k, x[N], y[N], l[N], h[N], a, b;
map<pair<int, int>, int> mp;
long long f(int x) { return (long long)x * (x - 1) / 2; }
int main() {
  scanf("%d", &t);
  while (t--) {
    mp.clear();
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= max(n, m); i++) l[i] = h[i] = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
    for (int i = 1; i <= m; i++) scanf("%d", &y[i]);
    long long res = 0;
    for (int i = 1; i <= k; i++) {
      scanf("%d%d", &a, &b);
      int p1 = lower_bound(x + 1, x + 1 + n, a) - x;
      int p2 = lower_bound(y + 1, y + 1 + m, b) - y;
      if (x[p1] != a) l[p1]++, res += f(mp[{p1, b}]) - f(++mp[{p1, b}]);
      if (y[p2] != b) h[p2]++, res += f(mp[{a, p2}]) - f(++mp[{a, p2}]);
    }
    for (int i = 1; i <= n; i++) res += f(l[i]);
    for (int i = 1; i <= m; i++) res += f(h[i]);
    printf("%lld\n", res);
  }
  return 0;
}
