#include <bits/stdc++.h>
using namespace std;
long long dx[4] = {-1, 0, 1, 0};
long long dy[4] = {0, -1, 0, 1};
const long long mod = 1e9 + 7;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> v(n);
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
      cin >> v[i];
      sum += v[i];
    }
    sort(v.begin(), v.end(), greater<long long>());
    long long ans = 1e18, cur;
    cur = 0;
    if (sum > k) cur += (sum - k);
    ans = min(ans, cur);
    for (long long i = 0; i < n - 1; i++) {
      cur = i + 1;
      sum -= (v[i] - v[n - 1]);
      if (sum > k) cur += (sum - k - 1) / (i + 2) + 1;
      ans = min(ans, cur);
    }
    cout << ans << "\n";
  }
  return 0;
}
