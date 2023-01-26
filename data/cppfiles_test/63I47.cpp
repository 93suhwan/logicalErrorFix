#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  vector<string> s(n);
  vector<int> cost(1 << n, 0);
  for (int i = 0; i < n; i++) cin >> s[i], cost[1 << i] = count(s[i].begin(), s[i].end(), '(') - count(s[i].begin(), s[i].end(), ')');
  for (int mask = 0; mask < (1 << n); mask++) {
    if ((mask & (mask - 1)) == 0) continue;
    for (int i = 0; i < n; i++) if (mask & (1 << i)) cost[mask] += cost[1 << i];
  }
  vector<int> mn(n, 0);
  vector< map<int, vector<int> > > pos(n);
  for (int i = 0; i < n; i++) {
    int cur = 0;
    for (int j = 0; j < (int) s[i].length(); j++) {
      if (s[i][j] == '(') cur++;
      else cur--;
      mn[i] = min(mn[i], cur);
      pos[i][cur].push_back(j);
    }
  }

  auto go = [&](int x, int b, int i) {
    if (b) return 0;
    int idx = pos[i][-x - 1].empty() ? INF : pos[i][-x - 1][0];
    auto it = lower_bound(pos[i][-x].begin(), pos[i][-x].end(), idx);
    return it - pos[i][-x].begin();
  };

  int dp[1 << n][2];
  memset(dp, 0, sizeof dp);
  for (int mask = 0; mask < (1 << n); mask++) {
    for (int b = 0; b < 2; b++) {
      for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) continue;
        dp[mask | (1 << i)][b || cost[mask] + mn[i] < 0] = max(dp[mask | (1 << i)][b || cost[mask] + mn[i] < 0], dp[mask][b] + go(cost[mask], b, i));
      }
    }
  }
  cout << max(dp[(1 << n) - 1][0], dp[(1 << n) - 1][1]) << '\n';
  return 0;
}