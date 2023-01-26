#include <bits/stdc++.h>
using namespace std;
long long dp[1200], dp2[1200];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long a, b, c, d, f, gg = 0, i, j, m, n, t, mod = 1e9 + 7;
  cin >> n;
  for (i = 1; i < 1100; i++) {
    dp[i] = INT_MAX;
    dp2[i] = INT_MAX;
  }
  for (i = 0; i < n; i++) {
    cin >> a;
    for (j = 0; j < 1100; j++) {
      if (dp[j] < a) {
        dp2[j ^ a] = min(dp[j ^ a], a);
      }
    }
    for (j = 0; j < 1100; j++) dp[j] = min(dp[j], dp2[j]);
  }
  f = 0;
  for (j = 0; j < 1100; j++)
    if (dp[j] < INT_MAX) f++;
  cout << f << '\n';
  for (j = 0; j < 1100; j++)
    if (dp[j] < INT_MAX) cout << j << ' ';
  return 0;
}
