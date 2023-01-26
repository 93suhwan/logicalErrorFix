#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 3e5 + 10;
const int mod = 998244353;
int n, m, k;
int x[maxn], y[maxn];
struct node {
  int x, y;
} p[maxn];
multiset<int> sy[maxn], sx[maxn];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &x[i]);
      sx[i].clear();
    }
    x[n + 1] = y[m + 1] = 1e6;
    for (int i = 1; i <= m; ++i) {
      scanf("%d", &y[i]);
      sy[i].clear();
    }
    for (int i = 1; i <= k; ++i) {
      scanf("%d%d", &p[i].x, &p[i].y);
    }
    long long ans = 0;
    sort(p + 1, p + 1 + k, [](node p1, node p2) { return p1.y < p2.y; });
    for (int i = 1; i <= k; ++i) {
      int px = p[i].x, py = p[i].y;
      if (binary_search(y, y + 1 + m + 1, py) == 0) {
        int upb = upper_bound(y, y + 1 + m + 1, py) - y;
        ans += (int)sy[upb].size() - sy[upb].count(px);
        sy[upb].insert(px);
      }
    }
    sort(p + 1, p + 1 + k, [](node p1, node p2) { return p1.x < p2.x; });
    for (int i = 1; i <= k; ++i) {
      int px = p[i].x, py = p[i].y;
      if (binary_search(x, x + 1 + n + 1, px) == 0) {
        int upb = upper_bound(x, x + 1 + n + 1, px) - x;
        ans += (int)sx[upb].size() - sx[upb].count(py);
        sx[upb].insert(py);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
