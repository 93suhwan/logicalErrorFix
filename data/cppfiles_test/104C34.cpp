#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct dish {
  long long a;
  long long b;
};
struct dish a[N];
long long b[N], c[N];
bool cmp1(struct dish a, struct dish b) { return a.a < b.a; }
void solve() {
  long long flag = 0, need;
  long long n, m, sum1 = 0, sum2 = 0, i;
  scanf("%lld%lld", &n, &m);
  for (i = 1; i <= n; ++i) {
    scanf("%lld%lld", &a[i].a, &a[i].b);
    sum1 += a[i].a;
    sum2 += a[i].b;
    b[i] = c[i] = 0;
  }
  if (sum1 < sum2) {
    swap(sum1, sum2);
    for (i = 1; i <= n; ++i) swap(a[i].a, a[i].b);
    flag = 1;
  }
  need = sum1 - sum2;
  for (i = 1; i <= n; ++i) {
    if (a[i].a >= m) {
      a[i].a -= m;
      b[i] = m;
      c[i] = 0;
      need = need - m;
    } else {
      b[i] = a[i].a;
      c[i] = m - a[i].a;
      a[i].a = 0;
      a[i].b = a[i].b - c[i];
      need = need - b[i] + c[i];
    }
  }
  if (need < -1) {
    long long g = (0 - need) / 2;
    for (i = 1; i <= n; ++i) {
      if (a[i].b) {
        int can = min(min(b[i], a[i].b), g);
        b[i] = b[i] - can;
        a[i].b = a[i].b - can;
        c[i] = c[i] + can;
        g = g - can;
        need = need + 2 * can;
      }
      if (g == 0) break;
    }
  }
  if (need < 0)
    printf("%lld\n", -1 * need);
  else
    printf("%lld\n", need);
  for (i = 1; i <= n; ++i) {
    if (flag == 0)
      printf("%lld %lld\n", b[i], c[i]);
    else
      printf("%lld %lld\n", c[i], b[i]);
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
}
