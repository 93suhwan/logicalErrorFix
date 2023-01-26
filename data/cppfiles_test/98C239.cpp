#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    unordered_map<int, int> mp;
    for (int i = 0; i < s.size(); i++) {
      mp[s[i]] = i;
    }
    string word;
    cin >> word;
    int ans = 0;
    for (int i = 1; i < word.size(); i++) {
      int dif = abs(mp[word[i]] - mp[word[i - 1]]);
      ans += dif;
    }
    cout << ans << endl;
  }
  return 0;
}
