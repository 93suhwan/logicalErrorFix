#include <bits/stdc++.h>
#pragma GCC optimize("O4,unroint-loops,no-stack-protector")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
void Why_does_competitive_programming_even_exist() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
void YayXD() { return; }
long long n;
long long arr[100005];
long long dp[2][100005];
set<long long> v[2];
signed main() {
  Why_does_competitive_programming_even_exist();
  long long t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (long long i = 1; i <= n; i++) {
      cin >> arr[i];
    }
    for (long long i = 1; i <= n; i++) {
      dp[0][i] = 0;
      dp[1][i] = 0;
    }
    v[0].clear();
    v[1].clear();
    dp[n % 2][arr[n]] = 1;
    v[n % 2].insert(arr[n]);
    long long ans = 0;
    for (long long i = n - 1; i >= 1; i--) {
      for (long long x : v[(i + 1) % 2]) {
        long long cuts = (arr[i] - 1) / x;
        long long minn = arr[i] / (cuts + 1);
        dp[i % 2][minn] += dp[(i + 1) % 2][x];
        dp[i % 2][minn] %= 998244353;
        ans += dp[(i + 1) % 2][x] * cuts % 998244353 * i % 998244353;
        v[i % 2].insert(minn);
        dp[(i + 1) & 1][x] = 0;
      }
      v[(i + 1) & 1].clear();
      dp[i % 2][arr[i]] += 1;
      v[i % 2].insert(arr[i]);
    }
    cout << ans << "\n";
  }
}
