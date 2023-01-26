#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const long long N = 1e6 + 5;
long long a[N], b[N], m[N], p[N], c[N], d[N];
int main() {
  long long T;
  scanf("%lld", &T);
  while (T--) {
    long long n;
    scanf("%lld", &n);
    for (long long i = 1; i <= n; i++) {
      scanf("%lld%lld%lld", &a[i], &b[i], &m[i]);
      c[i] = a[i] >= m[i] ? a[i] - m[i] : 0ll;
      d[i] = b[i] >= m[i] ? a[i] : a[i] - (m[i] - b[i]);
      p[i] = i;
    }
    sort(p + 1, p + 1 + n, [](long long idx1, long long idx2) {
      if (a[idx1] + b[idx1] - m[idx1] != a[idx2] + b[idx2] - m[idx2])
        return a[idx1] + b[idx1] - m[idx1] < a[idx2] + b[idx2] - m[idx2];
      return d[idx1] < d[idx2];
    });
    long long ans = 0;
    for (long long i = 1, j; i <= n; i = j) {
      ++ans;
      long long u = p[i];
      for (j = i + 1; j <= n; j++) {
        long long v = p[j];
        if (a[u] + b[u] - m[u] != a[v] + b[v] - m[v]) break;
      }
      a[u] -= d[u];
      b[u] = m[u] - a[u];
      long long pa = d[u];
      for (long long k = i + 1; k <= j - 1; k++) {
        long long x = p[k];
        if (c[x] > pa) {
          ++ans;
          a[x] -= d[x];
          b[x] = m[x] - a[x];
          pa = d[x];
        } else {
          a[x] -= pa;
          b[x] = m[x] - a[x];
        }
      }
    }
    printf("%lld\n", ans);
    for (long long i = 1; i <= n; i++) printf("%lld %lld\n", a[i], b[i]);
  }
  return 0;
}
