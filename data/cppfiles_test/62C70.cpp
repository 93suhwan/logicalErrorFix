#include <bits/stdc++.h>
using namespace std;
const long long md = 1000000007;
long long icase = 1;
void google(long long t) { cout << "Case #" << t << ": "; }
const long long limt = 1e3 + 5;
long long ans;
long long dp[2][limt][limt];
bool state[limt][limt];
long long m, n, k;
void update(long long r, long long c) {
  if (r > m || c > n) return;
  ans -= dp[0][r][c] + dp[1][r][c];
  if (state[r][c]) {
    dp[0][r][c] = dp[1][r][c] = 0;
  } else {
    dp[0][r][c] = dp[1][r][c - 1] + 1;
    dp[1][r][c] = dp[0][r - 1][c] + 1;
    ans += dp[0][r][c] + dp[1][r][c];
  }
}
void subMain() {
  cin >> m >> n >> k;
  for (long long i = 1; i <= m; i++) {
    for (long long j = 1; j <= n; j++) {
      update(i, j);
    }
  }
  long long r, c;
  ans -= m * n;
  while (k--) {
    cin >> r >> c;
    state[r][c] ^= 1;
    ans += (state[r][c] ? 1 : -1);
    for (long long i = r; i <= m; i++) {
      update(i, c + i - r);
      update(i, c + i - r + 1);
      update(i + 1, c + i - r);
    }
    cout << ans << endl;
  }
}
int32_t main() {
  long long t = 1;
  while (t--) {
    subMain();
  }
  return 0;
}
