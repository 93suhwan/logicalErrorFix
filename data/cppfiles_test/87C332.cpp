#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      ans = max(ans, a[i] - i - 1);
    }
    cout << ans;
    cout << endl;
  }
}
