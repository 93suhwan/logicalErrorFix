#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    long long n, lim;
    cin >> n >> lim;
    vector<long long> v(n);
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
      cin >> v[i];
      sum += v[i];
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    long long ans = max(0LL, sum - lim);
    if (ans == 0) {
      cout << 0 << "\n";
      continue;
    }
    long long preSum = v[n - 1];
    long long preSz = 1;
    for (int i = 0; i < (n - 1); i++) {
      preSum += v[i];
      preSz++;
      long long remain = sum - preSum;
      long long lo = ((sum - lim) / (preSz - 1)) * -1;
      long long hi = v[n - 1];
      long long target = 0;
      while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        if ((mid * preSz + remain) <= lim) {
          target = mid;
          lo = mid + 1;
        } else {
          hi = mid - 1;
        }
      }
      ans = min(ans, (v[n - 1] - target) + preSz - 1);
    }
    cout << ans << "\n";
  }
}
