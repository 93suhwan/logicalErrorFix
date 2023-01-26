#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long arr[n];
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  long long target = 2 * sum / n;
  if ((sum - target) * n != sum * (n - 2)) {
    cout << 0 << '\n';
    return;
  }
  map<long long, long long> mp;
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    ans += mp[target - arr[i]];
    mp[arr[i]]++;
  }
  cout << ans << '\n';
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
}
