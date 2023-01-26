#include <bits/stdc++.h>
using namespace std;
const long long N = 15, M = 1e4 + 1e2 + 7;
long long T;
long long n, m, x[N];
char s[N][M];
long long val[M], r[M], p[M], ap[M];
bool cmp(long long a, long long b) { return val[a] < val[b]; }
signed main() {
  scanf("%lld", &T);
  while (T--) {
    long long ans = -1;
    scanf("%lld%lld", &n, &m);
    for (long long i = 1; i <= n; i++) scanf("%lld", &x[i]);
    for (long long i = 1; i <= n; i++) scanf("%s", s[i] + 1);
    for (long long S = 0; S < (1 << n); S++) {
      for (long long i = 1; i <= m; i++) val[i] = 0, r[i] = i;
      for (long long i = 1; i <= n; i++) {
        long long v = (S & (1 << i - 1)) ? 1 : -1;
        for (long long j = 1; j <= m; j++)
          if (s[i][j] == '1') val[j] += v;
      }
      sort(r + 1, r + m + 1, cmp);
      for (long long i = 1; i <= m; i++) p[r[i]] = i;
      long long tot = 0;
      for (long long i = 1; i <= n; i++) {
        long long sv = 0;
        for (long long j = 1; j <= m; j++)
          if (s[i][j] == '1') sv += p[j];
        tot += abs(sv - x[i]);
      }
      if (tot > ans) {
        ans = tot;
        for (long long j = 1; j <= m; j++) ap[j] = p[j];
      }
    }
    for (long long i = 1; i <= m; i++) printf("%lld%c", ap[i], " \n"[i == m]);
  }
}
