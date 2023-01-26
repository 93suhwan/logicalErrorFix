#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
long long h[N], e[N], nx[N], idx;
long long k, T, t, n, m, ans, cnt;
long long a[N], b[N], c[N], res[N];
long long vis[N];
priority_queue<long long, vector<long long>, greater<long long> > q;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> T;
  while (T--) {
    long long cnt = 0;
    cin >> n >> k;
    for (long long i = 1; i <= n; i++) vis[i] = 0, c[i] = 0, res[i] = 0;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
      vis[a[i]]++;
      if (vis[a[i]] <= k) cnt++;
    }
    long long x = cnt / k, num = 1;
    for (long long i = 1; i <= n; i++)
      if (vis[a[i]] > k) vis[a[i]] = k;
    for (long long i = 1; i <= k; i++) b[i] = x;
    for (long long i = 1; i <= n; i++) {
      if (!vis[a[i]]) {
        cout << 0 << " ";
        continue;
      }
      long long l = 1, r = k;
      while (l < r) {
        long long mid = l + r >> 1;
        if (b[mid] && c[a[i]] < mid)
          r = mid;
        else
          l = mid + 1;
      }
      if (b[l] > 0) b[l]--;
      cout << l << " ";
      c[a[i]] = l;
      vis[a[i]]--;
    }
    cout << '\n';
  }
  return 0;
}
