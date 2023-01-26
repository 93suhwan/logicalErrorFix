#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int S = 26, N = 23, MOD = 998244353;
long long have[N][S];
int dp[S][1 << N];
int fir[1 << N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (auto c : a[i]) have[i][c - 'a']++;
  }
  for (int i = 0; i < n; i++) {
    for (int mask = 0; mask < (1 << (n - i - 1)); mask++) {
      fir[(mask << (i + 1)) ^ 1] = i;
    }
  }
  for (int i = 0; i < S; i++) {
    for (int mask = 1; mask < (1 << n); mask++) {
      int j = fir[mask];
      if (i == 0)
        dp[i][mask] = max(0ll + dp[0][mask ^ (1 << j)], have[j][0]);
      else
        dp[i][mask] =
            (dp[i][mask ^ (1 << j)] +
             have[j][i] * (dp[i - 1][mask] - dp[i - 1][mask ^ (1 << j)])) %
            MOD;
    }
  }
  long long ans = 0;
  for (int mask = 0; mask < (1 << n); mask++) {
    int cur = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
      if ((mask >> i) & 1) {
        cur += i + 1, cnt++;
      }
    }
    ans ^= cur * cnt * 1ll * dp[25][mask];
  }
  cout << ans << '\n';
}
