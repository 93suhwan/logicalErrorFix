#include <bits/stdc++.h>
using namespace std;
long long md = 998244353;
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
    long long n, a[200005], j, k, p, ans, ok = 0;
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
      cout << 0 << endl;
    } else {
      if (a[n - 1] == a[n - 2]) {
        cout << fq[n] << endl;
      } else {
        ans = fq[n] + md;
        ans -= (fq[n - 1] * 2);
        if (n == 2) ans += fq[n - 1];
        ans += md;
        ans += md;
        ans += md;
        ans %= md;
        cout << ans << endl;
      }
    }
  }
}
