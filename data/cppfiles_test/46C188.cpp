#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++) {
      cin >> v[i];
    }
    long long ans = 0;
    long long mx = 0;
    for (long long i = n - 1; i >= 0; i--) {
      if (v[i] > mx) {
        ans++;
        mx = v[i];
      }
    }
    ans--;
    cout << ans << "\n";
  }
}
