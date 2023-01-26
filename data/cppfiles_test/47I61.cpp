#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> v(n);
    for (long long &i : v) {
      cin >> i;
    }
    sort(v.begin(), v.end());
    long long count = n;
    long long ans = 0;
    for (long long i = 0; i < n && count > 0; i += k) {
      if (v[i] >= 0) break;
      count -= k;
      ans += abs(v[i] * 2);
    }
    for (long long i = n - 1; i >= 0 && count > 0; i -= k) {
      count -= k;
      ans += abs(v[i] * 2);
    }
    if (abs(v[0]) > abs(v[n - 1])) {
      for (long long i = n - 1; i >= 0 && count > 0; i -= k) {
        count -= k;
        if (v[i] > 0 && v[max(i - k + 1, 0LL)] < 0)
          ans += abs(v[i - k + 1]) * 2 + abs(v[i]) * 2;
        else
          ans += abs(v[i] * 2);
      }
    } else {
      for (long long i = 0; i < n && count > 0; i += k) {
        count -= k;
        if (v[i] < 0 && v[min(i + k - 1, n - 1)] < 0)
          ans += abs(v[i - k + 1]) * 2 + abs(v[i]) * 2;
        else
          ans += abs(v[i] * 2);
      }
    }
    cout << ans - max(abs(v[0]), abs(v[n - 1])) << endl;
  }
  return 0;
}
