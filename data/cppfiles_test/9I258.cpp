#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n[26];
    for (int i = 0; i < (int)(26); ++i) {
      n[i] = 0;
    }
    for (int i = 0; i < (int)(s.size()); ++i) {
      ++n[s[i] - 'a'];
    }
    int ans = s.size() / 2;
    int c = 0;
    for (int i = 0; i < (int)(26); ++i) {
      if (n[i] == 3) {
        ++c;
      }
    }
    if (c != 0 && s.size() % 2 == 1) {
      ++ans;
    } else if (c > 1 && s.size() % 2 == 0) {
      ++ans;
    }
    for (int i = 0; i < (int)(26); ++i) {
      if (n[i] >= 3) {
        ans -= n[i] / 3;
      }
    }
    cout << ans << "\n";
  }
}
