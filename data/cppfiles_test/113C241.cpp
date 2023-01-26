#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
vector<long long> v;
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, x, y;
  cin >> n;
  long long s = 0LL;
  long long mx = 0LL;
  for (int i = 0; i < n; i++) {
    cin >> x;
    v.push_back(x);
    s += x;
  }
  sort(v.begin(), v.end());
  long long m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    long long xx = lower_bound(v.begin(), v.end(), x) - v.begin();
    if (xx >= n) {
      mx = v[xx - 1];
      long long ans = x - mx;
      if (s - mx < y) ans += y - (s - mx);
      cout << ans << endl;
    } else {
      mx = v[xx];
      if (y <= (s - mx)) {
        cout << 0 << endl;
      } else if (xx == 0) {
        long long ans = 0;
        if (s - mx < y) ans += y - (s - mx);
        cout << ans << endl;
      } else {
        long long ans1 = 0;
        if (s - mx < y) ans1 += y - (s - mx);
        mx = v[xx - 1];
        long long ans = x - mx;
        if (s - mx < y) ans += y - (s - mx);
        cout << min(ans, ans1) << endl;
      }
    }
  }
  v.clear();
  return 0;
}
