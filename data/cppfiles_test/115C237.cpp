#include <bits/stdc++.h>
using namespace std;
void c_p_c() {}
bool check(long long mid, vector<long long> a, long long n, long long h) {
  long long i;
  long long sum = 0;
  for (i = 0; i < n - 1; i++) {
    if (a[i] + mid - 1 >= a[i + 1]) {
      sum += a[i + 1] - a[i];
    } else {
      sum += mid;
    }
  }
  sum += mid;
  return sum >= h;
}
void solve() {
  long long n, h;
  cin >> n >> h;
  vector<long long> a(n);
  long long i;
  for (i = 0; i < n; i++) cin >> a[i];
  long long low = 0;
  long long high = 1e18;
  long long ans = 0;
  while (low <= high) {
    long long mid = (low + high) / 2;
    if (check(mid, a, n, h)) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  cout << ans << endl;
}
int32_t main() {
  c_p_c();
  long long t = 1;
  cin >> t;
  while (t--) solve();
}
