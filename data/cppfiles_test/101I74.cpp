#include <bits/stdc++.h>
using namespace std;
long long t, n, m, k;
map<pair<long long, long long>, long long> q1, q2;
long long cnt1[200010], cnt2[200010];
long long a[200010], b[200010];
long long ans;
signed main() {
  scanf("%d", &t);
  while (t--) {
    ans = 0;
    q1.clear(), q2.clear();
    cin >> n >> m >> k;
    for (long long i = 1; i <= n; i++) scanf("%d", &a[i]), cnt1[i] = 0;
    for (long long i = 1; i <= m; i++) scanf("%d", &b[i]), cnt2[i] = 0;
    for (long long i = 1; i <= k; i++) {
      long long x, y;
      scanf("%d%d", &x, &y);
      long long l = lower_bound(a + 1, a + 1 + n, x) - a - 1;
      long long r = lower_bound(b + 1, b + 1 + m, y) - b - 1;
      if (x == a[l + 1]) {
        if (y == b[r + 1]) continue;
        cnt2[r]++, q2[make_pair(l, r)]++;
      } else
        cnt1[l]++, q1[make_pair(l, r)]++;
    }
    for (map<pair<long long, long long>, long long>::iterator it = q1.begin();
         it != q1.end(); it++)
      ans -= it->second * (it->second - 1) / 2;
    for (map<pair<long long, long long>, long long>::iterator it = q2.begin();
         it != q2.end(); it++)
      ans -= it->second * (it->second - 1) / 2;
    for (long long i = 1; i <= n; i++) ans += cnt1[i] * (cnt1[i] - 1) / 2;
    for (long long i = 1; i <= m; i++) ans += cnt2[i] * (cnt2[i] - 1) / 2;
    cout << ans << '\n';
  }
}
