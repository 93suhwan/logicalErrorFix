#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
long long t;
long long mex(vector<long long> &v) {
  sort(v.begin(), v.end());
  long long ans = 0;
  for (long long x : v)
    if (x == ans) ans++;
  return ans;
}
long long main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    vector<long long> dp(n);
    function<long long(long long, long long)> get_mex = [&](long long i,
                                                            long long delta) {
      vector<long long> v;
      for (long long j = 0; j < delta; j++) {
        v.push_back(s1[i - j] - '0');
        v.push_back(s2[i - j] - '0');
      }
      return mex(v);
    };
    for (long long i = 0; i < n; i++) {
      for (long long prv = i - 1; prv >= i - 2; prv--) {
        long long delta = i - prv;
        if (prv == -1) {
          dp[i] = max(dp[i], get_mex(i, delta));
        } else if (prv < -1) {
          continue;
        } else {
          dp[i] = max(dp[i], dp[prv] + get_mex(i, delta));
        }
      }
    }
    cout << dp[n - 1] << "\n";
  }
}
