#include <bits/stdc++.h>
using namespace std;
long long up(long long x, long long n) {
  if (x % n == 0)
    return x / n;
  else
    return x / n + 1;
}
long long gcd(long long a, long long b) {
  if (b != 0)
    return gcd(b, a % b);
  else
    return a;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long g, n;
    cin >> g >> n;
    vector<vector<long long> > b(g);
    for (long long i = 0; i < g; i++) {
      for (long long j = 0; j < n; j++) {
        long long x;
        cin >> x;
        b[i].push_back(x);
      }
    }
    long long l = 1, r = 1e9, ans = -1;
    while (l <= r) {
      long long mid = l + (r - l) / 2;
      vector<long long> vis(n + 1);
      long long check = 1, p = 0;
      for (long long i = 0; i < g; i++) {
        long long cnt = 0;
        for (long long j = 0; j < n; j++) {
          if (b[i][j] >= mid) {
            cnt++;
            vis[j + 1]++;
          }
        }
        if (cnt > 1) p = 1;
      }
      for (long long i = 1; i < n + 1; i++)
        if (!vis[i]) check = 0;
      if (check && p) {
        l = mid + 1;
        ans = mid;
      } else
        r = mid - 1;
    }
    cout << ans << "\n";
  }
  return 0;
}
