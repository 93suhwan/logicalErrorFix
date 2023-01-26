#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
map<long long, long long> mp;
long long T, n, m, ans;
long long l[400005], r[400005], a[400005], pre[400005], suf[400005];
int main() {
  ios::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> n >> m;
    ans = INF;
    mp.clear();
    for (long long i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (long long i = 1; i <= n; i++) {
      l[i] = r[i] = a[i];
      mp[a[i]] = i;
    }
    a[0] = -INF;
    a[n + 1] = INF;
    for (long long tl, tr, pl, pr, i = 1; i <= m; i++) {
      cin >> tl >> tr;
      pl = lower_bound(a + 1, a + 1 + n + 1, tl) - a;
      pr = upper_bound(a + 1, a + 1 + n + 1, tr) - a - 1;
      if (pl <= pr) continue;
      l[pl] = min(l[pl], tr);
      r[pr] = max(r[pr], tl);
    }
    suf[n + 1] = pre[0] = 0;
    for (long long i = 1; i <= n; i++) pre[i] = pre[i - 1] + (a[i] - l[i]);
    for (long long i = n; i >= 1; i--) suf[i] = suf[i + 1] + (r[i] - a[i]);
    for (long long i = 1; i <= n; i++)
      ans = min(ans, pre[i - 1] + suf[i + 1] +
                         (min(r[i] - a[i], a[i] - l[i]) + r[i] - l[i]));
    cout << ans << '\n';
  }
  return 0;
}
