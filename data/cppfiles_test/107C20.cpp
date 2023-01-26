#include <bits/stdc++.h>
using namespace std;
int dp[205][205];
long long rest[205][205];
int n, x[205], y[205], m;
long long area(int x1, int y1, int x2, int y2, int x3, int y3) {
  long long a = x2 - x1, b = y2 - y1, c = x3 - x1, d = y3 - y1;
  return abs(a * d - b * c);
}
bool chk(long long X) {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) dp[i][j] = -1e9;
  for (int i = 1; i < n; i++) dp[i][i + 1] = 0, rest[i][i + 1] = 0;
  for (int le = 3; le <= n; le++)
    for (int l = 1, r = le; r <= n; l++, r++) {
      for (int k = l + 1; k < r; k++) {
        int cnt = dp[l][k] + dp[k][r];
        long long S =
            area(x[l], y[l], x[r], y[r], x[k], y[k]) + rest[l][k] + rest[k][r];
        if (S >= X) S = 0, cnt++;
        if (cnt > dp[l][r])
          dp[l][r] = cnt, rest[l][r] = S;
        else if (cnt == dp[l][r])
          rest[l][r] = max(rest[l][r], S);
      }
    }
  return dp[1][n] >= m;
}
int main() {
  scanf("%d%d", &n, &m);
  m++;
  for (int i = 1; i <= n; i++) scanf("%d%d", x + i, y + i);
  long long l = 0, r = 8e16, ans = 0;
  while (l <= r) {
    long long mid = l + r >> 1;
    if (chk(mid))
      ans = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  printf("%lld\n", ans);
}
