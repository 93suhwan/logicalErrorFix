#include <bits/stdc++.h>
using namespace std;
long long dx[] = {0, 1, 0, -1};
long long dy[] = {1, 0, -1, 0};
const long long INF = 1e18;
const long long MOD = 998244353;
const long long N = 1e5 + 5;
long long n;
long long a[N];
long long dp[2][N];
vector<long long> v[2];
void solve() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long res = 0;
  for (long long i = n; i >= 1; i--) {
    long long k = i & 1;
    long long val = a[i];
    dp[k][val] = 1;
    v[k].push_back(val);
    for (long long x : v[k ^ 1]) {
      long long j = (val - 1) / x + 1;
      long long temp = val / j;
      dp[k][temp] += dp[k ^ 1][x];
      res += (j - 1) * dp[k ^ 1][x] * i;
      res %= MOD;
      if (temp != v[k].back()) {
        v[k].push_back(temp);
      }
    }
    for (long long x : v[k ^ 1]) dp[k ^ 1][x] = 0;
    v[k ^ 1].clear();
  }
  for (long long x : v[1]) dp[1][x] = 0;
  v[1].clear();
  cout << res << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long T;
  cin >> T;
  while (T--) solve();
}
