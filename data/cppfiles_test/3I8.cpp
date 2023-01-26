#include <bits/stdc++.h>
using namespace std;
char a[15];
int main() {
  cin >> a;
  int len = strlen(a);
  if ((a[0] == '0' || a[0] == '_' || a[0] == 'X') && len == 1) {
    cout << "1" << endl;
    return 0;
  }
  if (a[0] == '0') {
    cout << "0" << endl;
    return 0;
  }
  if (len == 2) {
    if (a[len - 1] >= '0' && a[len - 1] <= '9' && a[len - 2] >= '0' &&
        a[len - 2] <= '9') {
      int k = (a[len - 2] - '0') * 10 + a[len - 1] - '0';
      if (k % 25 == 0) {
        cout << "1" << endl;
      }
      return 0;
    }
    if ((a[len - 1] == 'X' || a[len - 1] == '_') &&
        (a[len - 2] == 'X' || a[len - 2] == '_')) {
      if (a[len - 1] == a[len - 2] && a[len - 1] == 'X') {
        cout << "0" << endl;
      } else {
        cout << "3" << endl;
      }
    } else if (a[len - 1] == '0') {
      cout << "1" << endl;
    } else if (a[len - 1] == '5') {
      cout << "2" << endl;
    } else if (a[len - 2] == '7') {
      cout << "1" << endl;
    }
    return 0;
  }
  int c, b;
  c = 0;
  b = 0;
  for (int i = 0; i < len; i++) {
    if (a[i] == 'X') {
      c++;
    } else if (a[i] == '_') {
      b++;
    }
  }
  if (c != 0) {
    b++;
  }
  int ans = 0;
  if (a[len - 1] >= '0' && a[len - 1] <= '9' && a[len - 2] >= '0' &&
      a[len - 2] <= '9') {
    int k = (a[len - 2] - '0') * 10 + a[len - 1] - '0';
    if (k % 25 == 0) {
      if (k == 0) {
        if (a[0] != '_' && a[0] != 'X') {
          ans = pow(10, b);
        } else {
          ans = pow(10, b - 1) * 9;
        }
      } else {
        ans = pow(10, b);
      }
    }
  } else if (a[len - 1] == '0' || a[len - 1] == '5') {
    if (a[0] != 'X' && a[0] != '_') {
      ans = pow(10, b - 1) * 2;
    } else {
      if (a[0] == 'X' && a[len - 2] == 'X') {
        if (a[len - 1] == '0') {
          ans = pow(10, b - 1);
        } else {
          ans = pow(10, b - 1) * 2;
        }
      } else {
        ans = pow(10, b - 2) * 9 * 2;
      }
    }
  } else if (a[len - 2] == '0' || a[len - 2] == '5' || a[len - 2] == '7') {
    if (a[0] != 'X' && a[0] != '_') {
      ans = pow(10, b - 1) * 2;
    } else {
      ans = pow(10, b - 2) * 9 * 2;
    }
  } else if ((a[len - 1] == 'X' || a[len - 1] == '_') &&
             (a[len - 2] == 'X' || a[len - 2] == '_')) {
    if (a[0] != 'X' && a[0] != '_') {
      if (a[len - 1] == 'X' && a[len - 2] == 'X') {
        ans = pow(10, b - 1);
      } else {
        ans = 3 * pow(10, b - 2);
      }
    } else {
      if (a[len - 1] == 'X' && a[len - 2] == 'X') {
        if (a[0] != 'X') {
          ans = pow(10, b - 2) * 9;
        }
      } else if (a[len - 1] == 'X') {
        if (a[0] == 'X') {
          ans = pow(10, b - 2);
        } else {
          ans = pow(10, b - 3) * 3 * 9;
        }
      } else if (a[len - 2] == 'X') {
        if (a[0] == 'X') {
          ans = pow(10, b - 2) * 2;
        } else {
          ans = pow(10, b - 3) * 3 * 9;
        }
      } else {
        ans = pow(10, b - 3) * 9 * 3;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
