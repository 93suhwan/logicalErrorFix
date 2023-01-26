#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int rest = 0, no1 = 0, alt[26] = {0};
    for (int i = 0; i < s.size(); i++) {
      alt[s[i] - 'a'] += 1;
    }
    for (int i = 0; i < 26; i++) {
      if (alt[i] != 0) {
        if (alt[i] == 1)
          no1++;
        else
          rest++;
      }
    }
    cout << rest + no1 / 2 << "\n";
  }
}
