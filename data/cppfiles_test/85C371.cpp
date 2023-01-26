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
    long long s = 0;
    memset(c, 0, sizeof(c));
    cin >> c;
    for (long long i = 0; i < strlen(c); i++) {
      if (c[i] == '1') {
        while (c[i] == '1') i++;
      }
      if (c[i] == '0') {
        s++;
        while (c[i] == '0') i++;
      }
      if (s == 2) break;
    }
    cout << s << endl;
  }
}
