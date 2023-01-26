#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long>>;
using vpi = vector<pair<int, int>>;
const long long infl = 1LL << 60;
long long mod = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  int t = 1;
  while (t--) {
    long long n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    long long dp[n + 1][6];
    memset(dp, 0, sizeof(dp));
    vvll v = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 6; j++) {
        dp[i][j] = dp[i - 1][j];
        if (s[i - 1] == 'a' && v[j][0] == (i - 1) % 3) dp[i][j]++;
        if (s[i - 1] == 'b' && v[j][1] == (i - 1) % 3) dp[i][j]++;
        if (s[i - 1] == 'c' && v[j][2] == (i - 1) % 3) dp[i][j]++;
      }
    }
    while (q--) {
      long long l, r;
      cin >> l >> r;
      long long ans = (1LL << 60);
      for (int i = 0; i < 6; i++)
        ans = min(ans, r - l + 1 - dp[r][i] + dp[l - 1][i]);
      cout << ans << endl;
    }
  }
}
