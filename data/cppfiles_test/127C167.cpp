#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s, t, s1 = "abc";
  cin >> s >> t;
  set<char> st((s).begin(), (s).end());
  sort((s).begin(), (s).end());
  if (t != s1 || st.count('a') == 0 || st.count('b') == 0 || st.count('c') == 0)
    cout << s << "\n";
  else {
    string ans;
    long long c0 = 0, f = 0;
    for (long long i = 0; i < (long long)(s.size()); i += 1) {
      if (s[i] == 'b')
        c0++;
      else if (s[i] > 'c' && f == 0) {
        for (long long j = 0; j < c0; j += 1) ans.push_back('b');
        ans.push_back(s[i]);
        f = 1;
        c0 = 0;
      } else
        ans.push_back(s[i]);
    }
    for (long long i = 0; i < c0; i += 1) ans.push_back('b');
    cout << ans << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
