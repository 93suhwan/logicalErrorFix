#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
int a[maxn];
int dp[1512];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, i, j;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  memset(dp, inf, sizeof(dp));
  dp[0] = 0;
  for (i = 1; i <= n; i++) {
    for (j = 0; j <= 512; j++)
      if (dp[j ^ a[i]] < a[i]) dp[j] = min(dp[j], a[i]);
  }
  for (i = 0; i <= 512; i++)
    if (dp[i] != inf) cout << i << ' ';
  return 0;
}
