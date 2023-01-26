#include <bits/stdc++.h>
using namespace std;
int a, b, c, i, j, n, m, k1, k2, k3, k4, x;
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
  if (s.size() == 1 && s[0] != '0')
    cout << 0;
  else if (s.size() == 1 && s[0] == '0')
    cout << 1;
  else {
    for (i = 0; i < s.size() - 2; i++) {
      if (s[i] == '_' && i > 0)
        k1 += 1;
      else if (s[i] == '_' && i == 0)
        k2 = 1;
    }
    for (i = 0; i < s.size() - 2; i++) {
      if (s[i] == 'X' && i > 0)
        k3 = 1;
      else if (s[i] == 'X' && i == 0)
        k4 = 1;
    }
    if (s[s.size() - 2] == 'X' && s[s.size() - 1] == 'X') {
      if (k4 == 1) {
        cout << 0;
      } else if (k2 == 1) {
        cout << 9 * pp(k1 - 1);
      } else {
        if (s[0] == '0')
          cout << 0;
        else {
          cout << pp(k1);
        }
      }
    } else if (s[s.size() - 2] == '_' && s[s.size() - 1] == 'X') {
      if (k4 == 1) {
        cout << pp(k1 - 1) * 2;
      } else if (k2 == 1 && s.size() > 2) {
        cout << 9 * 4 * pp(k1 - 1);
      } else if (k2 == 1 && s.size() == 2) {
        cout << 4;
      } else {
        if (s[0] == '0')
          cout << 0;
        else {
          cout << 4 * pp(k1);
        }
      }
    } else if (s[s.size() - 2] == 'X' && s[s.size() - 1] == '_') {
      if (k4 == 1 && s.size() > 2) {
        cout << pp(k1) * 3;
      } else if (k4 == 1 && s.size() == 2) {
        cout << 3;
      } else if (k2 == 1) {
        cout << 9 * pp(k1 - 1) * 4;
      } else {
        if (s[0] == '0')
          cout << 0;
        else {
          cout << pp(k1) * 4;
        }
      }
    } else if (s[s.size() - 2] == '_' && s[s.size() - 1] == '_') {
      if (k4 == 1) {
        cout << 9 * pp(k1) * 4;
      } else if (k2 == 1 && s.size() > 2) {
        cout << 9 * pp(k1 - 1) * 4;
      } else if (k2 == 1 && s.size() == 2) {
        cout << 4;
      } else {
        if (s[0] == '0')
          cout << 0;
        else {
          if (k3 == 1)
            cout << pp(k1) * 10;
          else
            cout << pp(k1);
        }
      }
    } else if (s[s.size() - 2] == 'X') {
      if (k4 == 1 && s.size() > 2) {
        if (s[s.size() - 1] == '0')
          cout << pp(k1);
        else if (s[s.size() - 1] == '5')
          cout << 2 * pp(k1);
        else
          cout << 0;
      } else if (k4 == 1 && s.size() == 2) {
        if (s[s.size() - 1] == '0')
          cout << 1;
        else if (s[s.size() - 1] == '5')
          cout << 2;
        else
          cout << 0;
      } else if (k2 == 1) {
        if (s[s.size() - 1] == '0')
          cout << 9 * pp(k1 - 1) * 2;
        else if (s[s.size() - 1] == '5')
          cout << 9 * pp(k1 - 1) * 2;
        else
          cout << 0;
      } else {
        if (s[0] == '0')
          cout << 0;
        else {
          if (s[s.size() - 1] == '0')
            cout << pp(k1) * 2;
          else if (s[s.size() - 1] == '5')
            cout << pp(k1) * 2;
          else
            cout << 0;
        }
      }
    } else if (s[s.size() - 1] == 'X') {
      if (k4 == 1) {
        if (s[s.size() - 2] == '2')
          cout << pp(k1);
        else if (s[s.size() - 2] == '5')
          cout << 0;
        else if (s[s.size() - 2] == '7')
          cout << pp(k1);
        else if (s[s.size() - 2] == '0')
          cout << 0;
        else
          cout << 0;
      } else if (k2 == 1) {
        if (s[s.size() - 2] == '2')
          cout << 9 * pp(k1 - 1);
        else if (s[s.size() - 2] == '5')
          cout << 9 * pp(k1 - 1);
        else if (s[s.size() - 2] == '7')
          cout << 9 * pp(k1 - 1);
        else if (s[s.size() - 2] == '0')
          cout << 9 * pp(k1 - 1);
        else
          cout << 0;
      } else {
        if (s[0] == '0')
          cout << 0;
        else {
          if (s.size() > 2) {
            if (k1 > 0) {
              if (s[s.size() - 2] == '2')
                cout << pp(k1);
              else if (s[s.size() - 2] == '5')
                cout << pp(k1);
              else if (s[s.size() - 2] == '7')
                cout << pp(k1);
              else if (s[s.size() - 2] == '0')
                cout << pp(k1);
              else
                cout << 0;
            } else {
              if (s[s.size() - 2] == '2')
                cout << 1;
              else if (s[s.size() - 2] == '5')
                cout << 1;
              else if (s[s.size() - 2] == '7')
                cout << 1;
              else if (s[s.size() - 2] == '0')
                cout << 1;
              else
                cout << 0;
            }
          } else if (s.size() == 2) {
            if (s[s.size() - 2] == '2')
              cout << 1;
            else if (s[s.size() - 2] == '5')
              cout << 1;
            else if (s[s.size() - 2] == '7')
              cout << 1;
            else if (s[s.size() - 2] == '0')
              cout << 0;
            else
              cout << 0;
          }
        }
      }
    } else if (s[s.size() - 2] == '_') {
      if (k4 == 1) {
        if (s[s.size() - 1] == '0')
          cout << 9 * pp(k1) * 2;
        else if (s[s.size() - 1] == '5')
          cout << 9 * pp(k1) * 2;
        else
          cout << 0;
      } else if (k2 == 1 && s.size() > 2) {
        if (s[s.size() - 1] == '0')
          cout << 9 * pp(k1 - 1) * 2;
        else if (s[s.size() - 1] == '5')
          cout << 9 * pp(k1 - 1) * 2;
        else
          cout << 0;
      } else if (k2 == 1 && s.size() == 2) {
        if (s[s.size() - 1] == '0')
          cout << 1;
        else if (s[s.size() - 1] == '5')
          cout << 2;
        else
          cout << 0;
      } else {
        if (s[0] == '0')
          cout << 0;
        else {
          if (k3 == 1) {
            if (s[s.size() - 1] == '0')
              cout << 10 * pp(k1) * 2;
            else if (s[s.size() - 1] == '5')
              cout << 10 * pp(k1) * 2;
            else
              cout << 0;
          } else if (k3 == 0) {
            if (s[s.size() - 1] == '0')
              cout << pp(k1) * 2;
            else if (s[s.size() - 1] == '5')
              cout << pp(k1) * 2;
            else
              cout << 0;
          }
        }
      }
    } else if (s[s.size() - 1] == '_') {
      if (k4 == 1) {
        if (s[s.size() - 2] == '2')
          cout << 9 * pp(k1);
        else if (s[s.size() - 2] == '5')
          cout << 9 * pp(k1);
        else if (s[s.size() - 2] == '7')
          cout << 9 * pp(k1);
        else if (s[s.size() - 2] == '0')
          cout << 9 * pp(k1);
        else
          cout << 0;
      } else if (k2 == 1) {
        if (k3 == 1) {
          if (s[s.size() - 2] == '2')
            cout << 9 * 10 * pp(k1 - 1);
          else if (s[s.size() - 2] == '5')
            cout << 9 * 10 * pp(k1 - 1);
          else if (s[s.size() - 2] == '7')
            cout << 9 * 10 * pp(k1 - 1);
          else if (s[s.size() - 2] == '0')
            cout << 9 * 10 * pp(k1 - 1);
          else
            cout << 0;
        } else if (k3 == 0) {
          if (s[s.size() - 2] == '2')
            cout << 9 * pp(k1 - 1);
          else if (s[s.size() - 2] == '5')
            cout << 9 * pp(k1 - 1);
          else if (s[s.size() - 2] == '7')
            cout << 9 * pp(k1 - 1);
          else if (s[s.size() - 2] == '0')
            cout << 9 * pp(k1 - 1);
          else
            cout << 0;
        }
      } else {
        if (s[0] == '0')
          cout << 0;
        else {
          if (s.size() > 2) {
            if (k3 == 1) {
              if (s[s.size() - 2] == '2')
                cout << pp(k1) * 10;
              else if (s[s.size() - 2] == '5')
                cout << pp(k1) * 10;
              else if (s[s.size() - 2] == '7')
                cout << pp(k1) * 10;
              else if (s[s.size() - 2] == '0')
                cout << pp(k1) * 10;
              else
                cout << 0;
            } else if (k3 == 0) {
              if (s[s.size() - 2] == '2')
                cout << pp(k1);
              else if (s[s.size() - 2] == '5')
                cout << pp(k1);
              else if (s[s.size() - 2] == '7')
                cout << pp(k1);
              else if (s[s.size() - 2] == '0')
                cout << pp(k1);
              else
                cout << 0;
            }
          } else if (s.size() == 2) {
            if (s[s.size() - 2] == '2')
              cout << 1;
            else if (s[s.size() - 2] == '5')
              cout << 1;
            else if (s[s.size() - 2] == '7')
              cout << 1;
            else if (s[s.size() - 2] == '0')
              cout << 0;
            else
              cout << 0;
          }
        }
      }
    } else if (s[s.size() - 2] == '0' && s[s.size() - 1] == '0') {
      if (s.size() == 2)
        cout << 0;
      else {
        if (k4 == 1) {
          cout << 9 * pp(k1);
        } else if (k2 == 1) {
          if (k3 == 1) {
            cout << 9 * 10 * pp(k1 - 1);
          } else if (k3 == 0) {
            cout << 9 * pp(k1 - 1);
          }
        } else {
          if (s[0] == 0)
            cout << 0;
          else {
            if (k3 == 1) {
              cout << 10 * pp(k1);
            } else if (k3 == 0) {
              cout << 10 * pp(k1);
            }
          }
        }
      }
    } else if (s[s.size() - 2] == '2' && s[s.size() - 1] == '5') {
      if (s.size() == 2)
        cout << 1;
      else {
        if (k4 == 1) {
          cout << 9 * pp(k1);
        } else if (k2 == 1) {
          if (k3 == 1) {
            cout << 9 * 10 * pp(k1 - 1);
          } else if (k3 == 0) {
            cout << 9 * pp(k1 - 1);
          }
        } else {
          if (s[0] == 0)
            cout << 0;
          else {
            if (k3 == 1) {
              cout << 10 * pp(k1);
            } else if (k3 == 0) {
              cout << 10 * pp(k1);
            }
          }
        }
      }
    } else if (s[s.size() - 2] == '5' && s[s.size() - 1] == '0') {
      if (s.size() == 2)
        cout << 1;
      else {
        if (k4 == 1) {
          cout << 9 * pp(k1);
        } else if (k2 == 1) {
          if (k3 == 1) {
            cout << 9 * 10 * pp(k1 - 1);
          } else if (k3 == 0) {
            cout << 9 * pp(k1 - 1);
          }
        } else {
          if (s[0] == 0)
            cout << 0;
          else {
            if (k3 == 1) {
              cout << 10 * pp(k1);
            } else if (k3 == 0) {
              cout << 10 * pp(k1);
            }
          }
        }
      }
    } else if (s[s.size() - 2] == '7' && s[s.size() - 1] == '5') {
      if (s.size() == 2)
        cout << 1;
      else {
        if (k4 == 1) {
          cout << 9 * pp(k1);
        } else if (k2 == 1) {
          if (k3 == 1) {
            cout << 9 * 10 * pp(k1 - 1);
          } else if (k3 == 0) {
            cout << 9 * pp(k1 - 1);
          }
        } else {
          if (s[0] == 0)
            cout << 0;
          else {
            if (k3 == 1) {
              cout << 10 * pp(k1);
            } else if (k3 == 0) {
              cout << 10 * pp(k1);
            }
          }
        }
      }
    } else
      cout << 0;
  }
}
