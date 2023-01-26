#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2001;
const int UNSET = -1;
int a[MAXN], dp[MAXN];
int tc, n, m;
void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fast_io();
  cin >> tc;
  while (tc--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    memset(dp, UNSET, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = i; j >= 1; j--) dp[j] = max(dp[j], dp[j - 1] + (a[i] == j));
    }
    int ans = UNSET;
    for (int i = n; i >= 0; i--) {
      if (dp[i] >= m) {
        ans = (n - i);
        break;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
