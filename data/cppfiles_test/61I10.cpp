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
    for (long long i = 0; i < n; i++) {
      if (a[i] != '?')
        cout << a[i];
      else {
        if (a[i - 1] == 'B')
          a[i] = 'R';
        else
          a[i] = 'B';
        cout << a[i];
      }
    }
    cout << endl;
  }
}
