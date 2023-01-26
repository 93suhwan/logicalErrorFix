#include <bits/stdc++.h>
using namespace std;
long long t, n, a[205], vis[205], k;
pair<long long, long long> p[205];
long long check(long long x1, long long y1, long long x2, long long y2) {
  if (y1 < x2 || y2 < x1) return 0;
  if (x1 > y2 || x2 > y1) return 0;
  if (x1 < x2 && y1 > y2) return 0;
  if (x2 < x1 && y2 > y1) return 0;
  return 1;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    memset(a, 0, sizeof(a));
    memset(vis, 0, sizeof(vis));
    long long cnt = 0, sum = k, pos = 0;
    for (long long i = 1; i <= k; i++) {
      long long x, y;
      cin >> x >> y;
      if (x > y) swap(x, y);
      p[i].first = x, p[i].second = y;
      vis[x] = 1, vis[y] = 1;
    }
    long long ans = 0;
    for (long long i = 1; i <= 2 * n; i++) {
      if (!vis[i]) {
        a[++pos] = i;
      }
    }
    long long mid = pos / 2;
    mid++;
    for (long long i = 1; i <= k; i++) {
      for (long long j = i + 1; j <= k; j++) {
        ans += check(p[i].first, p[i].second, p[j].first, p[j].second);
      }
    }
    while (mid <= pos) {
      cnt++;
      sum++;
      p[sum].first = a[cnt];
      p[sum].second = a[mid];
      mid++;
      for (long long i = 1; i <= sum - 1; i++) {
        ans += check(p[sum].first, p[sum].second, p[i].first, p[i].second);
      }
    }
    cout << ans << endl;
  }
}
