#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++) cin >> v[i];
    long long maxi = -1e9;
    long long ind;
    long long ans = -1e9;
    long long mini = 1e9;
    long long m = -1e9;
    for (long long i = 0; i < n; i++) {
      if (v[i] > maxi) {
        ind = i;
      }
      maxi = max(maxi, v[i]);
    }
    for (long long i = ind - 1; i >= 0; i--) {
      mini = min(mini, v[i]);
      ans = max(ans, v[ind] * min(mini, v[i]));
    }
    for (long long i = ind + 1; i < n; i++) {
      m = max(m, v[i]);
      ans = max(ans, v[ind] * m);
    }
    sort(v.begin(), v.end());
    long long x = v[n - 1] * v[n - 2];
    cout << ans << endl;
  }
}
