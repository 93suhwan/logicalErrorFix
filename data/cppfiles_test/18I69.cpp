#include <bits/stdc++.h>
using namespace std;
void solve(long long tc) {
  long long n;
  cin >> n;
  long long d;
  cin >> d;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long ans = 0;
  bool all = true;
  bool all2 = true;
  for (long long i = 0; i < n; i++) {
    if (a[i] == 0) all = false;
    if (a[i] == 1) all = false;
  }
  if (all2) {
    cout << 0 << "\n";
    return;
  }
  if (all) {
    cout << -1 << "\n";
    return;
  }
  if (d > 1) {
    for (long long i = 0; i < n; i++) {
      if (a[i] == 1) {
        long long idx = (i + d) % n;
        long long cnt = 0;
        while (idx != i) {
          cnt++;
          if (a[idx] == 0) {
            break;
          }
          if (cnt == n) {
            cout << -1 << "\n";
            return;
          }
          idx = (idx + d) % n;
        }
        if (idx == i) {
          cout << -1 << "\n";
          return;
        }
        ans = max(ans, cnt);
      }
    }
    cout << ans << "\n";
  } else {
    long long cnt = 0;
    long long total = 0;
    for (long long i = 0; i < n; i++) {
      if (a[i] == 1) {
        cnt++;
        total = max(total, cnt);
      } else {
        cnt = 0;
      }
    }
    cout << total - 1 << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long x;
  cin >> x;
  for (long long tc = 1; tc <= x; tc++) {
    solve(tc);
  }
  return 0;
}
