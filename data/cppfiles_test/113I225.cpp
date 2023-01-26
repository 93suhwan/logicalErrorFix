#include <bits/stdc++.h>
using namespace std;
void solve() {
  vector<long long> v;
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
    if (xx > n) {
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
}
int main() {
  solve();
  return 0;
}
