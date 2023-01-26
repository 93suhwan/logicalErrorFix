#include <bits/stdc++.h>
using namespace std;
string s[25];
int dp[(1 << 20) + 5], n, cnt, mn[25], sum[24];
map<int, int> mp[22];
int call(int mask, int val) {
  if (mask == (1 << n) - 1) return 0;
  if (dp[mask] != -1) return dp[mask];
  int ret = 0, c, i, j;
  for (i = 0; i < n; i++) {
    if (mask & (1 << i)) continue;
    if (cnt + mn[i] < 0) goto go;
    c = mp[i][0 - cnt];
    ret = max(ret, c + call(mask | (1 << i), val + sum[i]));
    continue;
  go:
    c = 0;
    cnt = val;
    int l = s[i].size();
    for (j = 0; j < l; j++) {
      if (s[i][j] == '(')
        cnt++;
      else
        cnt--;
      if (cnt == 0)
        c++;
      else if (cnt < 0)
        break;
    }
    if (j != l)
      ret = max(ret, c);
    else
      ret = max(ret, c + call(mask | (1 << i), cnt));
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
      mp[i][c]++;
    }
    sum[i] = c;
    mn[i] = x;
  }
  memset(dp, -1, sizeof(dp));
  cout << call(0, 0);
}
