#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  string s;
  cin >> n;
  cin >> s;
  string b = s;
  int ans = s.length();
  sort(s.begin(), s.end());
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == b[i]) {
      ans--;
    }
  }
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
