#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int32_t main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t;
  t = 1;
  cin >> t;
  for (long long tc = 0; tc < t; tc++) {
    long long n;
    cin >> n;
    long long available[n][5];
    for (long long i1 = 0; i1 < n; i1++) {
      for (long long j1 = 0; j1 < 5; j1++) cin >> available[i1][j1];
    }
    bool vis[n];
    memset(vis, false, sizeof(vis));
    long long sz1 = 0, sz2 = 0, cnt = 0;
    bool can = false;
    for (long long day1 = 0; day1 < 5; day1++) {
      for (long long day2 = day1 + 1; day2 < 5; day2++) {
        memset(vis, false, sizeof(vis));
        cnt = 0, sz1 = 0, sz2 = 0;
        for (long long i = 0; i < n; i++) {
          sz1 += available[i][day1];
          if (available[i][day1]) {
            vis[i] = true;
          }
        }
        for (long long i = 0; i < n; i++) {
          sz2 += available[i][day2];
          if (available[i][day2]) {
            vis[i] = true;
          }
        }
        for (long long i = 0; i < n; i++) cnt += (vis[i]);
        if (sz1 >= n / 2 && sz2 >= n / 2 && cnt == n) {
          can = true;
          break;
        }
      }
      if (can) break;
    }
    cout << (can ? "YES" : "NO") << "\n";
  }
  return 0;
}
