#include <bits/stdc++.h>
using namespace std;
const long long inf = 1100000000000000000;
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  map<long long, long long> mp;
  long long cnt = 1, res = 0;
  for (long long i = 0; i < n; i++) {
    if (a[i] <= n and !mp[a[i]])
      mp[a[i]]++;
    else {
      while (mp[cnt]) cnt++;
      if (2 * cnt >= a[i]) {
        cout << -1;
        return;
      } else
        mp[cnt]++, res++;
    }
  }
  cout << res;
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  long long T = 1, cnt = 0;
  cin >> T;
  while (T--) {
    solve();
    cout << '\n';
  }
  return 0;
}
