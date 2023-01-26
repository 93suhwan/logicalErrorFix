#include <bits/stdc++.h>
using namespace std;
long long t, i, n, k, l, r, s, a[90], d;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    k++;
    s = 0;
    for (i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (i = 1; i < n; i++) {
      r = powl(10, a[i]);
      d = powl(10, a[i + 1] - a[i]) - 1;
      s = s + (r * min(k, d));
      k = k - min(k, d);
    }
    if (k <= 9) {
      s += 0;
    } else {
      s += powl(10, a[n]) * k;
    }
    cout << s << '\n';
  }
}
