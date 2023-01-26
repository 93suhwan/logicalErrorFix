#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int maxn = 1e6 + 10;
inline int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
int b[maxn];
struct a_node {
  int x;
  int id;
} a[maxn];
bool cmp(a_node x, a_node y) { return abs(x.x) < abs(y.x); }
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i].x), b[i] = 0, a[i].id = i;
    sort(a + 1, a + n + 1, cmp);
    if (n % 2) {
      for (int i = 1; i < n - 2; i += 2) {
        int tmp = abs(gcd(a[i].x, a[i + 1].x));
        b[a[i].id] = a[i + 1].x / tmp;
        b[a[i + 1].id] = (-1) * a[i].x / tmp;
      }
      int x = a[n - 1].x + a[n].x, y = a[n - 2].x;
      int tmp = abs(gcd(x, y));
      b[a[n - 2].id] = (-1) * (x) / tmp;
      b[a[n].id] = y / tmp, b[a[n - 1].id] = y / tmp;
      tmp = abs(gcd(a[n - 2].x, a[n].x));
      while (b[a[n - 2].id] == 0) {
        b[a[n - 2].id] -= a[n].x / tmp;
        b[a[n].id] += a[n - 2].x / tmp;
      }
    } else {
      for (int i = 1; i <= n; i += 2) {
        int tmp = abs(gcd(a[i].x, a[i + 1].x));
        b[a[i].id] = a[i + 1].x / tmp;
        b[a[i + 1].id] = -1 * a[i].x / tmp;
      }
    }
    for (int i = 1; i <= n; ++i) {
      printf("%d ", b[i]);
    }
    printf("\n");
  }
  return 0;
}
