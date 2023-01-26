#include <bits/stdc++.h>
using namespace std;
void init() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  cout.tie(0);
  cout.sync_with_stdio(0);
}
long long en;
long long n, arr[10001], ix = 0;
long long solve(long long i, long long x, long long mn, long long mx,
                vector<vector<long long>>& dp) {
  if (i == n) return 0;
  if (x >= 2 * en + 1) return 1e18;
  if (dp[i][x] != -1) return dp[i][x];
  long long ans = LONG_LONG_MAX;
  long long a = 0, b = 0;
  if (x - arr[i] >= mn && x - arr[i] <= mx)
    a = 0;
  else if (x - arr[i] > mx)
    a = abs(x - arr[i] - mx);
  else if (x - arr[i] < mn)
    a = abs(x - arr[i] - mn);
  if (x + arr[i] >= mn && x + arr[i] <= mx)
    b = 0;
  else if (x + arr[i] > mx)
    b = abs(x + arr[i] - mx);
  else if (x + arr[i] < mn)
    b = abs(x + arr[i] - mn);
  ans = min(ans, solve(i + 1, x - arr[i], min(mn, x - arr[i]),
                       max(mx, x - arr[i]), dp) +
                     a);
  ans = min(ans, solve(i + 1, x + arr[i], min(x + arr[i], mn),
                       max(mx, x + arr[i]), dp) +
                     b);
  return dp[i][x] = ans;
}
int main() {
  init();
  long long t;
  cin >> t;
  while (t--) {
    cin >> n;
    ix++;
    en = 0;
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
      arr[i] += 2000;
      en = max(arr[i], en);
    }
    vector<vector<long long>> dp(n + 1, vector<long long>(en * 2 + 5, -1));
    cout << solve(0, 0, 0, 0, dp) - 2000 << "\n";
  }
}
