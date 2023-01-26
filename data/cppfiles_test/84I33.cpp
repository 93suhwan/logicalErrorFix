#include <bits/stdc++.h>
const int N = 100001;
int t, n, k, p[N], pr[N], cp;
long long dp[18][N], P[N];
bool v[N];
long long c(int l, int r) {
  long long s = 0;
  int k;
  for (int i = l, j = r / i; i <= r; i = k + 1, j = r / i) {
    k = r / j, s += P[j] * (k - i + 1);
  }
  return s;
}
void solve(int l, int r, int dl, int dr, int k) {
  if (l > r) return;
  int m = (l + r) >> 1, dm = -1;
  long long dmin = -1;
  for (int i = dl; i <= std::min(dr, m - 1); ++i) {
    long long dtmp = dp[k - 1][i] + c(i + 1, m);
    if (dmin == -1 || dtmp < dmin) {
      dmin = dtmp;
      dm = i;
    }
  }
  dp[k][m] = dmin;
  solve(l, m - 1, dl, dm, k), solve(m + 1, r, dm, dr, k);
}
int main() {
  scanf("%d", &t);
  p[1] = P[1] = 1;
  for (int i = 2; i <= 10000; ++i) {
    if (!v[i]) pr[++cp] = i, p[i] = i - 1;
    for (int j = 1; j <= cp && i * pr[j] <= 10000; ++j) {
      v[i * p[j]] = 1, p[i * pr[j]] = p[i] * (pr[j] - 1);
      if (i % pr[j] == 0) {
        p[i * pr[j]] += p[i];
        break;
      }
    }
    P[i] = P[i - 1] + p[i];
  }
  for (int i = 1; i <= 10000; ++i) dp[1][i] = c(1, i);
  for (int k = 2; k <= 17; ++k) solve(1, 10000, 0, 10000, k);
  while (t--) {
    scanf("%d%d", &n, &k);
    if (k > log(n) / log(2))
      printf("%d\n", k);
    else
      printf("%lld\n", dp[k][n]);
  }
  return 0;
}
