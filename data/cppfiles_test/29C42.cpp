#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k, cnt1 = 0, cnt0 = 0;
    cin >> n;
    for (long long i = 0; i < n; i++) {
      cin >> k;
      if (k == 1) {
        cnt1++;
      }
      if (k == 0) {
        cnt0++;
      }
    }
    long long temp = pow(2, cnt0);
    cout << cnt1 * temp << "\n";
  }
}
