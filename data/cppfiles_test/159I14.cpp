#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  if (n < 4) {
    cout << 1 << '\n' << 1;
    return 0;
  }
  if (n % 4 == 0) {
    cout << n - 1 << '\n';
    for (int i = 1; i <= n; i++)
      if (i != n / 2) cout << i << ' ';
  } else if (n % 4 == 1) {
    cout << n - 2 << '\n';
    for (int i = 1; i < n; i++)
      if (i != n / 2) cout << i << ' ';
  } else if (n % 4 == 2) {
    cout << n - 2 << '\n';
    for (int i = 1; i <= n; i++)
      if (i != 2 && i != n / 2) cout << i << ' ';
  } else {
    long long t = 1ll * (n - 3) * 2 * n;
    long long p = sqrt(t);
    if (p * p == t) {
      cout << n - 2 << '\n';
      for (int i = 1; i <= n; i++)
        if (i != n / 2 - 2 && i != n - 2) cout << i << ' ';
    } else {
      cout << n - 3 << '\n';
      for (int i = 1; i < n; i++)
        if (i != 2 && i != n / 2) cout << i << ' ';
    }
  }
  return 0;
}
