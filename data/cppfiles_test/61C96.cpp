#include <bits/stdc++.h>
using namespace std;
char a[105];
int main() {
  int T, n, q;
  cin >> T;
  while (T--) {
    cin >> n >> a;
    bool flag = false;
    for (int i = 0; i < n; i++) {
      if (a[i] != '?') {
        q = i;
        flag = true;
      }
    }
    if (flag) {
      for (int i = q - 1; i >= 0; i--) {
        if (a[i] == '?' && a[i + 1] == 'R') a[i] = 'B';
        if (a[i] == '?' && a[i + 1] == 'B') a[i] = 'R';
      }
      for (int i = q + 1; i < n; i++) {
        if (a[i] == '?' && a[i - 1] == 'R') a[i] = 'B';
        if (a[i] == '?' && a[i - 1] == 'B') a[i] = 'R';
      }
    } else {
      a[0] = 'B';
      for (int i = 1; i < n; i++) {
        if (a[i] == '?' && a[i - 1] == 'R') a[i] = 'B';
        if (a[i] == '?' && a[i - 1] == 'B') a[i] = 'R';
      }
    }
    for (int i = 0; i < n; i++) cout << a[i];
    cout << endl;
  }
  return 0;
}
