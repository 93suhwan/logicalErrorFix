#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    unordered_map<char, int> mp(s.size());
    for (long long i = 0; i < s.size(); i++) {
      mp[s[i]] = i + 1;
    }
    string ss;
    cin >> ss;
    long long ans = 0;
    for (long long i = 1; i < ss.size(); i++) {
      ans += abs(mp[ss[i]] - mp[ss[i - 1]]);
    }
    cout << ans << endl;
  }
  return 0;
}
