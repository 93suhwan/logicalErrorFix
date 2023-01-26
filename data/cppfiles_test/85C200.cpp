#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int a = 0, b = 0, tn;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '0')
        a++;
      else
        b++;
    }
    if (a == s.size()) {
      cout << 1 << endl;
      goto l;
    }
    if (b == s.size()) {
      cout << 0 << endl;
      goto l;
    }
    tn = a;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '0')
        tn--;
      else {
        tn = a;
      }
      if (tn == 0) {
        cout << 1 << endl;
        goto l;
      }
    }
    cout << 2 << endl;
  l:;
  }
}
