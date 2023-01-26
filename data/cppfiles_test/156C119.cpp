#include <bits/stdc++.h>
using namespace std;
const long long mxn = 2e5 + 10;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> arr(n);
    long long sm = 0;
    for (auto &u : arr) {
      cin >> u;
      sm += u;
    }
    if (sm <= k) {
      cout << "0\n";
      continue;
    }
    sort(arr.begin(), arr.end());
    vector<long long> pre(n + 1, 0);
    for (long long i = 0; i < n; i++) {
      pre[i + 1] = pre[i] + arr[i];
    }
    long long ans = (long long)9e18;
    for (long long i = 0; i < n; i++) {
      long long sm = pre[n - i] + arr[0] * i;
      long long tot = i;
      if (sm > k) {
        long long df = sm - k;
        tot += (df + i) / (i + 1);
      }
      ans = min(ans, tot);
    }
    cout << ans << "\n";
  }
  return 0;
}
