#include <bits/stdc++.h>
using namespace std;
long long n, dp[(1 << 20)], pre[(1 << 20)], cost[25];
map<long long, vector<long long>> mp[25];
vector<long long> pmn[25];
inline void solve() {
  cin >> n;
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    string str;
    cin >> str;
    long long mn = 0, sum = 0, t = 0;
    for (long long j = 0; j < (long long)(str.size()); j++) {
      if (str[j] == ')')
        sum--;
      else
        sum++;
      mn = min(mn, sum);
      mp[i][sum].emplace_back(j);
      if (mn >= 0 and sum == 0) t++;
      pmn[i].emplace_back(-mn);
    }
    ans = max(ans, t);
    cost[i] = sum;
  }
  for (long long i = 1; i < (1 << n); i++)
    pre[i] = pre[i ^ (i & -i)] + cost[__builtin_ctz(i)];
  for (long long i = 0; i < (1 << n); i++) {
    for (long long j = 0; j < n; j++) {
      if (((i >> j) & 1)) continue;
      long long now = pre[i];
      if (-pmn[j].back() >= now) {
        dp[i ^ (1 << j)] =
            max(dp[i ^ (1 << j)], dp[i] + (long long)(mp[j][-now].size()));
        ans = max(ans, dp[i ^ (1 << j)]);
      } else {
        long long id =
            upper_bound(pmn[j].begin(), pmn[j].end(), now) - pmn[j].begin();
        long long add =
            lower_bound(mp[j][-now].begin(), mp[j][-now].end(), id) -
            mp[j][-now].begin();
        ans = max(ans, dp[i] + add);
      }
    }
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  solve();
}
