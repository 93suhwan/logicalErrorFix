#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long T = 1;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    array<long long, 2> a[n];
    long long ans[n];
    map<long long, vector<array<long long, 3>>> mp;
    long long b[n];
    long long cnt = 0;
    for (long long i = 0; i < n; i++) {
      long long x, y, m;
      cin >> x >> y >> m;
      a[i] = {x, y};
      b[i] = m;
      long long mn = max((long long)0, x - m);
      long long k = m - min(m, y);
      long long mx = x - k;
      mp[x + y - m].push_back({mn, mx, i});
    }
    for (auto x : mp) {
      vector<array<long long, 3>> v(x.second);
      sort(v.begin(), v.end());
      for (long long i = 0; i < v.size(); i++) {
        long long l = 0, r = 1e9;
        long long j = i;
        while (j < v.size() && max(l, v[j][0]) <= min(r, v[j][1])) {
          l = max(l, v[j][0]);
          r = min(r, v[j][1]);
          j++;
        }
        while (i < v.size() && i <= j) {
          long long id = v[i][2];
          ans[id] = a[id][0] - l;
          i++;
        }
        cnt++;
        i--;
      }
    }
    cout << cnt << '\n';
    for (long long i = 0; i < n; i++) {
      cout << ans[i] << ' ' << b[i] - ans[i] << '\n';
    }
  }
  return 0;
}
