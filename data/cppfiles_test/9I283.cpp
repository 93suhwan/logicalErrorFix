#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int by2 = 0, notby2 = 0, alt[26] = {0};
    for (int i = 0; i < s.size(); i++) {
      alt[s[i] - 'a'] += 1;
    }
    for (int i = 0; i < 26; i++) {
      if (alt[i] != 0) {
        if (alt[i] % 2 == 0)
          by2++;
        else
          notby2 += alt[i];
      }
    }
    cout << by2 + notby2 / 2 << "\n";
  }
}
