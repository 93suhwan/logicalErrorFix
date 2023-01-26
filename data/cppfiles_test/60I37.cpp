#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  long long sum = 0;
  map<long long, long long> mp;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]]++;
    sum += a[i];
  }
  long long ans = 0;
  long long sum2 = (sum * (n - 2)) / n;
  if (sum2 * n != sum * (n - 2)) {
    cout << ans << endl;
    return;
  }
  sum2 = sum - sum2;
  for (long long i = 0; i < n; i++) {
    mp[a[i]]--;
    ans += mp[sum2 - a[i]];
  }
  cout << ans << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
