#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, ans = 0;
  cin >> n;
  vector<string> v;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    v.push_back(s);
  }
  vector<vector<int>> v1(n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 5; j++) v1[i].push_back(0);
  for (int i = 0; i < n; i++) {
    string s = v[i];
    for (int j = 0; j < s.size(); j++) v1[i][s[j] - 'a']++;
  }
  for (int i = 0; i < 5; i++) {
    vector<int> v3;
    for (int j = 0; j < n; j++) {
      string s1 = v[j];
      int n2 = s1.size(), cnt = v1[j][i], diff = cnt - (n2 - cnt);
      v3.push_back(diff);
    }
    sort(v3.begin(), v3.end());
    reverse(v3.begin(), v3.end());
    int till = 0;
    for (int k = 0; k < n; k++) {
      till += v3[k];
      if (till > 0) ans = max(ans, k + 1);
    }
  }
  cout << ans << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
