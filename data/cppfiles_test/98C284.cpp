#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    map<char, int> mp;
    int ans = 0;
    for (int i = 0; i < s1.size(); i++) {
      mp[s1[i]] = i;
    }
    for (int i = 0; i < s2.size() - 1; i++) {
      ans = ans + abs(mp[s2[i]] - mp[s2[i + 1]]);
    }
    cout << ans << "\n";
  }
  return 0;
}
