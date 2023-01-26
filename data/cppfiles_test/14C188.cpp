#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2050;
int n, k, a[MAXN], f[MAXN][MAXN], ans;
inline bool solve(int cs) {
  scanf("%d%d", &n, &k);
  for (long long i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    f[i][0] = f[i - 1][0] + (a[i] == i);
    for (long long j = 1; j <= i; j++) {
      f[i][j] = max(f[i - 1][j - 1], f[i - 1][j] + (a[i] == i - j));
    }
  }
  ans = -1;
  for (long long j = n; j >= 0; j--) {
    if (f[n][j] >= k) ans = j;
  }
  printf("%d\n", ans);
  return true;
}
int main() {
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    bool useless = solve(t);
  }
  return 0;
}
