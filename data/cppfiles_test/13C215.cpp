#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int resa = 0, resb = 0, resc = 0;
    for (auto &it : s) {
      if (it == 'A')
        resa++;
      else if (it == 'B')
        resb++;
      else
        resc++;
    }
    if (resb == resa + resc)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
