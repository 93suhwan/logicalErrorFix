#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<map<int, int>> m(n, map<int, int>());
  vector<int> a(n);
  for (int j = 0; j < n; ++j) {
    string s;
    cin >> s;
    int acu = 0, mn = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(')
        acu += 1;
      else
        acu -= 1;
      if (acu <= mn && s[i] == ')') ++m[j][acu];
      mn = min(acu, mn);
    }
    a[j] = acu;
  }
  vector<int> dp(1 << n, 0);
  int ans = 0;
  for (int msk = 1; msk < 1 << n; ++msk) {
    int acu = 0;
    for (int k = 0; k < n; ++k) {
      if (msk & (1 << k)) acu += a[k];
    }
    for (int k = 0; k < n; ++k) {
      if (!(msk & (1 << k))) continue;
      int cur = dp[msk ^ (1 << k)];
      auto it = m[k].find(-(acu - a[k]));
      if (it != m[k].end()) cur += (*it).second;
      dp[msk] = max(dp[msk], cur);
    }
    ans = max(ans, dp[msk]);
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
