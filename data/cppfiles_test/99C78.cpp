#include <bits/stdc++.h>
using namespace std;
void _SSGJ_() {
  long long x, n;
  cin >> x >> n;
  if (abs(x) % 2) {
    if (n % 2 == 0) {
      if (n % 4 == 0) {
        cout << x << "\n";
      } else {
        cout << x - 1 << "\n";
      }
    } else {
      if ((n - 1) % 4 == 0) {
        cout << x + n << "\n";
      } else {
        cout << x - 1 - n << "\n";
      }
    }
  } else {
    if (n % 2 == 0) {
      if (n % 4 == 0) {
        cout << x << "\n";
      } else {
        cout << x + 1 << "\n";
      }
    } else {
      if ((n - 1) % 4 == 0) {
        cout << x - n << "\n";
      } else {
        cout << x + 1 + n << "\n";
      }
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) _SSGJ_();
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
       << "\n";
  return 0;
}
