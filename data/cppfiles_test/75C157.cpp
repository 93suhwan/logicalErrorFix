#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  long long t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<pair<long long, long long>> pow(n);
    for (long long i = 0; i < n; i++) {
      long long k;
      cin >> k;
      long long p = 0;
      for (long long j = 0; j < k; j++) {
        long long temp;
        cin >> temp;
        p = max(p, temp - j + 1);
      }
      pow[i] = {p, k};
    }
    sort(pow.begin(), pow.end());
    vector<long long> prefixSum(n);
    prefixSum[0] = 0;
    for (long long i = 0; i < n - 1; i++) {
      long long num = pow[i].second;
      prefixSum[i + 1] = num + prefixSum[i];
    }
    long long ans = 1;
    for (long long i = n - 1; i >= 0; i--) {
      long long p = pow[i].first;
      ans = max(ans, p - prefixSum[i]);
    }
    cout << ans << '\n';
  }
  return 0;
}
