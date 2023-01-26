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
    if (a == b) {
      cout << s << endl;
    } else if (a > b && s[s.length() - 1] == 'b') {
      int x = -1;
      for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'a') {
          x = i;
        }
      }
      int counter = 0;
      for (int i = x; i >= 0; i--) {
        if (s[i] == 'a') {
          counter++;
        }
      }
      x++;
      int len = s.length() - x;
      if (len <= counter) {
        for (int i = x; i < s.length(); i++) {
          s[i] = 'a';
        }
      } else {
        for (int i = x - 1; i >= 0; i--) {
          if (s[i] == 'a') {
            s[i] = 'b';
          } else {
            break;
          }
        }
      }
      cout << s << endl;
    } else if (a < b && s[s.length() - 1] == 'a') {
      int x = -1;
      for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'b') {
          x = i;
        }
      }
      int counter = 0;
      for (int i = x; i >= 0; i--) {
        if (s[i] == 'b') {
          counter++;
        } else {
          break;
        }
      }
      x++;
      int len = s.length() - x;
      if (len <= counter) {
        for (int i = x; i < s.length(); i++) {
          s[i] = 'b';
        }
      } else {
        for (int i = x - 1; i >= 0; i--) {
          if (s[i] == 'b') {
            s[i] = 'a';
          } else {
            break;
          }
        }
      }
      cout << s << endl;
    }
  }
  return 0;
}
