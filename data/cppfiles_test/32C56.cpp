#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e18 + 5;
int const maxn = 1e5 + 5, maxk = 450;
int a[maxn], dp[maxn][maxk];
int inf = 1e9 + 7;
long long pref[maxn];
int t, n;
void Enter() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    pref[i] = pref[i - 1] + 1ll * a[i];
  }
}
void Process() {
  int k = 0;
  while (k * (k + 1) / 2 <= n) k++;
  for (int j = 0; j < k; ++j) {
    dp[n + 1][j] = -inf;
  }
  dp[n + 1][0] = inf;
  for (int i = n; i >= 1; --i) {
    for (int j = 0; j < k; ++j) {
      dp[i][j] = dp[i + 1][j];
      if (j && i + j - 1 <= n &&
          pref[i + j - 1] - pref[i - 1] < dp[i + j][j - 1]) {
        dp[i][j] = max(dp[i][j], (int)(pref[i + j - 1] - pref[i - 1]));
      }
    }
  }
  int ans = 0;
  for (int j = 0; j < k; ++j) {
    if (dp[1][j] > 0) ans = j;
  }
  cout << ans << '\n';
}
int main() {
  scanf("%d", &t);
  while (t--) {
    Enter();
    Process();
  }
  return 0;
}
