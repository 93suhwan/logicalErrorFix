#include <bits/stdc++.h>
using namespace std;
int dp[1 << 23];
int cnt[23][26];
string s[23];
const int P = 998244353;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (auto& j : s[i]) {
      cnt[i][j - 'a']++;
    }
  }
  int c[26]{};
  fill(dp, dp + (1 << n), 1);
  for (int i = 1; i < (1 << n); i++) {
    fill(c, c + 26, 1e9);
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        for (int t = 0; t < 26; t++) {
          c[t] = min(c[t], cnt[j][t]);
        }
      }
    }
    for (int t = 0; t < 26; t++) {
      dp[i] = dp[i] * (c[t] + 1ll) % P;
    }
    if (__builtin_parity(i) == 0) {
      if (dp[i]) dp[i] = P - dp[i];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (1 << n); j++) {
      if (j & (1 << i)) {
        dp[j] += dp[j ^ (1 << i)];
        if (dp[j] >= P) dp[j] -= P;
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i < (1 << n); i++) {
    int s = 0, c = 0;
    dp[i]--;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        s += j + 1, c++;
      }
    }
    ans ^= dp[i] * 1ll * s * c;
  }
  cout << ans;
}
