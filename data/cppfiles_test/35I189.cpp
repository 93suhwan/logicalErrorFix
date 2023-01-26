#include <bits/stdc++.h>
using namespace std;
int n, k;
void solve() {
  cin >> n >> k;
  if (n > k) {
    cout << 0 << endl;
  } else {
    long long t1 = (long long)log2(k);
    long long ans = 0;
    if (n == 0 && k == 0) {
      puts("1");
      return;
    }
    if (n == 1 && k == 1) {
      puts("2");
      return;
    }
    if (n == 0) {
      cout << 1 + k << endl;
      return;
    }
    for (long long i = t1; i >= 0; --i) {
      if ((long long)log2(n) > (long long)log2(k)) {
        cout << ans << endl;
        return;
      } else if ((long long)log2(n) == (long long)log2(k)) {
        if (n > k) {
          cout << ans << endl;
          return;
        } else {
          ans += min((n ^ k) + 1, 1 << ((long long)log2(n) + 1));
          cout << ans << endl;
          return;
        }
      }
      if ((1 << i) > k) continue;
      ans += (1 << i);
      k -= (1 << i);
    }
  }
}
signed main() {
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
