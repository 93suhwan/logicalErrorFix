#include <bits/stdc++.h>
using namespace std;
const unsigned int M = 1000000007;
const unsigned int mod = 998244353;
const int MAXN = 1e5 + 55;
const long long int MAXD = 1e14;
const long long int INF = 1e18;
const long long int NINF = INF * (-1);
const int INTINF = 1e8;
const int INTNINF = INTINF * (-1);
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a);
    a = (a * a);
    b >>= 1;
  }
  return res;
}
set<int> s;
void subsetSums(int arr[], int l, int r, int sum = 0) {
  if (l > r) {
    s.insert(sum);
    return;
  }
  subsetSums(arr, l + 1, r, sum + arr[l]);
  subsetSums(arr, l + 1, r, sum);
}
void testmetal() {
  long long int n;
  cin >> n;
  ;
  long long int k;
  cin >> k;
  ;
  long long int a[n + 1];
  for (long long int i = 1; i < n + 1; i++) {
    cin >> a[i];
  }
  long long int dp[n + 1][n + 1];
  memset(dp, 0, sizeof(dp));
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 1; j <= i; j++) {
      dp[i][j] = max(dp[i][j], dp[i - 1][j]);
      if (a[i] == j) {
        dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j]);
      } else {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
      }
    }
  }
  long long int ans = -1;
  for (long long int i = n; i >= 1; i--) {
    if (dp[n][i] >= k) {
      ans = n - i;
      break;
    }
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    testmetal();
  }
  return 0;
}
