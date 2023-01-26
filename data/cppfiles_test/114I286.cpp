#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long ans = 0;
    sort(a, a + n);
    vector<pair<long long, long long>> v;
    for (long long i = 1; i < n; i++) {
      if (ans == (n / 2)) {
        break;
      }
      if (a[i] != a[i - 1]) {
        long long r = a[i] % a[i - 1];
        long long low = 0;
        long long hi = i - 1;
        while ((hi - low) > 1) {
          long long mid = (low + hi) / 2;
          if (a[mid] <= r) {
            low = mid;
          } else {
            hi = mid - 1;
          }
        }
        if (a[low] != r && a[hi] != r) {
          ans++;
          v.push_back(make_pair(a[i], a[i - 1]));
        }
      }
    }
    for (long long i = 0; i < v.size(); i++) {
      cout << v[i].first << " " << v[i].second << endl;
    }
  }
  return 0;
}
