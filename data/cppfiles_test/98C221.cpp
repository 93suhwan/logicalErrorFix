#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, ca, cb;
  cin >> t;
  string str;
  while (t--) {
    cin >> n;
    cin >> str;
    ca = 0;
    cb = 0;
    for (int i = 0; i < n; i++) {
      if (str[i] == 'a')
        ca += 1;
      else
        cb += 1;
    }
    if (n == 1 || ca == n || cb == n) {
      cout << -1 << ' ' << -1 << endl;
    } else {
      for (int i = 0; (i + 1) < n; i++) {
        if (str[i] == 'a' && str[i + 1] == 'b') {
          cout << i + 1 << ' ' << i + 2 << endl;
          break;
        } else if (str[i] == 'b' && str[i + 1] == 'a') {
          cout << i + 1 << ' ' << i + 2 << endl;
          break;
        }
      }
    }
  }
}
