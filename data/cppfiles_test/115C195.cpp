#include <bits/stdc++.h>
using namespace std;
long long count(long long k, long long n, vector<long long> v) {
  long long sum = 0;
  for (long long i = 1; i < n; i++) {
    sum += min(k, (v[i] - v[i - 1]));
  }
  sum += k;
  return sum;
}
void solve() {
  long long n, h;
  cin >> n >> h;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) cin >> v[i];
  if (n >= h) {
    cout << 1 << ("\n");
    return;
  } else {
    long long l = 1, r = h;
    long long mid = (l + r) / 2;
    long long ans = 0;
    while (l <= r) {
      mid = (l + r) / 2;
      long long t1 = count(mid, n, v);
      if (t1 >= h) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    cout << ans << ("\n");
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long testcase;
  cin >> testcase;
  while (testcase--) {
    solve();
  }
  return 0;
}
