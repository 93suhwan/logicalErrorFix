#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long n, a[100005], dp[2][100005];
vector<long long> v[2];
void solve() {
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  long long ans = 0;
  memset(dp, 0, sizeof dp);
  v[0].clear();
  v[1].clear();
  for (long long i = n; i >= 1; i--) {
    long long m = i & 1;
    v[m].push_back(a[i]);
    dp[m][a[i]] = 1;
    long long last = a[i];
    for (auto num : v[1 - m]) {
      long long dv = (a[i] + num - 1) / num;
      ans = (ans + (dv - 1) * i * dp[1 - m][num] % mod) % mod;
      dp[m][a[i] / dv] = (dp[m][a[i] / dv] + dp[1 - m][num]) % mod;
      if (last != a[i] / dv) {
        last = a[i] / dv;
        v[m].push_back(last);
      }
    }
    for (auto x : v[1 - m]) dp[1 - m][x] = 0;
    v[1 - m].clear();
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
