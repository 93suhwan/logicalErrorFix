#include <bits/stdc++.h>
using namespace std;
int check(string s) {
  int c = 0;
  for (int i = 1; i < s.length(); i++) {
    if (s[i - 1] == s[i]) {
      c++;
    }
  }
  return c;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s, s1, s2;
    cin >> s;
    int j = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] != '?') {
        if (s[i] == 'B') {
          int k = i - 1, f = 1;
          while (k >= j) {
            if (f == 1) {
              s[k] = 'R';
              f = 0;
            } else {
              s[k] = 'B';
              f = 1;
            }
            k--;
          }
          j = i + 1;
        } else {
          int k = i - 1, f = 1;
          while (k >= j) {
            if (f == 1) {
              s[k] = 'B';
              f = 0;
            } else {
              s[k] = 'R';
              f = 1;
            }
            k--;
          }
          j = i + 1;
        }
      }
    }
    if (j < s.length()) {
      if (s[j - 1] == 'B') {
        int k = 1;
        while (j < s.length()) {
          if (k == 1) {
            s[j] = 'R';
            k = 0;
          } else {
            s[j] = 'B';
            k = 1;
          }
          j++;
        }
      } else {
        int k = 1;
        while (j < s.length()) {
          if (k == 1) {
            s[j] = 'B';
            k = 0;
          } else {
            s[j] = 'R';
            k = 1;
          }
          j++;
        }
      }
    }
    cout << s << endl;
  }
  return 0;
}
