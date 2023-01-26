#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int n = (int)s.size();
  vector<int> c(26);
  for (int i = 0; i < n; i++) {
    c[(int)s[i] - 'a']++;
  }
  int ans = 0;
  for (int j = 0; j < 26; j++) {
    if (c[j] >= 2) {
      ans++;
    }
  }
  int c1 = 0;
  for (int j = 0; j < 26; j++) {
    if (c[j] == 1) {
      c1++;
    }
  }
  ans += c1 / 2;
  cout << ans << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
