#include <bits/stdc++.h>
using namespace std;
const int maxn = 10;
char a[maxn];
int ans = 1;
int main() {
  scanf("%s", a + 1);
  int len = strlen(a + 1);
  if (len == 1) {
    if (a[1] == '0')
      cout << "1" << endl;
    else if (a[1] == 'X' || a[1] == '_')
      cout << "1" << endl;
    else
      cout << "0" << endl;
    return 0;
  } else if (len == 2) {
    if (a[1] == '0')
      cout << "0" << endl;
    else if (a[1] == 'X') {
      if (a[2] == '0') cout << "1" << endl;
      if (a[2] == '5') cout << "2" << endl;
      if (a[2] == 'X') cout << "0" << endl;
      if (a[2] == '_') cout << "3" << endl;
    } else if (a[1] == '2' && a[2] == '5')
      cout << "1" << endl;
    else if (a[1] == '5' && a[2] == '0')
      cout << "1" << endl;
    else if (a[1] == '7' && a[2] == '5')
      cout << "1" << endl;
    else if (a[1] == '_') {
      if (a[2] == '5') cout << "2" << endl;
      if (a[2] == '0') cout << "1" << endl;
      if (a[2] == '_' || a[2] == 'X') cout << "3" << endl;
    } else
      cout << "0" << endl;
    return 0;
  }
  if (a[1] == '0')
    cout << "0" << endl;
  else if (a[len] != '0' && a[len] != '5' && a[len] != 'X' && a[len] != '_')
    cout << "0" << endl;
  else if (a[len - 1] != '0' && a[len - 1] != '5' && a[len - 1] != '7' &&
           a[len - 1] != '2' && a[len - 1] != 'X' && a[len - 1] != '_')
    cout << "0" << endl;
  else if (a[1] == 'X' && a[len] == 'X' && a[len - 1] == 'X')
    cout << "0" << endl;
  else {
    if (a[len] == 'X' && a[len - 1] == 'X') {
      for (int i = len - 2; i >= 2; i--)
        if (a[i] == '_') ans *= 10;
      if (a[1] == '_') ans *= 9;
      cout << ans << endl;
    } else if (a[len] == 'X' && a[len - 1] == '_') {
      if (a[1] == 'X')
        ans = 3;
      else
        ans = 4;
      for (int i = len - 2; i >= 2; i--)
        if (a[i] == '_') ans *= 10;
      if (a[1] == '_') ans *= 9;
      cout << ans << endl;
    } else if (a[len] == '_' && a[len - 1] == '_') {
      bool flag = false;
      ans = 4;
      for (int i = len - 2; i >= 2; i--) {
        if (a[i] == '_') ans *= 10;
        if (a[i] == 'X') flag = true;
      }
      if (flag)
        if (a[1] == 'X')
          ans *= 9;
        else
          ans *= 10;
      if (a[1] == '_') ans *= 9;
      cout << ans << endl;
    } else if (a[len] == '_' && a[len - 1] == 'X') {
      if (a[1] == 'X')
        ans = 3;
      else
        ans = 4;
      for (int i = len - 2; i >= 2; i--)
        if (a[i] == '_') ans *= 10;
      if (a[1] == '_') ans *= 9;
      cout << ans << endl;
    } else if (a[len - 1] == 'X' && a[len] == '5') {
      ans = 2;
      for (int i = len - 2; i >= 2; i--)
        if (a[i] == '_') ans *= 10;
      if (a[1] == '_') ans *= 9;
      cout << ans << endl;
    } else if (a[len - 1] == '5' && a[len] == 'X') {
      if (a[1] == 'X') ans = 0;
      for (int i = len - 2; i >= 2; i--)
        if (a[i] == '_') ans *= 10;
      if (a[1] == '_') ans *= 9;
      cout << ans << endl;
    } else if (a[len - 1] == 'X' && a[len] == '0') {
      if (a[1] == 'X')
        ans = 1;
      else
        ans = 2;
      for (int i = len - 2; i >= 2; i--)
        if (a[i] == '_') ans *= 10;
      if (a[1] == '_') ans *= 9;
      cout << ans << endl;
    } else if (a[len - 1] == '0' && a[len] == 'X') {
      if (a[1] == 'X') ans = 0;
      for (int i = len - 2; i >= 2; i--)
        if (a[i] == '_') ans *= 10;
      if (a[1] == '_') ans *= 9;
      cout << ans << endl;
    } else if ((a[len - 1] == '2' || a[len - 1] == '7') && a[len] == 'X') {
      ans = 1;
      for (int i = len - 2; i >= 2; i--)
        if (a[i] == '_') ans *= 10;
      if (a[1] == '_') ans *= 9;
      cout << ans << endl;
    } else if (a[len - 1] == '_' && (a[len] == '0' || a[len] == '5')) {
      ans = 2;
      for (int i = len - 2; i >= 2; i--)
        if (a[i] == '_') ans *= 10;
      if (a[1] == '_') ans *= 9;
      cout << ans << endl;
    } else if (a[len] == '_' && (a[len - 1] == '0' || a[len - 1] == '2' ||
                                 a[len - 1] == '5' || a[len - 1] == 7)) {
      ans = 1;
      for (int i = len - 2; i >= 2; i--)
        if (a[i] == '_') ans *= 10;
      if (a[1] == '_') ans *= 9;
      cout << ans << endl;
    } else if ((a[len] - '0' + (a[len - 1] - '0') * 10) % 25)
      cout << "0" << endl;
    else {
      bool flag = false;
      for (int i = len - 2; i >= 2; i--) {
        if (a[i] == '_') ans *= 10;
        if (a[i] == 'X') flag = true;
      }
      if (a[1] == '_') ans *= 9;
      if (flag)
        if (a[1] == 'X')
          ans *= 9;
        else
          ans *= 10;
      cout << ans << endl;
    }
  }
  return 0;
}
