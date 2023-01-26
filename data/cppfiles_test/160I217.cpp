#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
long long int dp[200001][18];
void solve() {
  long long int n, m, rc, cc, rb, cb;
  cin >> n >> m >> rc >> cc >> rb >> cb;
  if (rb == rc) {
    cout << 0 << "\n";
  } else if (cc == cb) {
    cout << 0 << "\n";
  } else if (rc > rb && cc > cb) {
    cout << n - rc + m - cc + min(rc - rb, cc - cb) << "\n";
  } else if (rc >= rb) {
    cout << cb - cc << "\n";
  } else if (cc >= cb) {
    cout << rb - rc << "\n";
  } else {
    cout << min(rb - rc, cb - cc) << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long int t = 1;
  for (long long int i = 1; i <= 200000; i++) {
    for (long long int j = 0; j < 18; j++) {
      dp[i][j] = dp[i - 1][j] + (((1 << j) & i) == 0);
    }
  }
  cin >> t;
  while (t--) {
    solve();
  }
}
