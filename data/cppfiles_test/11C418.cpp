#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> store(5);
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    vector<int> cnt(5, 0);
    for (auto x : s) {
      cnt[x - 'a']++;
    }
    for (int i = 0; i < 5; i++) {
      store[i].push_back(cnt[i] - ((long long int)s.size() - cnt[i]));
    }
  }
  for (int i = 0; i < 5; i++) {
    sort(store[i].begin(), store[i].end(), greater<int>());
  }
  int ans = 0;
  for (int i = 0; i < 5; i++) {
    int diff = 0, count = 0;
    for (int j = 0; j < store[i].size(); j++) {
      diff += store[i][j];
      if (diff > 0)
        count++;
      else
        break;
    }
    ans = max(ans, count);
  }
  cout << ans << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
