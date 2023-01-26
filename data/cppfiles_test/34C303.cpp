#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++) cin >> v[i];
    long long idx = max(0ll, n - 300ll);
    long long ans = LONG_MIN;
    for (long long i = idx; i < n; i++) {
      for (long long j = i + 1; j < n; j++) {
        ans = max(ans, ((i + 1) * (j + 1) - k * (v[i] | v[j])));
      }
    }
    cout << ans << endl;
  }
  return 0;
}
