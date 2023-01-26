#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 10;
long long a[maxn];
long long mn[maxn];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t = 1;
  while (t--) {
    long long n;
    cin >> n;
    for (long long i = 0; i <= 500; ++i) mn[i] = 0x3f3f3f3f;
    for (long long i = 1; i <= n; ++i) {
      cin >> a[i];
      mn[a[i]] = min(mn[a[i]], a[i]);
      for (long long j = 0; j <= 500; ++j) {
        if (mn[j] >= a[i]) continue;
        mn[j ^ a[i]] = min(mn[j ^ a[i]], a[i]);
      }
    }
    long long ans = 1;
    for (long long i = 1; i <= 500; ++i)
      if (mn[i] != 0x3f3f3f3f) ans++;
    cout << ans << endl;
    cout << 0 << ' ';
    for (long long i = 1; i <= 500; ++i)
      if (mn[i] != 0x3f3f3f3f) cout << i << ' ';
    cout << endl;
  }
  return 0;
}
