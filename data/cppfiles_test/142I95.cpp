#include <bits/stdc++.h>
using namespace std;
const long double PI = acos(-1);
const long long mod = 1e9 + 7;
void solve_test() {
  long long m, n;
  cin >> m >> n;
  long long a[m][n];
  for (long long i = 0; i < m; i++) {
    for (long long j = 0; j < n; j++) {
      cin >> a[i][j];
    }
    sort(a[i], a[i] + n);
  }
  long long l = 0, r = 1e10, ans = 0;
  while (l <= r) {
    long long mid = l + (r - l) / 2;
    vector<long long> v;
    for (long long i = 0; i < m; i++) {
      long long x = lower_bound(a[i], a[i] + n, mid) - a[i];
      v.push_back(n - x);
    }
    sort((v).begin(), (v).end());
    reverse((v).begin(), (v).end());
    long long sum = 0;
    for (long long i = 0; i < min(n - 1, m); i++) sum += v[i];
    bool ok = (sum >= n);
    if (ok) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve_test();
  }
  return 0;
}
