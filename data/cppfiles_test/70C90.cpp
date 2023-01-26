#include <bits/stdc++.h>
using namespace std;
void solve() {
  string t;
  cin >> t;
  long long n = t.size(), len = 0;
  vector<long long> hash(26, 0);
  string ans;
  for (long long i = n - 1; i >= 0; --i) {
    if (!hash[t[i] - 'a']) ans.push_back(t[i]);
    ++hash[t[i] - 'a'];
  }
  long long m = ans.size();
  for (long long i = 0; i < m; ++i) {
    if (hash[ans[i] - 'a'] % (m - i) != 0) {
      cout << "-1\n";
      return;
    }
    len += hash[ans[i] - 'a'] / (m - i);
  }
  reverse(ans.begin(), ans.end());
  string s;
  for (long long i = 0; i < len; ++i) s.push_back(t[i]);
  string temp = s;
  for (auto &x : ans) {
    string temp_;
    for (auto &y : temp) {
      if (y != x) {
        s.push_back(y);
        temp_.push_back(y);
      }
    }
    temp = temp_;
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
