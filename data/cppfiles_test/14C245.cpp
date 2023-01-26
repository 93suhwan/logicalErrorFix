#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, i, a[51], n2;
  cin >> t;
  while (t--) {
    long long d[51], l[51], r[51], b[51], s = 0, y = 0, m, j = 0, e;
    cin >> n;
    n2 = n;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(b, b + n);
    while (n--) {
      for (i = y; i < n2; i++)
        if (b[y] == a[i]) {
          m = i;
          break;
        }
      if (m - y > 0) {
        s++;
        d[j] = m - y;
        l[j] = y + 1;
        r[j] = m + 1;
        j++;
        for (e = m; e > 0; e--) a[e] = a[e - 1];
      }
      y++;
    }
    cout << s << endl;
    for (i = 0; i < s; i++) cout << l[i] << ' ' << r[i] << ' ' << d[i] << endl;
  }
}
