#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  set<char> st;
  long long n = s.size(), len = 0;
  string ans = "";
  vector<long long> hash(26, 0);
  vector<long long> vec(s.size());
  for (long long i = n - 1; i >= 0; --i) {
    st.insert(s[i]);
    ++hash[s[i] - 'a'];
    vec[i] = st.size();
  }
  ans += s[n - 1];
  for (long long i = n - 1; i > 0; --i) {
    if (vec[i] < vec[i - 1]) {
      ans.push_back(s[i - 1]);
    }
  }
  reverse(ans.begin(), ans.end());
  for (long long i = 0; i < ans.size(); ++i) {
    if (hash[ans[i] - 'a'] % (i + 1) != 0) {
      cout << "-1\n";
      return;
    }
    long long temp = (hash[ans[i] - 'a'] / (i + 1));
    len += temp;
  }
  string t = "";
  for (long long i = 0; i < len; ++i) t.push_back(s[i]);
  string temp = t;
  for (auto &x : ans) {
    string t_;
    for (auto &y : temp) {
      if (y != x) {
        t_.push_back(y);
        t.push_back(y);
      }
    }
    temp = t_;
  }
  if (t != s) {
    cout << "-1\n";
    return;
  }
  for (long long i = 0; i < len; ++i) cout << s[i];
  cout << " ";
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
