#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-8;
const long long INF = 1e9;
const long long N = 2e3 + 5;
const long long mod = 1e9 + 7;
int n, k;
int arr[N];
int dp[N][N];
int solve(int idx, int shift, int& mid) {
  if (idx == n + 1) return 0;
  if (dp[idx][shift] != -1) return dp[idx][shift];
  int ans = 0;
  if (arr[idx] == idx - shift) ans = solve(idx + 1, shift, mid) + 1;
  if (shift + 1 <= mid) ans = max(ans, solve(idx + 1, shift + 1, mid));
  ans = max(ans, solve(idx + 1, shift, mid));
  return dp[idx][shift] = ans;
}
void testCase() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  int s = 0, e = n, mid, res = INF;
  while (s <= e) {
    mid = (s + e) >> 1;
    memset(dp, -1, sizeof dp);
    int mx = solve(1, 0, mid);
    if (mx >= k)
      e = mid - 1, res = min(res, mid);
    else
      s = mid + 1;
  }
  cout << (res == INF ? -1 : res) << '\n';
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int tests = 1;
  cin >> tests;
  while (tests--) testCase();
}
