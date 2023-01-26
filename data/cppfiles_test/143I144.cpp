#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t, n, i, j, k;
  cin >> t;
  while (t--) {
    cin >> n;
    for (i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    set<pair<int, int> > extra;
    set<pair<int, int> >::iterator it;
    for (i = 1; i < n; i++) {
      if (a[i] == a[i - 1]) extra.insert({a[i], i});
    }
    int inc = 0;
    for (i = 0; i <= n; i++) {
      int kom = lower_bound(a, a + n, i) - a;
      if (kom < i) {
        cout << -1 << ' ';
        break;
      }
      int beshi = upper_bound(a, a + n, i) - a;
      int cnt = beshi - kom;
      int ans = cnt;
      if (i > 0) {
        if (kom == 0) {
          cout << -1 << ' ';
          break;
        }
        if (a[kom - 1] != (i - 1)) {
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
