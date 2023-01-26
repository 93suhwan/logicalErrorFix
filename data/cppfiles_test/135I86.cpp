#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const long long int INF = 1e18;
const int N = 2e5 + 5;
int v[N], dp[105][105][55];
int solve(int l, int r, int k) {
  if (l == r) return v[l];
  if (l > r) return 0;
  if (dp[l][r][k] != -1) return dp[l][r][k];
  int ans = min(solve(l + 1, r, k) + v[l], solve(l, r - 1, k) + v[r]);
  if (k) {
    ans = min({ans, solve(l, r - 2, k - 1) + (v[r] == v[r - 1]),
               solve(l + 1, r - 1, k - 1) + (v[l] == v[r])});
  }
  return dp[l][r][k] = ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tt;
  cin >> tt;
  while (tt--) {
    memset(dp, -1, sizeof(dp));
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    sort(v, v + n);
    cout << solve(0, n - 1, k) << "\n";
  }
  return 0;
}
