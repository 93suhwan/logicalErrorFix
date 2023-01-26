#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353, tt = 1e5 + 10;
long long sx, sy, ex, ey;
long long mx[] = {-1, 0, 0, 1};
long long my[] = {0, -1, 1, 0};
long long n, m, t, s;
long long f[tt];
char c[tt];
signed main() {
  cin >> t;
  while (t--) {
    memset(c, 0, sizeof(c));
    cin >> c;
    if (c[0] == '0') {
      long long s = 0;
      for (long long i = 1; i < strlen(c); i++) {
        if (c[i] == '1') s++;
        if (c[i] == '0' && s == 1) s++;
        if (s == 2) break;
      }
      if (s == 0)
        cout << 1 << endl;
      else
        cout << s << endl;
    } else {
      long long s = 0;
      for (long long i = 1; i < strlen(c); i++) {
        if (c[i] == '0') {
          s++;
          if (s == 2) break;
        }
      }
      cout << s << endl;
    }
  }
}
