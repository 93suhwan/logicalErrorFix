#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    string s;
    cin >> s;
    if (((int)(s).size()) % 2)
      cout << "NO\n";
    else {
      int j = ((int)(s).size()) / 2;
      bool ok = true;
      for (int i = 0; i < ((int)(s).size()) / 2; i++) {
        if (s[i] != s[j++]) ok = false;
      }
      if (ok)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}
