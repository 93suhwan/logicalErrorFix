#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  map<char, int> mp;
  while (t--) {
    string a;
    cin >> a;
    for (int i = 0; i < a.size(); i++) mp[a[i]] = i;
    string s;
    cin >> s;
    long long ans = 0;
    for (int i = 1; i < s.size(); i++) {
      ans += abs(mp[s[i]] - mp[s[i - 1]]);
    }
    cout << ans << "\n";
  }
  return 0;
}
