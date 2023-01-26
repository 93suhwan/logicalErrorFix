#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 10;
long long t, n;
long long a[N];
signed main() {
  cin >> t;
  while (t--) {
    map<long long, long long> mp;
    cin >> n;
    long long s = 0;
    for (long long i = 1; i <= n; i++) {
      scanf("%lld", &a[i]);
      s += a[i];
      a[i] *= n;
    }
    s *= 2;
    long long res = 0;
    for (long long i = 1; i <= n; i++) {
      res += mp[s - a[i]];
      mp[a[i]]++;
    }
    cout << res << '\n';
  }
}
