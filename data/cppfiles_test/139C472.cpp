#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s.length() % 2 != 0) {
      cout << "NO" << endl;
    } else {
      string s1 = "";
      string s2 = "";
      for (int i = 0; i <= (s.length() / 2) - 1; i++) {
        s1 = s1 + s[i];
      }
      for (int i = s.length() / 2; i <= s.length() - 1; i++) {
        s2 = s2 + s[i];
      }
      int m = 1;
      for (int i = 0; i <= (s.length() / 2) - 1; i++) {
        if (s1[i] != s2[i]) {
          m = 0;
        }
      }
      if (m == 0) {
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
      }
    }
  }
  return 0;
}
