#include <bits/stdc++.h>
using namespace std;
const double esp = 1e-10;
const int INF = 0x3f3f3f3f;
const int maxn = 2e3 + 50;
const double PI = acos(-1);
const int mod = 998244353;
int a[maxn], b[maxn];
int c[maxn], d[maxn];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d %d", &a[i], &b[i]);
      c[i] = max(m - b[i], 0);
      d[i] = min(m, b[i]);
      sum += a[i] - c[i] - b[i] + d[i];
    }
    for (int i = 1; i <= n; ++i) {
      if (sum <= 1)
        break;
      else {
        int x = a[i] - c[i];
        int limit = min(d[i], x);
        if (sum >= 2 * limit) {
          c[i] += limit;
          d[i] -= limit;
          sum -= limit * 2;
        } else {
          c[i] += sum / 2;
          d[i] -= sum / 2;
          sum %= 2;
        }
      }
    }
    printf("%lld\n", labs(sum));
    for (int i = 1; i <= n; ++i) printf("%d %d\n", c[i], d[i]);
  }
  return 0;
}
