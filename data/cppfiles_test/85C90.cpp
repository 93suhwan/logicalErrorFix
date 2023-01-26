#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int zeros = count(s.begin(), s.end(), '0');
    if (zeros == s.size()) {
      cout << 1 << endl;
      continue;
    }
    int ones = count(s.begin(), s.end(), '1');
    if (ones == s.size()) {
      cout << 0 << endl;
      continue;
    }
    int f = s.find('0');
    int l = s.rfind('0');
    bool p = true;
    for (int i = f; i <= l; i++) {
      if (s[i] == '1') {
        p = false;
        break;
      }
    }
    if (p == true)
      cout << 1 << endl;
    else
      cout << 2 << endl;
  }
}
