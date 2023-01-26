#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
void solve() {
  long long m, n;
  cin >> m >> n;
  long long arr[m][n];
  long long mn = 1e9, mx = 1;
  for (long long i = 0; i < m; i++) {
    for (long long j = 0; j < n; j++) {
      cin >> arr[i][j];
      mn = min(mn, arr[i][j]);
      mx = max(mx, arr[i][j]);
    }
  }
  long long ans = mn;
  while (mn <= mx) {
    long long mid = mn + (mx - mn) / 2;
    int flag1 = 0;
    int flag2 = 0;
    vector<long long> v(n, 0);
    for (long long i = 0; i < m; i++) {
      for (long long j = 0; j < n; j++) {
        v[j] = max(v[j], arr[i][j]);
      }
    }
    for (long long i = 0; i < n; i++) {
      if (v[i] < mid) {
        flag1 = 1;
        break;
      }
    }
    if (flag1) {
      mx = mid - 1;
      continue;
    }
    for (long long i = 0; i < m; i++) {
      long long cnt = 0;
      for (long long j = 0; j < n; j++) {
        if (arr[i][j] >= mid) cnt++;
      }
      if (cnt > 1) {
        flag2 = 1;
        break;
      }
    }
    if (flag2) {
      ans = mid;
      mn = mid + 1;
    } else
      mx = mid - 1;
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
