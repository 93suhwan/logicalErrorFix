#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int N = 2e5 + 5, mod = 1e9 + 7;
int n, a[N], dp[N][2];
int dfs(int l, int r, int last) {
  if (l == r) return a[l] > last;
  if (a[l] > a[r]) {
    if (last < a[r]) {
      int ans1 = dp[l][1] & 1, ans2 = !dfs(l, r - 1, a[r]);
      return ans1 | ans2;
    } else if (last < a[l]) {
      return dp[l][1] & 1;
    } else
      return 0;
  } else if (a[l] < a[r]) {
    if (last < a[l]) {
      int ans1 = dp[r][0] & 1, ans2 = !dfs(l + 1, r, a[l]);
      return ans1 | ans2;
    } else if (last < a[r]) {
      return dp[r][0] & 1;
    } else
      return 0;
  } else {
    if (last < a[l]) {
      int ans1 = dp[l][1] & 1, ans2 = dp[r][0] & 1;
      return ans1 | ans2;
    } else
      return 0;
  }
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  memset(a, -1, sizeof a);
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    if (a[i] < a[i - 1])
      dp[i][0] = dp[i - 1][0] + 1;
    else
      dp[i][0] = 1;
  }
  for (int i = n; i; i--) {
    if (a[i] < a[i + 1])
      dp[i][1] = dp[i + 1][1] + 1;
    else
      dp[i][1] = 1;
  }
  if (dfs(1, n, 0))
    cout << "Alice";
  else
    cout << "Bob";
  return 0;
}
