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
    bool b[n];
    for (long long i = 0; i < n; ++i) b[i] = false;
    for (long long i = n; i >= n - 2 * k; --i) {
      if (b[i]) continue;
      for (long long j = i - 1; j >= n - 2 * k; --j) {
        if (b[j])
          continue;
        else if (a[j] == a[i])
          continue;
        else {
          b[i] = true;
          b[j] = true;
          break;
        }
      }
    }
    long long val = 0;
    for (long long i = n - 2 * k; i < n; ++i) {
      if (!b[i]) ++val;
    }
    val /= 2;
    ans += val;
    cout << ans << '\n';
  }
  return 0;
}
