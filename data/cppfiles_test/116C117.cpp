#include <bits/stdc++.h>
using namespace std;
int a[500005];
long long dp[2][500005];
int n;
void solve() {
  scanf("%d", &n);
  for (int k = 0; k < 2; k++)
    for (int i = 0; i <= n + 3; i++) dp[k][i] = 0;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  long long countt = 0;
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    dp[0][a[i] + 1] = (dp[0][a[i] + 1] * 2) % 998244353;
    dp[1][a[i] + 1] = (dp[1][a[i] + 1] * 2) % 998244353;
    if (a[i] >= 1) dp[1][a[i] - 1] = (dp[1][a[i] - 1] * 2) % 998244353;
    dp[0][a[i] + 1] = (dp[0][a[i] + 1] + dp[0][a[i]]) % 998244353;
    if (a[i] >= 1)
      dp[1][a[i] - 1] = (dp[1][a[i] - 1] + dp[0][a[i] - 1]) % 998244353;
  }
  for (int i = 0; i <= n; i++)
    for (int k = 0; k < 2; k++) countt = (countt + dp[k][i]) % 998244353;
  printf("%lld\n", (countt - dp[0][0] + 998244353) % 998244353);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
}
