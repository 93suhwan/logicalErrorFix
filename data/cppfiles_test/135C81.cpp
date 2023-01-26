#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long testcases = 1;
  cin >> testcases;
  while (testcases--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++) {
      cin >> v[i];
    }
    sort(v.begin(), v.end());
    long long ans = 0;
    long long it = n - k - 1;
    while (k) {
      ans += (v[it] / v.back());
      v.pop_back();
      it--;
      k--;
    }
    for (long long i = 0; i <= it; i++) {
      ans += v[i];
    }
    cout << ans << "\n";
  }
  return 0;
}
