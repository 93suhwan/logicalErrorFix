#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int cases = 1;
  cin >> cases;
  while (cases--) {
    int a = 0, b = 0;
    string s;
    cin >> s;
    char f = s[0];
    for (int i = 1; i < s.length(); i++) {
      if (s[i] != f) {
        if (f == 'a') {
          a++;
        } else {
          b++;
        }
      }
      f = s[i];
    }
    if (a > b) {
      for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == 'b') {
          s[i] = 'a';
          break;
        }
      }
    } else if (b > a) {
      for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == 'a') {
          s[i] = 'b';
          break;
        }
      }
    }
    cout << s << endl;
  }
  return 0;
}
