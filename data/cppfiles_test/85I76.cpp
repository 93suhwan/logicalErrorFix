#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    ll one = 0;
    ll zer = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '0') {
        zer++;
      } else {
        one++;
      }
    }
    if (zer == 0) {
      int ans = 0;
      cout << ans << "\n";
      continue;
    }
    if (one == 0) {
      int ans = 1;
      cout << ans << "\n";
      continue;
    }
    if (zer == 1) {
      cout << 1 << "\n";
      continue;
    }
    if (one != s.size() && zer != s.size()) {
      int ans = 2;
      cout << ans << "\n";
      continue;
    }
  }
  return 0;
}
