#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int l = s.length();
    if (s[0] == s[l - 1])
      cout << s << endl;
    else {
      if (s[0] == 'a') {
        cout << 'b';
        for (int i = 1; i < l; i++) cout << s[i];
      } else {
        cout << 'a';
        for (int i = 0; i < l; i++) cout << s[i];
      }
      cout << endl;
    }
  }
}
