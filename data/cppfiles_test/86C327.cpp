#include <bits/stdc++.h>
using namespace std;
void run() {
  int n;
  cin >> n;
  string s[2];
  cin >> s[0];
  cin >> s[1];
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[0][i] != s[1][i]) {
      ans += 2;
    } else if (s[0][i] == '0' && s[1][i] == '0') {
      ans += 1;
    }
  }
  vector<int> typ;
  for (int i = 0; i + 1 < n; i++) {
    if (s[0][i] == '0' && s[1][i] == '0' && s[0][i + 1] == '1' &&
        s[1][i + 1] == '1') {
      typ.push_back(i);
    } else if (s[0][i] == '1' && s[1][i] == '1' && s[0][i + 1] == '0' &&
               s[1][i + 1] == '0') {
      typ.push_back(i);
    }
  }
  int k = (int)typ.size();
  if (k == 0) {
    ;
  } else if (k == 1) {
    ans += 1;
  } else {
    vector<int> dp(k);
    dp[0] = 1;
    dp[1] = 1 + (typ[1] != typ[0] + 1);
    for (int i = 2; i < k; i++) {
      dp[i] = dp[i - 2] + 1;
      if (typ[i] != typ[i - 1] + 1) dp[i] = max(dp[i], dp[i - 1] + 1);
    }
    ans += dp.back();
  }
  cout << ans << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) run();
}
