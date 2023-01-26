#include <bits/stdc++.h>
using namespace std;
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int T = 1;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int ca0 = 0;
    int ca1 = 0;
    int cau = 0;
    int cb0 = 0;
    int cb1 = 0;
    int cbu = 0;
    int ra = 5;
    int rb = 5;
    int sol = 9;
    for (int i = 0; i < 10; i++) {
      if (i % 2 == 0 && s[i] == '0') ca0++;
      if (i % 2 == 0 && s[i] == '1') ca1++;
      if (i % 2 == 0 && s[i] == '?') cau++;
      if (i % 2 == 1 && s[i] == '0') cb0++;
      if (i % 2 == 1 && s[i] == '1') cb1++;
      if (i % 2 == 1 && s[i] == '?') cbu++;
      if (ca1 + cau >= cb1 + rb || cb1 + cbu >= ca1 + ra) {
        sol = i + 1;
        break;
      }
      ra -= i % 2 == 0;
      rb -= i % 2 == 1;
    }
    cout << min(sol + 1, 10) << "\n";
  }
}
