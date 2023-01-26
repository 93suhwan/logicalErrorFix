#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> v(n);
    for (auto &i : v) cin >> i;
    sort((v).begin(), (v).end());
    long long ans = 0;
    for (long long i = 0; i < n - 2 * k; i++) ans += v[i];
    long long i = n - 2 * k + k - 1, j = n - 1;
    while (k--) {
      ans += v[i] / v[j];
      i--;
      j--;
    }
    cout << ans << '\n';
  }
  return 0;
}
