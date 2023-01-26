#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
long long a[N];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    if (a[1] == 1) {
      cout << n + 1 << " ";
      for (long long i = 1; i <= n; i++) cout << i << " ";
      cout << endl;
    } else if (a[n] == 0) {
      for (long long i = 1; i <= n; i++) cout << i << " ";
      cout << n + 1 << endl;
    } else {
      long long b = 0, plas = 0;
      for (long long i = 1; i < n; i++) {
        if (!a[i] && a[i + 1]) {
          b = i;
          plas = 1;
          break;
        }
      }
      if (!plas)
        cout << -1 << endl;
      else {
        for (long long i = 1; i <= b; i++) cout << i << " ";
        cout << n + 1 << " ";
        for (long long i = b + 1; i <= n; i++) cout << i << " ";
        cout << endl;
      }
    }
  }
  return 0;
}
