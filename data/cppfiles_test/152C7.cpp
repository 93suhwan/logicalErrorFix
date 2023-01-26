#include <bits/stdc++.h>
using namespace std;
long long p[(1000000 + 1)], a[(1000000 + 1)], dp[(1000000 + 1)][2],
    pr[(1000000 + 1)][2];
void solve() {
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> p[i];
    for (long long sign = 0; sign < 2; sign++) {
      dp[i][sign] = LONG_MAX;
    }
  }
  dp[0][0] = LONG_MIN;
  dp[0][1] = LONG_MIN;
  for (long long i = 0; i < n - 1; i++) {
    for (long long sign = 0; sign < 2; sign++) {
      long long x = sign ? -p[i] : p[i];
      long long y = dp[i][sign];
      if (x < y) swap(x, y);
      for (long long new_sign = 0; new_sign < 2; new_sign++) {
        long long z = new_sign ? -p[i + 1] : p[i + 1];
        if (z > x) {
          if (dp[i + 1][new_sign] > y) {
            dp[i + 1][new_sign] = y;
            pr[i + 1][new_sign] = sign;
          }
        } else if (z > y) {
          if (dp[i + 1][new_sign] > x) {
            dp[i + 1][new_sign] = x;
            pr[i + 1][new_sign] = sign;
          }
        }
      }
    }
  }
  long long sign = -1;
  for (long long new_sign = 0; new_sign < 2; new_sign++) {
    if (dp[n - 1][new_sign] != LONG_MAX) {
      sign = new_sign;
    }
  }
  if (sign == -1) {
    cout << "NO" << endl;
    return;
  } else {
    cout << "YES" << endl;
  }
  for (long long i = n - 1; i >= 0; i--) {
    a[i] = sign ? -p[i] : p[i];
    sign = pr[i][sign];
  }
  for (long long i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
