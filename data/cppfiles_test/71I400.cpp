#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool check(string a, string b) { return a >= b; }
void solve() {
  ll n, k;
  cin >> n >> k;
  string s = to_string(n);
  int len = s.length();
  set<char> st;
  for (auto c : s) {
    st.insert(c);
  }
  if (st.size() <= k) {
    cout << s << "\n";
    return;
  }
  st.clear();
  string ans = "";
  string t;
  for (int i = 0; i < len; i++) ans += s[0] + 1;
  if (k == 1) {
    for (int i = 0; i < len; i++) {
      t += s[0];
    }
    if (check(t, s)) ans = min(ans, t);
    cout << ans << "\n";
    return;
  }
  for (char p = '0'; p <= '9'; p++) {
    for (int i = 0; i < len; i++) t += p;
    for (char c = '1'; c <= '9'; c++) {
      for (int i = 1; i < len; i++) {
        t[i] = c;
        t[0] = c;
        if (check(t, s)) ans = min(ans, t);
        t[i] = p;
        t[0] = p;
      }
    }
    if (p != '0') {
      for (char c = '1'; c <= '9'; c++) {
        for (int i = 1; i < len; i++) {
          t[i] = c;
          if (check(t, s)) ans = min(ans, t);
          t[i] = p;
        }
      }
    }
    t = "";
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
