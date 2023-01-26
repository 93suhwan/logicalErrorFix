#include <bits/stdc++.h>
using namespace std;
void change(char s[], int n) {
  for (int i = 0; i < n - 1; i++) {
    if (s[i] != '?' and s[i + 1] == '?') {
      if (s[i] == 'R')
        s[i + 1] = 'B';
      else
        s[i + 1] = 'R';
    }
  }
}
void changef(char s[], int n) {
  for (int i = 0; i < n - 1; i++) {
    if (s[i + 1] != '?' and s[i] == '?') {
      if (s[i + 1] == 'R')
        s[i] = 'B';
      else
        s[i] = 'R';
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    char s[n];
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    int c = 0;
    for (auto i : s) {
      if (i == '?') c++;
    }
    char e = 'R';
    if (c == 1 and n == 1)
      cout << "R" << endl;
    else if (c == n) {
      for (int i = 0; i < n; i++) {
        cout << e;
        if (e == 'R')
          e = 'B';
        else
          e = 'R';
      }
      cout << endl;
    } else {
      for (int i = 0; i < c; i++) {
        change(s, n);
      }
      for (auto i : s) {
        if (i == '?') c++;
      }
      for (int i = 0; i < c; i++) {
        changef(s, n);
      }
      for (int i = 0; i < n; i++) {
        cout << s[i];
      }
      cout << endl;
    }
  }
  return 0;
}
