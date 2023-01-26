#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long I = 0; I < n; I++) cin >> v[I];
  ;
  long long mxor = 512;
  vector<long long> dp(mxor, 1e9);
  dp[0] = 0;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < mxor; j++) {
      if (v[i] > dp[j]) {
        long long k = v[i] ^ j;
        dp[k] = min(dp[k], v[i]);
      }
    }
  }
  vector<long long> ans;
  for (long long i = 0; i < mxor; i++) {
    if (dp[i] == 1e9) continue;
    ans.push_back(i);
  }
  cout << ans.size() << "\n";
  for (long long I = 0; I < ans.size(); I++) cout << ans[I] << " ";
  cout << "\n";
  ;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}
