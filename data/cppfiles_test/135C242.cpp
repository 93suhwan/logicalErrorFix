#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
long long dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
long long dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long a[n];
    for (long long i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a, a + n);
    long long ans = 0;
    for (long long i = 0; i < n - 2 * k; ++i) ans += a[i];
    map<long long, long long> mp;
    for (long long i = n - 2 * k; i < n; ++i) {
      mp[a[i]]++;
    }
    for (auto it : mp) {
      if (it.second > k) {
        ans += (it.second - k);
        break;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
