#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    string s;
    cin >> s;
    int one = 0, a2 = 0, zer = 0;
    string a1;
    for (int i = 0; i < s.size() - 1; ++i) {
      if (s[i] == '1' && s[i + 1] == '0') {
        a1 = "10";
        a2 += 1;
      }
      if (s[i] == '0' && s[i + 1] == '1') {
        a1 = "01";
        a2 += 1;
      }
      if (s[i] == '1') {
        one += 1;
      } else {
        zer += 1;
      }
    }
    if (s[s.size() - 1] == '1') {
      one += 1;
    } else {
      zer += 1;
    }
    if (one == s.size()) {
      cout << 0 << endl;
    } else if (zer == s.size()) {
      cout << 1 << endl;
    } else if (a2 == 1) {
      cout << 1 << endl;
    } else if (a2 == 2 && a1 == "01") {
      cout << 1 << endl;
    } else {
      cout << 2 << endl;
    }
  }
}
