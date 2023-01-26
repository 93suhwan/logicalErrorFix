#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int T;
  cin >> T;
  while (T) {
    long long int n, f = -1;
    cin >> n;
    string a;
    cin >> a;
    for (long long int i = 0; i < n; i++) {
      if (a[i] != '?') {
        f = i;
        break;
      }
    }
    char x;
    if (f != -1) {
      if (f % 2 == 0)
        x = a[f];
      else {
        if (a[f] == 'R')
          x = 'B';
        else
          x = 'R';
      }
    }
    for (long long int i = 0; i < n; i++) {
      if (a[i] == '?') a[i] = x;
      if (a[i] == 'R') x = 'B';
      if (a[i] == 'B') x = 'R';
    }
    cout << a << endl;
    T--;
  }
}
