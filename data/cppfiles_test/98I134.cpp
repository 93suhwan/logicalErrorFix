#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    vector<pair<char, int>> vec(26);
    for (int i{}; i < 26; i++) {
      cin >> vec[i].first;
      vec[i].second = i;
    }
    long long ans{};
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 1; i < n; i++) {
      ans += abs(vec[s[i] - 'a'].second - vec[s[i - 1] - 'a'].second);
    }
    cout << ans << endl;
  }
  return 0;
}
