#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y) { return (y == 0 ? x : gcd(y, x % y)); }
long long lcm(long long x, long long y) { return (x / gcd(x, y)) * y; }
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n;
  cin >> n;
  long long arr[n];
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  stack<pair<long long, long long>> ss;
  ss.push({0, 0});
  long long level = 0;
  long long ans = 0;
  long long num = 0;
  long long xx = 0, yy;
  for (long long i = 0; i < n - 1; i += 2) {
    long long a = arr[i];
    long long b = arr[i + 1];
    ans += min(max(b - a, 0ll), xx);
    xx += max(a - b, 0ll);
    level += a - b;
    ans += min(a, b);
    while ((!ss.empty()) && ss.top().first > level) {
      ans += ss.top().second;
      ss.pop();
    }
    if ((!ss.empty()) && ss.top().first == level) {
      ans += (ss.top().second);
      ss.top().second++;
    } else {
      if (ss.empty()) {
        xx = max(a - b, 0ll);
        ss.push({level, 0});
      } else {
        ss.push({level, 1});
      }
    }
  }
  cout << ans << '\n';
}
