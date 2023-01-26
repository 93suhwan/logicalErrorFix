#include <bits/stdc++.h>
using namespace std;
long long l1, l2, k0, k, k1, k2, k3, k4, k5, k6, q, x, y, t, u, g, p, ma, mi,
    f1, f2, f, l, n, i, m, j, b[200007], a[200007], c[100007], ans, up, r, v, d;
long long e1, e2, e3, e4, e5, w, c0, c1, h, p1, p2, yy, n1, n2, n3, i1, j11, p3;
string s4, s5, s6, s2, s1[107], s, s3;
char ch;
int main() {
  cin >> t;
  for (u = 1; u <= t; u++) {
    cin >> n;
    for (i = 1; i <= n - 2; i++) cin >> s1[i];
    p = 0;
    for (i = 1; i < n - 2; i++)
      if (s1[i][1] != s1[i + 1][0]) p = i;
    if (p == 0) {
      cout << s1[1][0];
      for (i = 1; i <= n - 2; i++) cout << s1[i][0];
      cout << s1[n - 2][1] << endl;
    } else {
      for (i = 1; i <= p; i++) cout << s1[i][0];
      cout << s1[p][1];
      for (i = p + 1; i <= n - 2; i++) cout << s1[i][0];
      cout << s1[n - 2][1] << endl;
    }
  }
  return 0;
}
