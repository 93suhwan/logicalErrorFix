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
    set<int> need;
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
        if (upper_bound(a, a + n, i - 1) - lower_bound(a, a + n, i - 1) == 0) {
          need.insert(i - 1);
          vector<int> temp;
          for (int x : need) {
            it = extra.lower_bound(make_pair(x, 0));
            if (it == extra.begin()) {
              cout << -1 << ' ';
              break;
            }
            it--;
            inc += (x - it->first);
            extra.erase(it);
            temp.push_back(x);
          }
          for (int x : temp) need.erase(x);
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
