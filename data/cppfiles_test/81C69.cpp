#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, d;
  cin >> n >> d;
  vector<pair<int, int> > a(n);
  for (int i = 0; i < n; ++i) cin >> a[i].second >> a[i].first;
  sort(a.begin(), a.end(),
       [&](const pair<int, int>& x, const pair<int, int>& y) {
         int mx1 = max(x.first, x.second);
         int mx2 = max(y.first, y.second);
         return make_pair(mx1, x.second) < make_pair(mx2, y.second);
       });
  int res = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i].second >= d) ++res, d = max(d, a[i].first);
  }
  cout << res;
  return 0;
}
