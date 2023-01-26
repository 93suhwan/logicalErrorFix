#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long T;
  cin >> T;
  while (T--) {
    map<long long, long long> mp;
    long long n, k, score = 0;
    cin >> n >> k;
    vector<long long> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    long long ans = 0;
    for (long long i = 0; i < k; i++) ans += a[i + k] / a[i];
    for (long long i = 2 * k; i < n; i++) ans += a[i];
    cout << ans << "\n";
  }
  return 0;
}
