#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> a(5, vector<int>(n));
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    vector<int> aa(5);
    for (int j = 0; j < s.size(); j++) {
      aa[s[j] - 'a']++;
    }
    for (int j = 0; j < 5; j++) {
      a[j][i] = 2 * aa[j] - s.size();
    }
  }
  int ans = 0;
  for (int i = 0; i < 5; i++) {
    sort(a[i].begin(), a[i].end(), greater<int>());
    long long sum = 0;
    int j = 0;
    for (; j < n; j++) {
      sum += a[i][j];
      if (sum <= 0) {
        break;
      }
    }
    ans = max(j, ans);
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
