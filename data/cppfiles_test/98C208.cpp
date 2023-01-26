#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 9, M = 1e5 + 9, mod = 1e9 + 7, inf = 0x3f3f3f;
int32_t main() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    map<int, int> mp;
    string s, f;
    int ans = 0;
    cin >> s >> f;
    for (int i = 0; i < s.size(); i++) {
      mp[s[i] - 'a'] = i;
    }
    for (int i = 1; i < f.size(); i++) {
      ans += abs(mp[f[i] - 'a'] - mp[f[i - 1] - 'a']);
    }
    cout << ans << '\n';
  }
}
