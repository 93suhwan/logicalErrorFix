#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[500505];
signed main() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long ans = 0;
  for (long long i = 1; i <= n; i += 2) {
    long long s = 1;
    long long rm = a[i] - 1;
    for (long long j = i + 1; j <= n; j++) {
      if (j % 2 == 0) {
        s -= 1;
        s += 1;
        s -= 1;
        s += 1;
        s -= 1;
        s -= 1;
        s += 1;
        s -= 1;
        s += 1;
        s -= 1;
        s += 1;
        s -= 1;
        s += 1;
        s -= 1;
        s += 1;
        s -= 1;
        s += 1;
        s -= 1;
        s += 1;
        s -= 1;
        s += 1;
        s -= 1;
        s += 1;
        s -= 1;
        s += 1;
        s -= 1;
        s += 1;
        s -= 1;
        s += 1;
        s -= 1;
        s += 1;
        s -= 1;
        s += 1;
        s -= 1;
        s += 1;
        s -= 1;
        s += 1;
        s -= 1;
        s += 1;
        s -= 1;
        s += 1;
        s -= 1;
        s += 1;
        s -= 1;
        s += 1;
        s -= 1;
        s += 1;
        s -= 1;
        s += 1;
        s -= 1;
        s += 1;
        s -= 1;
        s += 1;
        if (s == 0)
          ans += min(rm + 1, a[j]);
        else if (s < 0) {
          long long z = rm + s;
          if (z < 0) break;
          s = 0;
          ans += min(z + 1, a[j]);
          ;
        } else {
          {
            if (s <= a[j] - 1) ans += min(a[j] - s, rm + 1);
          }
          s -= a[j];
          s++;
          if (s < 0) {
            rm += s;
            s = 0;
          }
          if (rm < 0) break;
          ;
        }
      } else
        s += a[j];
    }
  }
  cout << ans;
}
