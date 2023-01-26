#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  if (s.size() == 1) {
    if (s == "0" || s == "X" || s == "_")
      cout << 1 << '\n';
    else
      cout << 0 << '\n';
    return 0;
  } else if (s.size() == 2) {
    long long ans;
    if (s == "XX")
      ans = 0;
    else if (s == "__" || s == "X_" || s == "_X")
      ans = 3;
    else if (s == "25" || s == "50" || s == "75")
      ans = 1;
    else if ((s[0] == '2' || s[0] == '5' || s[0] == '7') &&
             (s[1] == 'X' || s[1] == '_'))
      ans = 1;
    else if (s[1] == '5' && (s[0] == '_' || s[0] == 'X'))
      ans = 2;
    else if (s[1] == '0' && (s[0] == '_' || s[0] == 'X'))
      ans = 1;
    else
      ans = 0;
    cout << ans << '\n';
    return 0;
  } else if (s[0] == '0') {
    cout << 0 << '\n';
    return 0;
  }
  int len = s.size();
  string last = "";
  last += s[len - 2];
  last += s[len - 1];
  int x = 0;
  long long ans = 0;
  if (last == "XX" && s[0] != 'X') {
    ans = 1;
    x = 1;
  } else if (last == "XX")
    ans = 0;
  else if (last == "__")
    ans = 4;
  else if (last == "00" || last == "25" || last == "50" || last == "75")
    ans = 1;
  else if (last[0] == '2' || last[0] == '5' || last[0] == '7') {
    if (last[1] == '_') {
      ans = 1;
    } else if (last[1] == 'X') {
      if (s[0] == 'X' && last[0] == '5')
        ans = 0;
      else {
        x = 1;
        ans = 1;
      }
    } else
      ans = 0;
  } else if (last[0] == '0') {
    if (last[1] == '_') {
      ans = 1;
    } else if (last[1] == 'X' && s[0] != 'X') {
      x = 1;
      ans = 1;
    } else
      ans = 0;
  } else if (last[1] == '5') {
    if (last[0] == '_') {
      ans = 2;
    } else if (last[0] == 'X') {
      x = 2;
      ans = 2;
    } else
      ans = 0;
  } else if (last[1] == '0') {
    if (last[0] == '_')
      ans = 2;
    else if (last[0] == 'X' && s[0] != 'X') {
      x = 2;
      ans = 2;
    } else if (last[0] == 'X') {
      ans = 1;
      x = 1;
    } else
      ans = 0;
  } else if (last == "X_" && s[0] != 'X') {
    x = 4;
    ans = 4;
  } else if (last == "X_") {
    x = 3;
    ans = 3;
  } else if (last == "_X" && s[0] != 'X') {
    ans = 4;
    x = 2;
  } else if (last == "_X") {
    ans = 2;
    x = 1;
  } else
    ans = 0;
  bool adaX = (last[0] == 'X' || last[1] == 'X');
  bool ex = false;
  for (int i = 0; i < len - 2; i++) {
    if (s[i] == '_' && i != 0)
      ans *= 10;
    else if (s[i] == '_')
      ans *= 9;
    else if (s[i] == 'X')
      ex = true;
  }
  if (adaX)
    ans *= 1;
  else if (ex && s[0] != 'X')
    ans *= 10;
  else if (ex)
    ans *= 9;
  cout << ans << '\n';
  return 0;
}
