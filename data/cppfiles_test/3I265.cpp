#include <bits/stdc++.h>
using namespace std;
long long ans = 1, x = 0, n;
string s;
void go() {
  if (s[0] == '_') {
    ans *= 9;
    if (x) ans *= 10;
  } else if (s[0] == 'X')
    ans *= 9;
  else if (x)
    ans *= 10;
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
  cin >> s;
  n = s.size();
  if (n == 1) {
    if (s[0] != 'X' && s[0] != '_' && s[0] != '0')
      cout << 0;
    else
      cout << 1;
    return 0;
  }
  if (s[0] == '0') {
    cout << 0;
    return 0;
  }
  if (n == 2) {
    if (s[0] == 'X' && s[1] == s[0]) {
      cout << 0;
      return 0;
    }
    bool x2 = 0, y2 = 0;
    for (long long i = 0; i < n; i++) {
      if (s[i] == 'X')
        x2 = 1;
      else if (s[i] == '_')
        y2 = 1;
    }
    if (x2 && y2) {
      cout << 3;
      return 0;
    }
    if (s[1] == '5' && (s[0] == 'X' || s[0] == '_')) {
      cout << 2;
      return 0;
    }
    if (s[1] == '0' && (s[0] == 'X' || s[0] == '_')) {
      cout << 1;
      return 0;
    }
    if (s[0] == '2' && (s[1] == 'X' || s[1] == '_')) {
      cout << 1;
      return 0;
    }
    if (s[0] == '5' && (s[1] == 'X' || s[1] == '_')) {
      cout << 1;
      return 0;
    }
    if (s[0] == '7' && (s[1] == 'X' || s[1] == '_')) {
      cout << 1;
      return 0;
    }
    long long a = 1;
    if (s[0] >= '0' && s[0] <= '9' && s[1] >= '0' && s[1] <= '9')
      a = (s[0] - '0') * 10 + (s[1] - '0');
    if (a % 25)
      cout << 0;
    else
      cout << 1;
    return 0;
  }
  for (long long i = 1; i < n; i++) {
    if (s[i] == '_') ans *= 10;
    if (s[i] == 'X') x = 1;
  }
  if (s[n - 1] >= '0' && s[n - 1] <= '9' && s[n - 2] >= '0' &&
      s[n - 2] <= '9') {
    long long a = (s[n - 2] - '0') * 10 + (s[n - 1] - '0');
    if (a % 25) {
      cout << 0;
      return 0;
    }
    go();
    cout << ans;
    return 0;
  }
  if (s[n - 1] >= '0' && s[n - 1] <= '9') {
    if (s[n - 1] != '0' && s[n - 1] != '5') {
      cout << 0;
      return 0;
    }
    if (s[n - 1] == '5') {
      if (s[n - 2] == 'X') {
        ans *= 2;
        if (s[0] == '_') ans *= 9;
        cout << ans;
        return 0;
      }
      ans /= 5;
      go();
      cout << ans;
      return 0;
    }
    if (s[n - 1] == '0') {
      if (s[n - 2] == 'X') {
        if (s[0] == 'X')
          cout << ans;
        else if (s[0] == '_')
          cout << 18 * ans;
        else
          cout << ans * 2;
        return 0;
      }
      ans /= 5;
      go();
      cout << ans;
      return 0;
    }
  }
  if (s[n - 2] >= '0' && s[n - 2] <= '9') {
    if (s[n - 2] != '0' && s[n - 2] != '2' && s[n - 2] != '5' &&
        s[n - 2] != '7') {
      cout << 0;
      return 0;
    }
    if (s[n - 2] == '0' || s[n - 2] == '5') {
      if (s[n - 1] == 'X') {
        if (s[0] == 'X') {
          cout << 0;
          return 0;
        }
        if (s[0] == '_') ans *= 9;
        cout << ans;
        return 0;
      }
      ans /= 10;
      go();
      cout << ans;
      return 0;
    }
    if (s[n - 2] == '2' || s[n - 2] == '7') {
      if (s[n - 1] == 'X') {
        if (s[0] == '_') ans *= 9;
        cout << ans;
        return 0;
      }
      ans /= 10;
      go();
      cout << ans;
      return 0;
    }
  }
  if (s[n - 1] == 'X' && s[n - 1] == s[n - 2]) {
    if (s[0] == 'X') {
      cout << 0;
      return 0;
    }
    if (s[0] == '_') ans *= 9;
    cout << ans;
    return 0;
  }
  if (s[n - 1] == s[n - 2] && s[n - 1] == '_') {
    ans /= 25;
    go();
    cout << ans;
    return 0;
  }
  ans /= 10;
  if (s[n - 1] == 'X') {
    if (s[0] == 'X') {
      cout << 2 * ans;
      return 0;
    }
    if (s[0] == '_') {
      cout << 36 * ans;
      return 0;
    }
    cout << 4 * ans;
    return 0;
  }
  if (s[n - 2] == 'X') {
    if (s[0] == 'X') {
      cout << ans * 3;
      return 0;
    }
    if (s[0] == '_') {
      cout << ans * 36;
      return 0;
    }
    cout << ans * 4;
    return 0;
  }
}
