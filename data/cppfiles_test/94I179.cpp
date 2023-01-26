#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long a[15];
long long dp[15];
long long ans[15];
string an;
signed main() {
  ios::sync_with_stdio(0);
  long long T;
  cin >> T;
  while (T--) {
    memset(dp, 0, sizeof dp);
    memset(ans, 0, sizeof ans);
    memset(a, 0, sizeof a);
    cin >> n >> k;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (long long i = 1; i <= n - 1; i++) {
      dp[i] = pow(10ll, a[i + 1] - a[i]) - 1ll;
    }
    long long so = k + 1;
    for (long long i = 1; i <= n - 1; i++) {
      if (so >= dp[i]) {
        so -= dp[i];
        ans[i] = dp[i];
      } else {
        ans[i] = so;
        so = 0;
      }
    }
    an = "";
    for (long long i = 1; i < n; i++) {
      string t = to_string(ans[i]);
      reverse(t.begin(), t.end());
      an += t;
    }
    if (so > 0) {
      string t = to_string(so);
      reverse(t.begin(), t.end());
      an += t;
    }
    reverse(an.begin(), an.end());
    cout << an << endl;
  }
}
