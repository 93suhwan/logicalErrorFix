#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  int j = 1;
  while (j <= s1.size() - 1) {
    if (s1[j] == '1' && s2[j] == '1') {
      cout << "NO" << endl;
      return;
    } else {
      j++;
      continue;
    }
  }
  cout << "YES" << endl;
  return;
}
int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
