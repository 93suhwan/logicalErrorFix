#include <bits/stdc++.h>
using namespace std;
int a, b, c, x1, x2, i, j, t;
string s;
int pp(int a) {
  if (a == 0)
    return 1;
  else {
    int b = 1;
    for (i = 0; i < a; i++) b *= 10;
    return b;
  }
}
int main() {
  cin >> s;
  if (s.size() > 2) {
    if (s[0] == '_')
      a = 9;
    else if (s[0] == 'X') {
      a = 9;
      x1 = 1;
    } else if (s[0] == '0')
      a = 0;
    else
      a = 1;
    for (i = 1; i < s.size() - 2; i++) {
      if (s[i] == '_')
        t++;
      else if (s[i] == 'X')
        x2 = 1;
    }
    if (s[s.size() - 2] == 'X' && s[s.size() - 1] == 'X') {
      if (x1 == 0)
        cout << a * pp(t) * 1;
      else
        cout << 0;
    } else if (s[s.size() - 2] == 'X' && s[s.size() - 1] == '_') {
      if (x1 == 0)
        cout << a * pp(t) * 4;
      else
        cout << 1 * pp(t) * 3;
    } else if (s[s.size() - 2] == '_' && s[s.size() - 1] == 'X') {
      if (x1 == 0)
        cout << a * pp(t) * 4;
      else
        cout << 1 * pp(t) * 2;
    } else if (s[s.size() - 2] == '_' && s[s.size() - 1] == '_') {
      if (x1 == 0) {
        if (x2 == 0)
          cout << a * pp(t) * 4;
        else
          cout << a * 10 * pp(t) * 4;
      } else
        cout << a * pp(t) * 4;
    } else if (s[s.size() - 2] == '0' && s[s.size() - 1] == '0') {
      if (x1 == 0 && x2 == 0)
        cout << a * pp(t);
      else if (x1 == 0 && x2 == 1)
        cout << a * 10 * pp(t);
      else if (x1 == 1 && x2 == 0)
        cout << a * pp(t);
      else if (x1 == 1 && x2 == 1)
        cout << a * pp(t);
    } else if (s[s.size() - 2] == '2' && s[s.size() - 1] == '5') {
      if (x1 == 0 && x2 == 0)
        cout << a * pp(t);
      else if (x1 == 0 && x2 == 1)
        cout << a * 10 * pp(t);
      else if (x1 == 1 && x2 == 0)
        cout << a * pp(t);
      else if (x1 == 1 && x2 == 1)
        cout << a * pp(t);
    } else if (s[s.size() - 2] == '5' && s[s.size() - 1] == '0') {
      if (x1 == 0 && x2 == 0)
        cout << a * pp(t);
      else if (x1 == 0 && x2 == 1)
        cout << a * 10 * pp(t);
      else if (x1 == 1 && x2 == 0)
        cout << a * pp(t);
      else if (x1 == 1 && x2 == 1)
        cout << a * pp(t);
    } else if (s[s.size() - 2] == '7' && s[s.size() - 1] == '5') {
      if (x1 == 0 && x2 == 0)
        cout << a * pp(t);
      else if (x1 == 0 && x2 == 1)
        cout << a * 10 * pp(t);
      else if (x1 == 1 && x2 == 0)
        cout << a * pp(t);
      else if (x1 == 1 && x2 == 1)
        cout << a * pp(t);
    } else if (s[s.size() - 2] == 'X') {
      if (s[s.size() - 1] == '0') {
        if (x1 == 0)
          cout << a * pp(t) * 2;
        else
          cout << pp(t);
      } else if (s[s.size() - 1] == '5') {
        if (x1 == 0)
          cout << pp(t) * 2;
        else
          cout << a * pp(t) * 2;
      } else
        cout << 0;
    } else if (s[s.size() - 2] == '_') {
      if (s[s.size() - 1] == '0') {
        if (x2 == 1 && x1 == 0)
          cout << a * 10 * pp(t) * 2;
        else
          cout << a * pp(t) * 2;
      } else if (s[s.size() - 1] == '5') {
        if (x2 == 1 && x1 == 0)
          cout << a * 10 * pp(t) * 2;
        else
          cout << a * pp(t) * 2;
      } else
        cout << 0;
    } else if (s[s.size() - 1] == 'X') {
      if (s[s.size() - 2] == '0') {
        if (x1 == 0)
          cout << a * pp(t);
        else
          cout << 0;
      } else if (s[s.size() - 2] == '5') {
        if (x1 == 0)
          cout << a * pp(t);
        else
          cout << 0;
      } else
        cout << 0;
    } else if (s[s.size() - 1] == '_') {
      if (s[s.size() - 2] == '0') {
        if (x2 == 1 && x1 == 0)
          cout << a * 10 * pp(t) * 1;
        else
          cout << a * pp(t) * 1;
      } else if (s[s.size() - 2] == '2') {
        if (x2 == 1 && x1 == 0)
          cout << a * 10 * pp(t) * 1;
        else
          cout << a * pp(t) * 1;
      } else if (s[s.size() - 2] == '5') {
        if (x2 == 1 && x1 == 0)
          cout << a * 10 * pp(t) * 1;
        else
          cout << a * pp(t) * 1;
      } else if (s[s.size() - 2] == '7') {
        if (x2 == 1 && x1 == 0)
          cout << a * 10 * pp(t) * 1;
        else
          cout << a * pp(t) * 1;
      } else
        cout << 0;
    } else
      cout << 0;
  } else if (s.size() == 1 && s[0] == '0')
    cout << 1;
  else if (s.size() == 1)
    cout << 0;
  else if (s.size() == 2) {
    if (s[s.size() - 2] == 'X' && s[s.size() - 1] == 'X')
      cout << 0;
    else if (s[s.size() - 2] == 'X' && s[s.size() - 1] == '_')
      cout << 3;
    else if (s[s.size() - 2] == '_' && s[s.size() - 1] == 'X')
      cout << 3;
    else if (s[s.size() - 2] == '_' && s[s.size() - 1] == '_')
      cout << 3;
    else if (s[s.size() - 2] == '0' && s[s.size() - 1] == '0')
      cout << 0;
    else if (s[s.size() - 2] == '2' && s[s.size() - 1] == '5')
      cout << 1;
    else if (s[s.size() - 2] == '5' && s[s.size() - 1] == '0')
      cout << 1;
    else if (s[s.size() - 2] == '7' && s[s.size() - 1] == '5')
      cout << 1;
    else if (s[s.size() - 2] == '2' && s[s.size() - 1] == 'X')
      cout << 1;
    else if (s[s.size() - 2] == '5' && s[s.size() - 1] == 'X')
      cout << 1;
    else if (s[s.size() - 2] == '7' && s[s.size() - 1] == 'X')
      cout << 1;
    else if (s[s.size() - 2] == 'X' && s[s.size() - 1] == '0')
      cout << 1;
    else if (s[s.size() - 2] == 'X' && s[s.size() - 1] == '5')
      cout << 2;
    else if (s[s.size() - 2] == '2' && s[s.size() - 1] == '_')
      cout << 1;
    else if (s[s.size() - 2] == '5' && s[s.size() - 1] == '_')
      cout << 1;
    else if (s[s.size() - 2] == '7' && s[s.size() - 1] == '_')
      cout << 1;
    else if (s[s.size() - 2] == '_' && s[s.size() - 1] == '0')
      cout << 1;
    else if (s[s.size() - 2] == '_' && s[s.size() - 1] == '5')
      cout << 2;
    else
      cout << 0;
  }
}
