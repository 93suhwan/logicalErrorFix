#include <bits/stdc++.h>
using namespace std;
long long t, n;
bool ok;
long long a[10010];
signed main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    a[0] = 0;
    ok = 1;
    for (int i = 1; i <= n; i++) {
      if (a[i] == 1 && a[i - 1] == 0 && ok == true) {
        ok = false;
        cout << (n + 1) << ' ';
      }
      cout << i << ' ';
    }
    if (ok == true) {
      cout << (n + 1) << ' ';
    }
    cout << endl;
  }
}
