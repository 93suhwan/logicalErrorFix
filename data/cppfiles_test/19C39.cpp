#include <bits/stdc++.h>
using namespace std;
const long long N = 2e4 + 5;
long long arr[N];
long long dp[2][2005];
void solve() {
  long long n;
  cin >> n;
  for (long long i = (long long)0; i < (long long)n; i++) {
    cin >> arr[i];
  }
  for (long long i = (long long)0; i < (long long)2; i++) {
    for (long long j = (long long)0; j < (long long)2005; j++) {
      dp[i][j] = ((long long)(1e9 + 7) * (long long)(1e9 + 7));
    }
  }
  dp[0][0] = 0;
  for (long long i = (long long)0; i < (long long)n; i++) {
    long long a = arr[i];
    long long cur = i % 2;
    for (long long j = (long long)0; j < (long long)2005; j++) {
      dp[!cur][j] = ((long long)(1e9 + 7) * (long long)(1e9 + 7));
    }
    for (long long l = (long long)0; l < (long long)2005; l++) {
      long long lenR = dp[cur][l];
      if (l + a < 2005) {
        long long newPos = l + a;
        long long r = lenR + l;
        long long newLenR = (newPos >= r) ? 0 : r - newPos;
        dp[!cur][newPos] = min(dp[!cur][newPos], newLenR);
      }
      long long newPos = max(0ll, l - a);
      long long newR = lenR + a;
      dp[!cur][newPos] = min(dp[!cur][newPos], newR);
    }
  }
  long long ans = ((long long)(1e9 + 7) * (long long)(1e9 + 7));
  for (long long l = (long long)0; l < (long long)2005; l++) {
    ans = min({ans, l + dp[n % 2][l]});
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tests = 1;
  cin >> tests;
  for (long long i = (long long)0; i < (long long)tests; i++) {
    solve();
    cout << "\n";
  }
  return 0;
}
