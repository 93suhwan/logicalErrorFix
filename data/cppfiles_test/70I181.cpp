#include <bits/stdc++.h>
using namespace std;
void solve() {
  string t;
  cin >> t;
  long long n = t.size(), len = 0;
  set<char> st;
  vector<long long> vec(n, 0);
  vector<long long> hash(26, 0), s_hash(26, 0);
  string ans;
  for (long long i = n - 1; i >= 0; --i) {
    st.insert(t[i]);
    vec[i] = st.size();
    ++hash[t[i] - 'a'];
  }
  for (long long i = n - 1; i > 0; --i) {
    if (vec[i - 1] > vec[i]) ans += t[i - 1];
  }
  reverse(ans.begin(), ans.end());
  ans += t[n - 1];
  for (long long i = 0; i < ans.size(); ++i) {
    if (hash[ans[i] - 'a'] % (i + 1) != 0) {
      cout << "-1\n";
      return;
    }
    len += hash[ans[i] - 'a'] / (i + 1);
  }
  string s;
  while (s.size() < t.size()) {
    for (long long j = 0; j < len; ++j) {
      if (hash[t[j] - 'a'] > 0) {
        s.push_back(t[j]);
        --hash[t[j] - 'a'];
      }
    }
  }
  if (s != t) {
    cout << "-1\n";
    return;
  }
  for (long long j = 0; j < len; ++j) cout << t[j];
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
