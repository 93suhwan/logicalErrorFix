#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const char nl = '\n';
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    if (s[0] == s.back())
      cout << s << nl;
    else {
      s[(int)s.length() - 1] = s[0];
      cout << s << nl;
    }
  }
  return 0;
}
