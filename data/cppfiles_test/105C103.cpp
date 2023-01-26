#include <bits/stdc++.h>
using namespace std;
const int maxn = 3003, maxc = 20, maxv = 100, mod = 1e9 + 7, maxa = 1005,
          maxs = 820, maxb = 10, base = 737, base2 = 3079, mod3 = 998244353,
          delt = 10513;
const long long inf = 2e16;
const int infint = 1e9 + 11;
long long max(long long x, long long y) { return (x > y ? x : y); }
long long min(long long x, long long y) { return (x < y ? x : y); }
int dp[maxn][maxn];
vector<int> v[maxn];
int a[maxn];
int solve(int l, int r) {
  if (r - l == 0) {
    dp[l][r] = 0;
    return 0;
  }
  if (a[l] == a[r]) {
    dp[l][r] = solve(l, r - 1);
    return dp[l][r];
  }
  if (dp[l][r] >= 0) {
    return dp[l][r];
  }
  dp[l][r] = infint;
  int col = a[l];
  for (int i = 0; i < v[col].size(); i++) {
    int j = v[col][i];
    if (j > r) {
      break;
    }
    if (j < l) {
      continue;
    }
    dp[l][r] = min(solve(l, j) + solve(j + 1, r) + 1, dp[l][r]);
  }
  return dp[l][r];
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      v[a[i]].push_back(i);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dp[i][j] = -1;
      }
    }
    cout << solve(0, n - 1) << endl;
    for (int i = 0; i < n; i++) {
      v[a[i]].clear();
    }
  }
  return 0;
}
