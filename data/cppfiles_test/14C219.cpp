#include <bits/stdc++.h>
using namespace std;
int denom = 31607;
int powmod(int a, int b) {
  int res = 1;
  a %= denom;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % denom;
    a = a * a % denom;
  }
  return res;
}
int n;
int solve(int idx, int k, vector<int>& a, vector<vector<int>>& dp) {
  if (k == 0) return 0;
  if (idx >= n) return n + 1;
  if (dp[idx][k] != -1) return dp[idx][k];
  int result = n + 1;
  for (int j = (idx + 1); j < (n); j++) {
    if (a[j] <= a[idx]) continue;
    int dIdx = j - idx;
    int dVal = a[j] - a[idx];
    if (dVal > dIdx) continue;
    result = min(result, dIdx - dVal + solve(j, k - 1, a, dp));
    if (dIdx == dVal) break;
  }
  dp[idx][k] = result;
  return result;
}
int main(int argc, const char* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t-- > 0) {
    int k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = (0); i < (n); i++) {
      cin >> a[i];
      a[i]--;
    }
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    int res = INT_MAX;
    for (int i = (0); i < (n); i++) {
      if (a[i] > i) continue;
      res = min(res, i - a[i] + solve(i, k - 1, a, dp));
    }
    cout << (res > n ? -1 : res) << endl;
  }
  return 0;
}
