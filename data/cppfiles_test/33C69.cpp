#include <bits/stdc++.h>
using namespace std;
const int M = 100005;
const int inf = 0x3f3f3f3f;
int read() {
  int x = 0, f = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9') {
    if (c == '-') f = -1;
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
int n, m, k, a[M], dp[M];
signed main() {
  n = read();
  m = 512;
  dp[0] = -1;
  for (int i = 1; i <= m; i++) dp[i] = inf;
  for (int i = 1; i <= n; i++) {
    int x = read();
    for (int j = 0; j < m; j++) {
      if (dp[j] < x) dp[j ^ x] = min(dp[j ^ x], x);
    }
  }
  for (int i = 0; i < m; i++)
    if (dp[i] < inf) a[++k] = i;
  printf("%d\n", k);
  for (int i = 1; i <= k; i++) printf("%d ", a[i]);
  puts("");
}
