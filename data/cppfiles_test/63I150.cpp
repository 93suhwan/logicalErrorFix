#include <bits/stdc++.h>
using namespace std;
string s[25];
int dp[(1 << 20) + 5], n, cnt, mn[25], sum[24], dp1[(1 << 20) + 3][22];
map<int, int> first[22];
map<int, vector<int> > mp[22];
int call(int mask, int val) {
  if (mask == (1 << n) - 1) return 0;
  if (dp[mask] != -1) return dp[mask];
  int ret = 0, c, i, j;
  for (i = 0; i < n; i++) {
    if (mask & (1 << i)) continue;
    if (dp1[mask][i] != -1) {
      ret = max(ret, dp1[mask][i]);
      continue;
    }
    if (val + mn[i] < 0) goto go;
    c = mp[i][0 - val].size();
    ret = max(ret, c + call(mask | (1 << i), val + sum[i]));
    continue;
  go:
    int p = first[i][0 - (val + 1)];
    c = upper_bound(mp[i][0 - val].begin(), mp[i][0 - val].end(), p) -
        mp[i][0 - val].begin();
    ret = max(ret, c);
  }
  return dp[mask] = ret;
}
int main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
  }
  int i, j, k, m, c, t, x, y;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> s[i];
    m = s[i].size();
    c = 0;
    x = INT_MAX;
    for (j = 0; j < m; j++) {
      if (s[i][j] == '(')
        c++;
      else
        c--;
      x = min(x, c);
      if (mp[i][c].size() == 0) first[i][c] = j;
      mp[i][c].push_back(j);
    }
    sum[i] = c;
    mn[i] = x;
  }
  memset(dp, -1, sizeof(dp));
  memset(dp1, -1, sizeof(dp));
  int ans = call(0, 0);
  cout << ans << "\n";
}
