#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
using namespace std;
long long t, n, a[100005];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> t;
  while (t--) {
    cin >> n;
    long long mx = 0;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
      if (i >= 2) {
        mx = max(mx, a[i] * a[i - 1]);
      }
    }
    cout << mx << '\n';
  }
}
