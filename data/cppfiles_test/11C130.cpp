#include <bits/stdc++.h>
using namespace std;
void intStart() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
void solve() {
  int n;
  cin >> n;
  vector<string> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  vector<vector<int> > dp(n, vector<int>(6, 0));
  for (int i = 0; i < n; i++) {
    string s = v[i];
    for (int j = 0; j < s.size(); j++) {
      dp[i][s[j] - 'a']++;
    }
  }
  for (int i = 0; i < n; i++) {
    int x = 0;
    for (int j = 0; j < 5; j++) x = x + dp[i][j];
    dp[i][5] = x;
  }
  int ans = 0;
  for (int i = 0; i < 5; i++) {
    int cnt = 0, other = 0;
    vector<int> t;
    for (int j = 0; j < n; j++) {
      int x = dp[j][i];
      int y = dp[j][5] - x;
      t.push_back(x - y);
    }
    sort(t.begin(), t.end());
    reverse(t.begin(), t.end());
    int c = 0;
    for (int j = 0; j < t.size(); j++) {
      if (t[j] > 0) {
        c++;
        cnt = cnt + t[j];
      } else {
        if (cnt > other + abs(t[j])) {
          c++;
          other += abs(t[j]);
        }
      }
    }
    ans = max(ans, c);
  }
  cout << ans << endl;
}
int main() {
  intStart();
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
