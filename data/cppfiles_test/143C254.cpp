#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t, n, i, j, k;
  cin >> t;
  while (t--) {
    cin >> n;
    for (i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    set<pair<long long, long long> > extra;
    set<pair<long long, long long> >::iterator it;
    for (i = 1; i < n; i++) {
      if (a[i] == a[i - 1]) extra.insert({a[i], i});
    }
    long long inc = 0;
    for (i = 0; i <= n; i++) {
      long long kom = lower_bound(a, a + n, i) - a;
      if (kom < i) {
        cout << -1 << ' ';
        break;
      }
      long long beshi = upper_bound(a, a + n, i) - a;
      long long cnt = beshi - kom;
      long long ans = cnt;
      if (i > 0) {
        if (kom == 0) {
          cout << -1 << ' ';
          break;
        }
        if (upper_bound(a, a + n, i - 1) - lower_bound(a, a + n, i - 1) == 0) {
          it = extra.lower_bound(make_pair(i - 1, 0));
          if (it == extra.begin()) {
            cout << -1 << ' ';
            break;
          }
          it--;
          inc += (i - 1 - it->first);
          extra.erase(it);
        }
      }
      ans += inc;
      cout << ans << ' ';
    }
    if (i <= n) {
      for (j = i + 1; j <= n; j++) cout << -1 << ' ';
    }
    cout << endl;
  }
}
