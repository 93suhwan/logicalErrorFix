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
    vector<long long> dp(maxx + 1), cnt(maxx + 1);
    for (long long i = 0; i < n; i++) {
      mp[a[i]]++;
      if (a[i] == 0) {
        if (!dp[a[i]])
          dp[a[i]] = 1;
        else
          dp[a[i]] = (dp[a[i]] * 2) % md;
      } else {
        dp[a[i]] = max(1LL, dp[a[i]]) * dp[a[i] - 1];
      }
      if (a[i] == 1) {
        cnt[a[i]] = max(1LL, cnt[a[i]] * 2);
      } else if (a[i] > 1) {
        cnt[a[i]] = max(0LL, max(1LL, cnt[a[i]]) * dp[a[i] - 2]);
      }
      cnt[a[i]] %= md;
      dp[a[i]] %= md;
      ans = (ans + dp[a[i]] + cnt[a[i]]) % md;
    }
    cout << (ans + md) % md << endl;
  }
}
