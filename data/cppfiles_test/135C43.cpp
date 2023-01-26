#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> v;
    long long mini = INT_MAX;
    for (long long i = 0; i < n; i++) {
      long long x;
      cin >> x;
      v.push_back(x);
      mini = min(mini, x);
    }
    sort(v.begin(), v.end());
    long long ans = 0;
    for (long long i = n - 2 * k - 1; i >= 0; i--) {
      ans += v[i];
    }
    long long j = n - k;
    for (long long i = n - 2 * k; i < n - k; i++) {
      if (v[i] == v[j]) {
        ans++;
      }
      j++;
    }
    cout << ans << endl;
  }
  return 0;
}
