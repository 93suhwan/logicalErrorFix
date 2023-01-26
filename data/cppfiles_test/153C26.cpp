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
  vector<int> min_used(1 << n);
  for (int mask = 1; mask < (1 << n); mask++)
    for (int j = 0; j < n; j++)
      if (mask & (1 << j)) {
        min_used[mask] = j;
        break;
      }
  vector<vector<int> > dp(27, vector<int>(1 << n));
  for (int i = 0; i < (1 << n); i++) dp[26][i] = 1;
  dp[26][0] = 0;
  for (int let = 25; let >= 0; let--) {
    vector<pair<int, int> > min_string(1 << n);
    min_string[0] = {1000000000, -1};
    for (int mask = 1; mask < (1 << n); mask++) {
      int mu = min_used[mask];
      min_string[mask] =
          min(min_string[mask - (1 << mu)], make_pair(v[mu][let], mu));
    }
    for (int mask = 1; mask < (1 << n); mask++) {
      pair<int, int> mn = min_string[mask];
      dp[let][mask] =
          (((long long)dp[let][mask - (1 << mn.second)] -
            (long long)dp[let + 1][mask - (1 << mn.second)] * (mn.first + 1) +
            (long long)dp[let + 1][mask] * (mn.first + 1)) %
               mod +
           mod) %
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
