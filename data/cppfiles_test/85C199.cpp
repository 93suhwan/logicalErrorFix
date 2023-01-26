#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    s = s[0] + s;
    bool a = 0, b = 0, c = 0;
    for (int i = 1; i < s.size(); i++) {
      if (s[i - 1] == '0' && s[i] == '1')
        a = 1;
      else if (a && s[i - 1] == '1' && s[i] == '0')
        b = 1;
      else if (s[i] == '0')
        c = 1;
    }
    if (a && b)
      cout << 2 << endl;
    else if (a || b || c)
      cout << 1 << endl;
    else
      cout << 0 << endl;
  }
  return 0;
}
