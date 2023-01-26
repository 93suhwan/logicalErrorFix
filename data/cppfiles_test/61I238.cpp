#include <bits/stdc++.h>
using namespace std;
long long n, k, m, s, t;
char a[1010];
signed main() {
  cin >> t;
  while (t--) {
    s = 0;
    memset(a, 0, sizeof(a));
    cin >> n;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] == '?') s++;
    }
    if (s == n) a[1] = 'B';
    long long pos = 1;
    for (; pos <= n; pos++) {
      if (a[pos] != '?') break;
    }
    if (a[pos] == 'R') {
      long long r = pos + 1, l = pos - 1;
      while (l > 0) {
        if (a[l] == '?')
          ;
        {
          if ((pos - l) % 2 == 1)
            a[l] = 'B';
          else
            a[l] = 'R';
        }
        l--;
      }
      while (r <= n) {
        if (a[r] == '?') {
          if ((r - pos) % 2 == 1)
            a[r] = 'B';
          else
            a[r] = 'R';
        }
        r++;
      }
    }
    if (a[pos] == 'B') {
      long long r = pos + 1, l = pos - 1;
      while (l > 0) {
        if (a[l] == '?') {
          if ((pos - l) % 2 == 1)
            a[l] = 'R';
          else
            a[l] = 'B';
        }
        l--;
      }
      while (r <= n) {
        if (a[r] == '?') {
          if ((r - pos) % 2 == 1)
            a[r] = 'R';
          else
            a[r] = 'B';
        }
        r++;
      }
    }
    cout << a + 1 << endl;
  }
}
