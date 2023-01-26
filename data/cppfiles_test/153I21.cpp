#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int> > v(n, vector<int>(26));
  long long mod = 998244353;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int ptr = 0;
    for (int j = 0; j < 26; j++) {
      while (ptr < s.size() && s[ptr] - 'a' == j) {
        v[i][j]++;
        ptr++;
      }
    }
  }
  vector<vector<pair<int, int> > > cnt_order(26);
  for (int let = 0; let < 26; let++) {
    for (int j = 0; j < n; j++) cnt_order[let].push_back({v[j][let], j});
    sort(cnt_order[let].begin(), cnt_order[let].end());
  }
  vector<vector<int> > dp(27, vector<int>(1 << n));
  for (int i = 0; i < (1 << n); i++) dp[26][i] = 1;
  dp[26][0] = 0;
  for (int let = 25; let >= 0; let--) {
    for (int mask = 1; mask < (1 << n); mask++) {
      vector<pair<int, int> > cnts = {{-1, -1}};
      int accum_mask = 0;
      for (int i = 0; i < n; i++)
        if (mask & (1 << cnt_order[let][i].second)) {
          cnts.push_back(cnt_order[let][i]);
        }
      if (cnts.back().first == cnts[cnts.size() - 2].first)
        dp[let][mask] = dp[let + 1][mask];
      else
        dp[let][mask] =
            ((long long)dp[let + 1][mask] * (cnts[cnts.size() - 2].first + 1) +
             (long long)dp[let + 1][1 << cnts.back().second] *
                 (cnts.back().first - cnts[cnts.size() - 2].first)) %
            mod;
    }
  }
  long long ans = 0;
  for (int mask = 0; mask < (1 << n); mask++) {
    int sum = 0, cnt = 0;
    for (int i = 0; i < n; i++)
      if (mask & (1 << i)) {
        cnt++;
        sum += i + 1;
      }
    ans = (ans ^ ((long long)dp[0][mask] * cnt * sum));
  }
  cout << ans << endl;
}
