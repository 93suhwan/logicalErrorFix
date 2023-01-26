#include <bits/stdc++.h>
using namespace std;
long long dp[500005][2];
const long long p = 998244353;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n + 1);
  for (long long i = (1); i <= (n); i++) cin >> a[i];
  for (long long i = (0); i <= (n + 1); i++) dp[i][0] = dp[i][1] = 0;
  for (long long i = (1); i <= (n); i++) {
    (dp[a[i] + 1][0] = (dp[a[i] + 1][0] + dp[a[i] + 1][0]) % p),
        (dp[a[i] + 1][1] = (dp[a[i] + 1][1] + dp[a[i] + 1][1]) % p);
    (dp[a[i] + 1][0] = (dp[a[i] + 1][0] + dp[a[i]][0]) % p);
    if (a[i] > 0)
      (dp[a[i] - 1][1] =
           (dp[a[i] - 1][1] + dp[a[i] - 1][0] + dp[a[i] - 1][1]) % p);
    if (a[i] == 1)
      (dp[0][1] = (dp[0][1] + 1) % p);
    else if (a[i] == 0)
      (dp[1][0] = (dp[1][0] + 1) % p);
  }
  long long ans = 0;
  for (long long i = (0); i <= (n + 1); i++)
    ans = (ans + dp[i][0] + dp[i][1]) % p;
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
