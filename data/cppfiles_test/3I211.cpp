#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
  cin >> s;
  int n = s.size();
  if (n == 1) {
    if (s == "0") {
      cout << 1 << endl;
    } else {
      cout << 0 << endl;
    }
    return 0;
  }
  int l = 1, r = 9;
  for (int i = 0; i < n - 1; i++) {
    l *= 10;
    r *= 10;
    r += 9;
  }
  if (n == 2) {
    l = 25;
  }
  int ans = 0;
  for (int i = l; i <= r; i += 25) {
    int j = i;
    int x = -1;
    bool ok = true;
    for (int k = s.size() - 1; k >= 0; k--) {
      if (s[k] == '_' || ((s[k] - '0') == j % 10))
        ;
      else if (s[k] == 'X') {
        if (x == -1) {
          x = j % 10;
        } else {
          if (j % 10 != x) {
            ok = false;
            break;
          }
        }
      } else {
        ok = false;
        break;
      }
      j /= 10;
    }
    if (ok) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
