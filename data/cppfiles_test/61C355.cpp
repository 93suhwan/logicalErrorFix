#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int t;
int n;
int ans;
char a[N];
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    ans = 0;
    int flag = 999999;
    for (int i = 0; i < n; i++) {
      if (a[i] == '?')
        ;
      else
        flag = min(flag, i);
    }
    if (n == 1) {
      if (a[0] == '?')
        cout << 'B' << endl;
      else
        cout << a[0] << endl;
      continue;
    }
    if (flag == 999999) {
      cout << 'R';
      for (int i = 1; i < n; i++) {
        if (i & 1)
          cout << 'B';
        else
          cout << 'R';
      }
      cout << endl;
      continue;
    }
    for (int i = flag - 1; i >= 0; i--) {
      if (a[i + 1] == 'R') {
        a[i] = 'B';
      } else {
        a[i] = 'R';
      }
    }
    for (int i = flag + 1; i < n; i++) {
      if (a[i] == '?') {
        if (a[i - 1] == 'R') {
          a[i] = 'B';
        } else {
          a[i] = 'R';
        }
      }
    }
    for (int i = 0; i < n; i++) {
      cout << a[i];
    }
    cout << endl;
  }
  return 0;
}
