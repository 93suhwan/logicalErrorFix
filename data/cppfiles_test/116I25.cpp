#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
const long long INF = 1e9 + 10;
long long MOD = 998244353;
long double EPS = 1e-12;
void fastIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long t, n, a[MAXN];
long long dp1[MAXN], dp2[MAXN];
long long sum(long long x, long long y) { return (x + y) % MOD; }
int main() {
  fastIO();
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    fill(dp1, dp1 + n + 1, 0);
    fill(dp2, dp2 + n + 1, 0);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int val = a[i];
      dp1[val] = sum(dp1[val], dp1[val]);
      dp2[val] = sum(dp2[val], dp2[val]);
      if (val > 0) {
        dp1[val] = sum(dp1[val], dp1[val - 1]);
      } else {
        dp1[val] = sum(dp1[val], 1);
      }
      if (val > 1) {
        dp2[val] = sum(dp2[val], dp1[val - 2]);
      } else if (val == 1) {
        dp2[val] = sum(dp2[val], 1);
      }
    }
    for (int i = 0; i <= n; i++) {
      ans = sum(ans, dp1[i]);
      ans = sum(ans, dp2[i]);
    }
    cout << ans << '\n';
  }
  return 0;
}
