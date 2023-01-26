#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int a = 0, b = 0, x = 0, y = 0, c = 0;
    int n = s.length();
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        if (s[i] == '1') a++;
        if (s[i] == '?') b++;
      }
      if (i % 2 != 0) {
        if (s[i] == '1') x++;
        if (s[i] == '?') y++;
      }
      if (((x + y) > ((ceil((9 - i) / 2)) + a)) or
          ((a + b) > ((ceil((9 - i) / 2.0)) + x))) {
        cout << i + 1 << "\n";
        c++;
        break;
      }
    }
    if (c == 0) cout << n << "\n";
  }
}
