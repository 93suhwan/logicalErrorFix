#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long n, n1, n2, k, a[N], b[N], p;
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    n1 = n2 = 0;
    for (int i = 1, j = 1, l = 1; i <= n; i++) {
      cin >> p;
      if (p < 0) {
        a[j++] = -p;
        n1++;
      }
      if (p > 0) {
        b[l++] = p;
        n2++;
      }
    }
    sort(a + 1, a + 1 + n1);
    sort(b + 1, b + n2 + 1);
    long long res = 0, q = 0, t = 0;
    for (int i = 1; i <= k; i++) {
      q = 0;
      for (int j = i; j <= n1; j += k) {
        q += 2 * a[j];
        if (j != n1 && j + k > n1) q += 2 * a[n1];
      }
      if (res == 0)
        res = q;
      else if (q)
        res = min(res, q);
    }
    for (int i = 1; i <= k; i++) {
      q = 0;
      for (int j = i; j <= n2; j += k) {
        q += 2 * b[j];
        if (j != n2 && j + k > n2) q += 2 * b[n2];
      }
      if (t == 0)
        t = q;
      else if (q)
        t = min(t, q);
    }
    if (n1 == 0)
      res = res + t - b[n2];
    else if (n2 == 0)
      res = res + t - a[n1];
    else if (a[n1] < b[n2])
      res = res + t - b[n2];
    else
      res = res + t - a[n1];
    cout << res << '\n';
  }
  return 0;
}
