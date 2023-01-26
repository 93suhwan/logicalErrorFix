#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, t, cnt1 = 0, cnt0 = 0;
    cin >> n;
    for (long long i = 0; i < n; i++) {
      cin >> t;
      if (t == 1) {
        cnt1++;
      }
      if (t == 0) {
        cnt0++;
      }
    }
    cout << cnt1 * (pow(2, cnt0)) << "\n";
  }
}
