#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int cntab = 0, cntba = 0;
    char cidx;
    int par = 0;
    for (int i = 0; i < s.length() - 1; i++) {
      if (s[i] == 'a' && s[i + 1] == 'b' && par == 0) {
        par = 1;
        cidx = 'b';
        cntab++;
      } else if (s[i] == 'b' && s[i + 1] == 'a' && par == 0) {
        par = 1;
        cidx = 'a';
        cntba++;
      } else if (s[i] == 'a' && s[i + 1] == 'b') {
        cntab++;
      } else if (s[i] == 'b' && s[i + 1] == 'a') {
        cntba++;
      }
    }
    if (cntab == cntba)
      cout << s << endl;
    else {
      s[0] = cidx;
      cout << s << endl;
    }
  }
  return 0;
}
