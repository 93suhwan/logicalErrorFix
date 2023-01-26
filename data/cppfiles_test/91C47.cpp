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
signed main() {
  Why_does_competitive_programming_even_exist();
  long long t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (long long i = 1; i <= n; i++) {
      cin >> arr[i];
    }
    vector<long long> v[2];
    dp[n & 1][arr[n]] = 1;
    v[n & 1].push_back(arr[n]);
    long long ans = 0;
    for (long long i = n - 1; i >= 1; i--) {
      v[i & 1].push_back(arr[i]);
      dp[i & 1][arr[i]] = 1;
      long long pre = arr[i];
      for (long long x : v[(i + 1) & 1]) {
        long long cuts = (arr[i] - 1) / x;
        long long minn = arr[i] / (cuts + 1);
        dp[i & 1][minn] += dp[(i + 1) & 1][x];
        ans += dp[(i + 1) & 1][x] * cuts % 998244353 * i % 998244353;
        ans %= 998244353;
        if (pre != minn) {
          v[i & 1].push_back(minn);
          pre = minn;
        }
        dp[(i + 1) & 1][x] = 0;
      }
      v[(i + 1) & 1].clear();
    }
    cout << ans << "\n";
    for (long long i : v[1]) {
      dp[0][i] = 0;
      dp[1][i] = 0;
    }
  }
}
