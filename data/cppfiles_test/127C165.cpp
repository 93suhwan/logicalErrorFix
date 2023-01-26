#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int n, m[107], c, t;
int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> s1 >> s2;
    n = s1.size();
    for (c = 0; c < n; c++) {
      m[s1[c] - 'a']++;
    }
    if ((m[0] == 0 || m[1] == 0 || m[2] == 0) || (s2 != "abc")) {
      for (c = 0; c <= 'z' - 'a'; c++) {
        while (m[c] > 0) {
          cout << char('a' + c);
          m[c]--;
        }
      }
      cout << endl;
    } else {
      while (m[0] > 0) {
        cout << 'a';
        m[0]--;
      }
      while (m[2] > 0) {
        cout << 'c';
        m[2]--;
      }
      for (c = 1; c <= 'z' - 'a'; c++) {
        while (m[c] > 0) {
          cout << char('a' + c);
          m[c]--;
        }
      }
      cout << endl;
    }
  }
  return 0;
}
