#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, M = 27, mod = 1e9 + 7, OO = 0x3f3f3f3f, sqr = 320;
const long long LOO = 0x3f3f3f3f3f3f3f3f;
const long double eps = 1e-8;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    string k, s;
    set<char> st;
    cin >> k >> s;
    map<char, int> mp;
    for (int i = 0; i < 26; i++) mp[k[i]] = i + 1;
    for (int i = 0; i < s.size(); i++) st.insert(s[i]);
    if (st.size() == 1)
      cout << 0 << '\n';
    else {
      int ans = 0;
      for (int i = 1; i < s.size(); i++) ans += abs(mp[s[i]] - mp[s[i - 1]]);
      cout << ans << '\n';
    }
  }
  return 0;
}
