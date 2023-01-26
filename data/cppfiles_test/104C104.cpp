#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (!b)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n), ans(n, 0);
    for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
      ans[i] = min(a[i], m);
      a[i] -= ans[i];
      b[i] -= m - ans[i];
    }
    long long int c0 = 0, c1 = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] - b[i] < 0)
        c0 += b[i] - a[i];
      else
        c1 += a[i] - b[i];
    }
    long long int fin = c1 - c0;
    if (fin < 0) {
      fin = abs(fin);
      for (int x = 0; x < n; x++) {
        b[x] += m - ans[x];
        a[x] += ans[x];
        a[x] = max(0, m - b[x]);
        int lim = ans[x] - a[x];
        if (fin <= 2 * lim) {
          ans[x] -= fin / 2;
          fin &= 1;
          break;
        } else {
          fin -= 2 * lim;
          ans[x] -= lim;
        }
      }
    }
    cout << fin << '\n';
    for (int i = 0; i < n; i++) cout << ans[i] << " " << m - ans[i] << '\n';
  }
}
