#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
  return a.second < b.second;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
    }
    bool flag = true;
    long long ans = 0;
    sort(arr, arr + n);
    for (long long i = 0; i < n; i++) {
      long long cur = arr[i];
      long long make = i + 1;
      if (make == cur) continue;
      long long x = cur - make;
      if (x < 1 || cur % x != make) {
        ans = -1;
        break;
      }
      ans++;
    }
    cout << ans << "\n";
  }
}
