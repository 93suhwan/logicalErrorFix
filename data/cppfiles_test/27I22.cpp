#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 1e9 + 7;
constexpr long double EPS = 0.0 + 1e-6;
void YES() {
  cout << "YES"
       << "\n";
}
void NO() {
  cout << "NO"
       << "\n";
}
void solve() {
  string s;
  cin >> s;
  string t;
  cin >> t;
  if (t.size() >= s.size() and s != t) return NO();
  unordered_set<char> st;
  for (long long i = 0; i < s.size(); ++i) {
    st.insert(s[i]);
  }
  for (long long i = 0; i < t.size(); ++i) {
    if (st.count(t[i]) == 0) return NO();
  }
  string res;
  for (long long i = 0, j = 0; i < s.size(); ++i) {
    if (s[i] == t[j]) {
      if (s[i] == t[j] and res.size() != 0 and res.back() != t[j - 1]) {
        res.resize(max((long long)0, (long long)res.size() - 1));
      } else
        res += s[i], j++;
    } else {
      if (res.size() != 0 and res.back() == s[i]) {
      } else if (res.size() != 0 and res.back() == t[j - 1]) {
        res += s[i];
      } else {
        res.resize(max((long long)0, (long long)res.size() - 1));
      }
    }
  }
  if (res == t) return YES();
  return NO();
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
