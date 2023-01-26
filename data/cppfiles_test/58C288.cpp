#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
long long n, m, l, g = 0, t, one, two, maxx = 0, x, y, o, p, j, a[N], b[N],
                   s[N], e, gcd, ans, minn = 1e8, r;
char c[N], d[N];
string k;
signed main() {
  cin >> t;
  while (t--) {
    cin >> n >> c >> d;
    g = 0;
    for (long long i = 0; i < n; i++) {
      if (c[i + 1] == '1' && d[i + 1] == '1') {
        g = 1;
        break;
      }
    }
    if (g == 1) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
  return 0;
}
