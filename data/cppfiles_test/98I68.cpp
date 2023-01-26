#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  unordered_map<char, int> mp;
  int tc = t;
  while (tc--) {
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    for (int i = 1; i <= 26; i++) {
      mp[s1[i - 1]] = i;
    }
    int ans = 0;
    for (int i = 1; i < s2.size(); i++) {
      ans += abs(mp[s2[i]] - mp[s2[i - 1]]);
      cout << ans;
    }
    cout << ans << endl;
  }
}
