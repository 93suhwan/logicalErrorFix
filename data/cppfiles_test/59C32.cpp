#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<vector<long long>> a(n, vector<long long>(5));
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < 5; j++) {
        cin >> a[i][j];
      }
    }
    long long ok = 0;
    for (long long i = 0; i < 5; i++) {
      for (long long k = i + 1; k < 5; k++) {
        long long cnt = 0;
        vector<bool> vis(n, false);
        for (long long j = 0; j < n; j++) {
          if (a[j][i] == 1) {
            vis[j] = 1;
            cnt++;
          }
        }
        long long cnt2 = 0;
        for (long long j = 0; j < n; j++) {
          if (a[j][k] == 1) {
            vis[j] = 1;
            cnt2++;
          }
        }
        long long val = 0;
        if (cnt >= (n / 2) && cnt2 >= (n / 2)) {
          for (long long l = 0; l < n; l++) {
            if (vis[l]) {
              val++;
            }
          }
        }
        if (val == n) {
          ok = 1;
          cout << "YES" << endl;
          break;
        }
      }
      if (ok == 1) break;
    }
    if (ok == 0) {
      cout << "NO" << endl;
    }
  }
}
