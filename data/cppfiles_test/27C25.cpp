#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, k;
    cin >> n >> m >> k;
    long long mn = n - 1;
    long long mx = n * (n - 1) / 2;
    if (!(m >= mn && m <= mx)) {
      cout << "NO\n";
      continue;
    }
    k -= 2;
    if (k < 0)
      cout << "NO\n";
    else if (k == 0) {
      if (n == 1)
        cout << "YES\n";
      else
        cout << "NO\n";
    } else if (k == 1) {
      if (m == mx)
        cout << "YES\n";
      else
        cout << "NO\n";
    } else
      cout << "YES\n";
  }
}
