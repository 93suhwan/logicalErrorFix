#include <bits/stdc++.h>
using namespace std;
const int maxn = 20, maxm = 4e5 + 3;
vector<vector<int> > bals, prefs;
vector<vector<vector<int> > > cnt(maxn, vector<vector<int> >(2 * maxm));
int calc(int bal, int a) {
  int ind = int(upper_bound(prefs[a].begin(), prefs[a].end(), bal) -
                prefs[a].begin()) -
            1;
  if (ind < 0) {
    return 0;
  }
  return int(
      upper_bound(cnt[a][-bal + maxm].begin(), cnt[a][-bal + maxm].end(), ind) -
      cnt[a][-bal + maxm].begin());
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> mn(n, 1e9);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    vector<int> bal((int)s.size()), pref((int)s.size());
    bal[0] = (s[0] == '(' ? 1 : -1);
    cnt[i][bal[0] + maxm].push_back(0);
    pref[0] = -bal[0];
    for (int j = 1; j < (int)s.size(); j++) {
      bal[j] = bal[j - 1] + (s[j] == '(' ? 1 : -1);
      cnt[i][bal[j] + maxm].push_back(j);
      mn[i] = min(mn[i], bal[j]);
      pref[j] = max(pref[j - 1], -bal[j]);
    }
    bals.push_back(bal);
    prefs.push_back(pref);
  }
  vector<int> dp(1 << n);
  for (int mask = 0; mask < (1 << n); mask++) {
    int curr_bal = 0;
    bool f = false;
    for (int i = 0; i < n; i++) {
      if ((1 << i) & mask) {
        if (curr_bal + mn[i] < 0) {
          f = 1;
        }
        curr_bal += bals[i][bals[i].size() - 1];
      }
    }
    for (int i = 0; i < n; i++) {
      if ((1 << i) & mask) {
        continue;
      }
      dp[mask | (1 << i)] =
          max(dp[mask | (1 << i)], dp[mask] + (f ? 0 : calc(curr_bal, i)));
    }
  }
  cout << dp[(1 << n) - 1];
  return 0;
}
