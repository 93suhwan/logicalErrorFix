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
  if (sum % n == 0) {
    long long mean = sum / n;
    long long target = mean * 2;
    map<long long, long long> mp;
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
      long long comp = target - arr[i];
      if (mp.find(comp) != mp.end()) {
        ans += mp[comp];
      }
      mp[arr[i]]++;
    }
    cout << ans << '\n';
  } else {
    cout << 0 << '\n';
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
}
