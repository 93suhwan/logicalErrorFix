#include <bits/stdc++.h>
#pragma optimize("ofast")
#pragma optimize("unroll-loops")
#pragma optimize("o3")
using namespace std;
const int N = 2e6, INF = 1e9 + 2, MOD = 1e9 + 7;
string mas[22];
int mn[22];
int en[22];
unordered_map<int, int> cnt[22];
pair<int, int> dp[N];
pair<int, int> add(int i, pair<int, int> res) {
  for (int j = 0; j < mas[i].size(); j++) {
    if (mas[i][j] == ')')
      res.first--;
    else
      res.first++;
    if (res.first < 0) {
      return res;
    }
    if (res.first == 0) res.second++;
  }
  return res;
}
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> mas[i];
  for (int i = 0; i < n; i++) {
    int c = 0;
    for (int j = 0; j < mas[i].size(); j++) {
      if (mas[i][j] == '(')
        c++;
      else
        c--;
      if (c < mn[i]) {
        mn[i] = c;
      }
      if (c == mn[i]) cnt[i][c]++;
    }
    en[i] = c;
  }
  for (int i = 0; i < N; i++) {
    dp[i] = {-1, -1};
  }
  dp[0] = {0, 0};
  int ans = 0;
  for (int mask = 0; mask < (1 << n); mask++) {
    if (dp[mask].first < 0) continue;
    for (int j = 0; j < n; j++) {
      if ((mask & (1 << j)) == 0) {
        int nextmask = mask ^ (1 << j);
        if (dp[mask].first >= -mn[j]) {
          pair<int, int> a = {dp[mask].first + en[j], dp[mask].second};
          if (dp[mask].first == -mn[j]) a.second += cnt[j][-dp[mask].first];
          ans = max(ans, a.second);
          if (a.first >= 0 && a.second > dp[nextmask].second) {
            dp[nextmask] = a;
          }
        } else {
          pair<int, int> a = {-1, dp[mask].second + cnt[j][-dp[mask].first]};
          ans = max(ans, a.second);
        }
      }
    }
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) solve();
}
