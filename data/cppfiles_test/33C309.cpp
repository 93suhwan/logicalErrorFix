#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (auto &x : a) {
      cin >> x;
    }
    long long ans = a[0] * a[1];
    for (long long i = 0; i + 1 < n; i++) {
      ans = max(ans, a[i] * a[i + 1]);
    }
    cout << ans << '\n';
  }
}
