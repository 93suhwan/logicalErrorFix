#include <bits/stdc++.h>
using namespace std;
int n;
void solve() {
  cin >> n;
  vector<map<int, int>> m(n, map<int, int>());
  vector<int> a(n), b(n);
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
    b[j] = mn;
    a[j] = acu;
  }
  vector<int> dp(1 << n, 0);
  int su = accumulate(a.begin(), a.end(), 0);
  int ans = 0;
  for (int msk = 1; msk < 1 << n; ++msk) {
    int s0 = 0;
    set<array<int, 2>> s;
    for (int k = 0; k < n; ++k) {
      if (msk & (1 << k))
        s0 += a[k];
      else
        s.insert({a[k], b[k]});
    }
    int acu = 0;
    bool cant = false;
    while (s.size()) {
      auto it = prev(s.end());
      while (acu + (*it)[1] < 0) {
        if (it == s.begin()) {
          cant = true;
          break;
        }
        --it;
      }
      if (cant) break;
      acu += (*it)[0];
      s.erase(it);
    }
    if (cant) continue;
    for (int k = 0; k < n; ++k) {
      if (!(msk & (1 << k))) continue;
      dp[msk] = max(dp[msk], dp[msk ^ (1 << k)]);
      auto it = m[k].find(-(su - s0));
      if (it != m[k].end())
        dp[msk] = max(dp[msk], dp[msk ^ (1 << k)] + (*it).second);
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
