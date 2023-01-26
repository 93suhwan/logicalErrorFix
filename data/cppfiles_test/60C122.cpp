#include <bits/stdc++.h>
using namespace std;
constexpr size_t MAXN = 2e5 + 5;
long long a[MAXN];
inline long long GCD(long long a, long long b) {
  return !b ? a : GCD(b, a % b);
}
inline void Solve() {
  long long n;
  cin >> n;
  long long sum = 0;
  for (long long i = 1; i <= n; i++) cin >> a[i], sum += a[i];
  long long g = GCD(sum, n);
  if (n / g > 2) {
    cout << "0\n";
    return;
  }
  sum /= g;
  if (n / g == 1) sum <<= 1;
  map<long long, long long> mp;
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    ans += mp[sum - a[i]];
    mp[a[i]]++;
  }
  cout << ans << '\n';
}
signed main(void) {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t;
  cin >> t;
  while (t--) Solve();
}
