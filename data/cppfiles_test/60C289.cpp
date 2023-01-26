#include <bits/stdc++.h>
using namespace std;
void init_code() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> a(n);
  long long int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sum *= 2;
  if (sum % n) {
    cout << 0 << '\n';
  } else {
    sum /= n;
    map<long long int, long long int> mp;
    long long int ans = 0;
    for (int i = 0; i < n; i++) {
      ans += mp[sum - a[i]];
      mp[a[i]]++;
    }
    cout << ans << '\n';
  }
}
signed main() {
  init_code();
  long long int t;
  cin >> t;
  while (t--) solve();
}
