#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long sum = 0;
  long long a[n + 1];
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  long long req = 2 * sum / n;
  map<long long, long long> cnt;
  long long ans = 0;
  if ((sum - req) * n != sum * (n - 2)) {
    cout << 0 << '\n';
    return;
  }
  for (long long i = 1; i <= n; i++) {
    ans += cnt[req - a[i]];
    cnt[a[i]]++;
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
