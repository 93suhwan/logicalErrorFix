#include <bits/stdc++.h>
using namespace std;
int a[100001];
int b[100001];
int ans[100001];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int i, n;
    cin >> n;
    for (i = 1; i <= n; ++i) cin >> a[i];
    for (i = 1; i <= n; ++i) cin >> b[i];
    if (1 == n)
      cout << "1\n";
    else {
      vector<tuple<int, int, int> > v;
      for (i = 1; i <= n; ++i) v.push_back({a[i], b[i], i});
      sort(v.begin(), v.end());
      int ed, mx;
      tie(ignore, mx, ed) = v.back();
      ans[ed] = 1;
      int save;
      tie(ignore, save, ignore) = v[0];
      for (i = 0; i < n - 1; ++i) {
        int p, ix;
        tie(ignore, p, ix) = v[i];
        save = max(save, p);
        if (save > mx)
          ans[ix] = 1;
        else
          ans[ix] = 0;
      }
      vector<pair<int, int> > bb;
      for (i = 1; i <= n; ++i) bb.push_back({b[i], i});
      sort(bb.begin(), bb.end());
      for (i = 1; i < n; ++i) {
        int pre = bb[i - 1].second;
        int cur = bb[i].second;
        ans[cur] |= ans[pre];
      }
      for (i = 1; i <= n; ++i) cout << ans[i];
      cout << "\n";
    }
  }
  return 0;
}
