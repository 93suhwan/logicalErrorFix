#include <bits/stdc++.h>
using namespace std;
int a[100001];
int b[100001];
int ans[100001];
int mx[100001];
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
      int ed;
      tie(ignore, mx[n - 1], ed) = v.back();
      ans[ed] = 1;
      for (i = n - 2; i >= 0; --i) {
        tie(ignore, mx[i], ignore) = v[i];
        mx[i] = max(mx[i], mx[i + 1]);
      }
      int save;
      tie(ignore, save, ignore) = v[0];
      for (i = 0; i < n - 1; ++i) {
        int p, ix;
        tie(ignore, p, ix) = v[i];
        save = max(save, p);
        if (save > mx[i + 1])
          ans[ix] = 1;
        else
          ans[ix] = 0;
      }
      for (i = 1; i <= n; ++i) cout << ans[i];
      cout << "\n";
    }
  }
  return 0;
}
