#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tt = 1;
  cin >> tt;
  while (tt--) {
    string t, s, ans;
    bool f = 0;
    cin >> t;
    long long n = t.size();
    vector<long long> a(26), b(26), c(26);
    for (long long i = n - 1; i >= 0; --i) {
      if (a[t[i] - 'a'] == 0) s = t[i] + s;
      a[t[i] - 'a']++;
    }
    long long sz = 0;
    for (long long i = 0; i < s.size(); ++i) {
      if (a[s[i] - 'a'] % (i + 1)) {
        f = 1;
        break;
      }
      b[s[i] - 'a'] = a[s[i] - 'a'] / (i + 1);
      sz += b[s[i] - 'a'];
    }
    if (!f) {
      vector<string> st(sz);
      long long id = 0;
      for (long long i = 0; i < s.size(); ++i) {
        st[i] = string(t, id, sz);
        id += sz, sz -= b[s[i] - 'a'];
      }
      ans = st[0];
      for (long long i = 0; i < st.size() - 1; ++i) {
        string cnt;
        for (long long j = 0; j < st[i].size(); ++j) {
          if (st[i][j] != s[i]) cnt = cnt + st[i][j];
        }
        if (cnt != st[i + 1]) {
          f = 1;
          break;
        }
      }
    }
    if (f)
      cout << -1 << '\n';
    else
      cout << ans << '\n';
  }
  return 0;
}
