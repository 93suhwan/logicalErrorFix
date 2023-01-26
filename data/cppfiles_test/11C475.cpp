#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> v[26];
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    int m = s.size();
    vector<int> temp(5, 0);
    for (char c : s) {
      int x = (c - 'a');
      temp[x]++;
    }
    for (int j = 0; j < 5; ++j) v[j].push_back(2 * temp[j] - m);
  }
  int ans = 0;
  for (int i = 0; i < 5; ++i) {
    sort(begin(v[i]), end(v[i]), greater<int>());
    int extra = 0, temp = 0;
    for (int j : v[i]) {
      if (extra + j > 0) {
        temp++;
        extra += j;
      } else
        break;
    }
    ans = max(ans, temp);
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
