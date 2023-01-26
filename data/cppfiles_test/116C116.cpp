#include <bits/stdc++.h>
using namespace std;
long long md = 998244353;
long long modRecursive(long long a, long long k, long long md) {
  if (k == 0) return 1;
  long long temp = modRecursive((a * a) % md, k / 2, md) % md;
  if (k % 2) temp = (temp * a % md) % md;
  return temp;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    map<long long, long long> mp;
    long long maxx = 0;
    for (auto &it : a) {
      cin >> it;
      maxx = max(maxx, it);
    }
    long long curr = 0, ans = 0;
    vector<long long> dp(maxx + 2), extra(maxx + 2);
    for (long long i = 0; i < n; i++) {
      if (a[i] == 0) {
        dp[a[i]] = dp[a[i]] * 2 + 1;
        extra[a[i] + 1] *= 2;
      } else if (a[i] == 1) {
        dp[a[i]] = dp[a[i]] * 2 + dp[a[i] - 1];
        extra[a[i] + 1] *= 2;
        extra[a[i] - 1] = extra[a[i] - 1] * 2 + 1;
        extra[a[i] - 1] %= md;
      } else {
        dp[a[i]] = dp[a[i]] * 2 + dp[a[i] - 1];
        extra[a[i] + 1] *= 2;
        extra[a[i] - 1] = extra[a[i] - 1] * 2 + dp[a[i] - 2];
        extra[a[i] - 1] %= md;
      }
      dp[a[i]] %= md;
      extra[a[i] + 1] %= md;
      extra[a[i]] %= md;
    }
    for (long long i = 0; i <= maxx; i++) {
      ans = (ans + dp[i] + extra[i]) % md;
    }
    cout << (ans + md) % md << endl;
  }
}
