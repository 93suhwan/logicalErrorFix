#include <bits/stdc++.h>
using namespace std;
long long n, k, m, s, t;
char a[1010];
signed main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (long long i = 0; i < n; i++) {
      if (a[i] == '?') s++;
    }
    if (s == n - 1) a[0] = 'B';
    long long pos = 0;
    while (a[pos] == '?') pos++;
    if (a[pos] == 'R') {
      long long r = pos + 1, l = pos - 1;
      while (l >= 0) {
        if (a[l] != '?')
          cout << a[l];
        else {
          if ((pos - l) % 2 == 1)
            cout << 'B';
          else
            cout << 'R';
        }
        l--;
      }
      cout << a[pos];
      while (r < n) {
        if (a[r] != '?')
          cout << a[r];
        else {
          if ((r - pos) % 2 == 1)
            cout << 'B';
          else
            cout << 'R';
        }
        r++;
      }
    }
    if (a[pos] == 'B') {
      long long r = pos + 1, l = pos - 1;
      while (l >= 0) {
        if (a[l] != '?')
          cout << a[l];
        else {
          if ((pos - l) % 2 == 1)
            cout << 'R';
          else
            cout << 'B';
        }
        l--;
      }
      cout << a[pos];
      while (r <= n) {
        if (a[r] != '?')
          cout << a[r];
        else {
          if ((r - pos) % 2 == 1)
            cout << 'R';
          else
            cout << 'B';
        }
        r++;
      }
    }
    cout << endl;
  }
}
