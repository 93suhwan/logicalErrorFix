#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n;
  cin >> n;
  while (n--) {
    long long t;
    cin >> t;
    char a[t + 5];
    cin >> a;
    if (t == 1 && a[0] == '?') {
      cout << "B" << endl;
      continue;
    }
    long long th = t - 1;
    for (long long i = 0; i < t; i++) {
      if (a[i] != '?') {
        th = i;
        break;
      }
    }
    for (long long i = th - 1; i >= 0; i--) {
      if (a[i] == '?') {
        if (a[i + 1] == 'B') {
          a[i] = 'R';
        } else {
          a[i] = 'B';
        }
      }
    }
    for (long long i = th + 1; i < t; i++) {
      if (a[i] == '?') {
        if (a[i - 1] == 'B') {
          a[i] = 'R';
        } else {
          a[i] = 'B';
        }
      }
    }
    cout << a << endl;
  }
}
