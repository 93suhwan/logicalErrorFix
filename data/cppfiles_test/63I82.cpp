#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int n, mn[22], sum[22][400005], dp[(1 << 21)];
string s[22];
multiset<pair<int, int> > v[22];
map<int, vector<int> > vl[22];
int f(int mask, int lst) {
  if (lst < 0) return 0;
  if (mask == (1 << n) - 1) return 0;
  if (dp[mask] != -1) return dp[mask];
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if ((mask & (1 << i))) continue;
    int r = s[i].size(), ad;
    if (v[i].upper_bound({lst, 1e9}) != v[i].end())
      r = (*v[i].upper_bound({lst, 1e9})).second;
    ad = upper_bound(vl[i][-lst].begin(), vl[i][-lst].end(), r) -
         vl[i][-lst].begin() - 1;
    if (upper_bound(vl[i][-lst].begin(), vl[i][-lst].end(), r) ==
        vl[i][-lst].end())
      ad++;
    if (r == s[i].size())
      ans = max(ans, f((mask | (1 << i)), sum[i][r - 1] + lst) + ad);
    else
      ans = max(ans, ad);
  }
  return dp[mask] = ans;
}
int main() {
  memset(dp, -1, sizeof dp);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    mn[i] = 1e9;
    for (int j = 0; j < s[i].size(); j++) {
      if (s[i][j] == '(') sum[i][j]++;
      if (s[i][j] == ')') sum[i][j]--;
      if (j) sum[i][j] += sum[i][j - 1];
      mn[i] = min(mn[i], sum[i][j]);
      v[i].insert({-sum[i][j], j});
      vl[i][sum[i][j]].push_back(j);
    }
  }
  cout << f(0, 0);
}
