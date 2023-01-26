#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int T, n;
int a[10010];
int dp[2][2010];
bool check(int len) {
  for (int i = 0; i <= len; ++i) dp[0][i] = dp[1][i] = -1;
  for (int i = 0; i <= len; ++i) {
    dp[0][i] = 1;
  }
  int now = 1, per = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= len; ++j) {
      dp[now][j] = 0;
    }
    for (int j = 0; j <= len; ++j) {
      if (dp[per][j]) {
        if (j + a[i] <= len) {
          dp[now][j + a[i]] = 1;
        }
        if (j - a[i] >= 0) {
          dp[now][j - a[i]] = 1;
        }
      }
    }
    now++;
    per++;
    now %= 2;
    per %= 2;
  }
  for (int i = 0; i <= len; ++i) {
    if (dp[per][i]) return true;
  }
  return false;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    int l = 1, r = 2010;
    int ans;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (check(mid)) {
        ans = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }
    printf("%d\n", ans);
  }
  return 0;
}
