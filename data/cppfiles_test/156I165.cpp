#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long t;
  cin >> t;
  long long n, k;
  while (t--) {
    cin >> n >> k;
    long long a[n], s = 0, mn = 1e12, i, yy, tt, rr, j, ans;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      s += a[i];
      mn = min(mn, a[i]);
    }
    sort(a, a + n);
    if (s <= k)
      cout << 0 << endl;
    else {
      long long d = s - k;
      long long xx = 0, Mn = 1e15, dd = s - k, sm = mn;
      for (j = n - 1; j > 0; j--) {
        sm += a[j];
        xx++;
        yy = dd - sm;
        tt = ceil((yy + xx) / (xx + 1));
        tt = max(mn + tt, 0LL);
        rr = tt + xx;
        Mn = min(Mn, rr);
      }
      cout << min(d, Mn) << endl;
    }
  }
}
int main() { solve(); }
