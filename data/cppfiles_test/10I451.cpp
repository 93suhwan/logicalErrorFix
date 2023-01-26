#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
long long h[N], e[N], nx[N], idx;
long long k, T, t, n, m, ans, cnt;
long long a[N], b[N], c[N];
long long vis[N];
priority_queue<long long, vector<long long>, greater<long long> > q;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> T;
  while (T--) {
    long long cnt = 0;
    cin >> n >> k;
    for (long long i = 1; i <= n; i++) vis[i] = 0, c[i] = 0;
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
      bool flag = false;
      while (b[num] == 0) num++;
      if (!vis[a[i]]) {
        cout << 0 << " ";
        continue;
      }
      for (long long j = max(num, c[a[i]] + 1); j <= k; j++) {
        if (b[j] > 0) {
          b[j]--;
          c[a[i]] = j;
          cout << j << " ";
          flag = true;
          break;
        }
      }
      if (!flag) cout << "0 ";
      vis[a[i]]--;
    }
    cout << '\n';
  }
  return 0;
}
