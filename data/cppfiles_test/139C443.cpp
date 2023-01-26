#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  if (((int)s.size()) % 2 != 0)
    cout << "No\n";
  else {
    int p = ((int)s.size()) / 2;
    string ans = "Yes";
    for (int i = 0; i < p; i++) {
      if (s[i] != s[p + i]) {
        ans = "No";
        break;
      }
    }
    cout << ans << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
