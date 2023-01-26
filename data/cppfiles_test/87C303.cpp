#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> v(n);
    long long int ans = 0, c = 0;
    for (long long int i = 0; i < n; i++) cin >> v[i];
    for (long long int i = 0; i < n; i++) {
      c++;
      if (v[i] <= c)
        continue;
      else {
        ans += v[i] - c;
        c = v[i];
      }
    }
    cout << ans << endl;
  }
  return 0;
}
