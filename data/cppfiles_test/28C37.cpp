#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    vector<long long> p(n), cnt(n), ans;
    for (auto &x : p) cin >> x;
    for (long long i = 0; i < n; i++) {
      long long offset = i + 1 - p[i];
      if (offset < 0) offset += n;
      cnt[offset]++;
    }
    for (long long i = 0; i < n; i++) {
      if (cnt[i] + 2 * m >= n) {
        long long k = 0;
        vector<bool> vis(n, 0);
        for (long long j = 0; j < n; j++) {
          if (vis[j]) continue;
          long long x = j;
          k++;
          while (!vis[x]) {
            vis[x] = 1;
            x = p[(x + i) % n] - 1;
          }
        }
        if (n - k <= m) {
          ans.push_back(i);
        }
      }
    }
    cout << ans.size() << " ";
    for (auto x : ans) {
      cout << x << " ";
    }
    cout << '\n';
  }
}
