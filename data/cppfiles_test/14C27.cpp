#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, unsigned long long int y) {
  long long int res = 1;
  while (y > 0) {
    if (y & 1) {
      res = res * x;
    }
    y = y >> 1;
    x = x * x;
  }
  return res;
}
long long int powermod(long long int x, unsigned long long int y,
                       long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) {
      res = (res * x) % p;
    }
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int n, k, fans;
vector<long long int> v;
long long int dp[2001][2001];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int T;
  cin >> T;
  while (T--) {
    v.clear();
    cin >> n >> k;
    for (long long int i = (long long int)(0); i < (long long int)(n + 1); i++)
      for (long long int j = (long long int)(0); j < (long long int)(n + 1);
           j++)
        dp[i][j] = 0;
    v.push_back(0);
    for (long long int i = (long long int)(0); i < (long long int)(n); i++) {
      long long int t;
      cin >> t;
      v.push_back(t);
    }
    long long int ans = -1;
    for (long long int i = (long long int)(1); i < (long long int)(n + 1);
         i++) {
      for (long long int j = (long long int)(1); j < (long long int)(i + 1);
           j++) {
        long long int tans = max(
            {dp[i - 1][j], dp[i - 1][j - 1] + (v[i] == j), dp[i - 1][j - 1]});
        dp[i][j] = tans;
        if (tans >= k) ans = max(ans, j);
      }
    }
    if (ans == -1) ans = n + 1;
    cout << n - ans << "\n";
  }
  return 0;
}
