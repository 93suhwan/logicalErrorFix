#include <bits/stdc++.h>
using namespace std;
template <typename T>
void chkmax(T &first, T second) {
  first < second ? first = second : T();
}
template <typename T>
void chkmin(T &first, T second) {
  second < first ? first = second : T();
}
template <typename T>
void readint(T &first) {
  first = 0;
  int f = 1;
  char c;
  for (c = getchar(); !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) first = first * 10 + (c - '0');
  first *= f;
}
const int n = 100000, m = 18;
long long dp[m + 3][n + 3];
int dv[n * 105], ed[n + 3], st[n + 3];
long long now[n + 3], f[n + 3];
int main() {
  for (int i = 1; i <= n; ++i)
    for (int j = i; j <= n; j += i) ++ed[j];
  for (int i = 1; i <= n; ++i) ed[i] += ed[i - 1], st[i] = ed[i];
  for (int i = n; i; --i)
    for (int j = i; j <= n; j += i) dv[st[j]--] = i;
  for (int i = 1; i <= n; ++i) dp[1][i] = 1ll * i * (i + 1) / 2;
  for (int k = 2; k <= m; ++k) {
    memset(now, 0, sizeof(now));
    long long sum = 0;
    for (int r = 1, l = 1; r <= n; ++r) {
      for (int i = ed[r]; i > st[r] && dv[i] >= l; --i) {
        int d = dv[i];
        f[d] = r / d;
        for (int j = ed[r / d]; j > st[r / d] + 1; --j) f[d] -= f[d * dv[j]];
        now[d] += f[d];
        sum += f[d];
      }
      for (; l < r && dp[k - 1][l - 1] >= dp[k - 1][l] - now[l]; ++l)
        sum -= now[l];
      dp[k][r] = dp[k - 1][l - 1] + sum;
    }
  }
  int T;
  readint(T);
  while (T--) {
    int u, k;
    readint(u), readint(k);
    if (k > m)
      printf("%d\n", u);
    else
      printf("%lld\n", dp[k][u]);
  }
  return 0;
}
