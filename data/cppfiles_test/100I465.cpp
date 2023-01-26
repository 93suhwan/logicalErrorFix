#include <bits/stdc++.h>
using namespace std;
long long md = 998244353;
long long bigmod(long long a, long long b) {
  if (b == 0) return 1;
  if (b % 2) {
    long long x = a * bigmod(a, b - 1);
    return x % md;
  } else {
    long long x = bigmod(a, b / 2);
    x = (x * x) % md;
    return x;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  long long fq[200005], i;
  fq[0] = 1;
  fq[1] = 1;
  for (i = 2; i <= 200005; i++) {
    fq[i] = fq[i - 1] * i;
    fq[i] %= md;
  }
  while (tc--) {
    long long n, an = 0, oo, a[200005], j, k, p, ans, ok = 0;
    cin >> n;
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    p = a[0];
    for (i = 0; i < n - 1; i++) {
      if (a[i] == p || a[i] == p + 1) {
        p = a[i];
      } else {
        ok = 1;
        break;
      }
    }
    if (ok) {
      p = a[n - 1];
      if (a[n - 2] == p) {
        cout << fq[n] << endl;
      } else
        cout << 0 << endl;
    } else {
      if (a[n - 1] == a[n - 2]) {
        cout << fq[n] << endl;
      } else {
        p = a[n - 1];
        p--;
        for (i = 0; i < n; i++) {
          if (a[i] < p) an++;
        }
        ans = fq[n] + md;
        ans -= (fq[n - 1]);
        for (i = 1; i <= an; i++) {
          ans += md;
          oo = (fq[n - i - 1]);
          oo %= md;
          oo = oo * fq[an];
          oo %= md;
          if (an != i) oo = oo * bigmod(fq[an - i], md - 2);
          oo %= md;
          ans -= oo;
          ans += 3 * md;
          ans %= md;
        }
        ans %= md;
        cout << ans << endl;
      }
    }
  }
}
