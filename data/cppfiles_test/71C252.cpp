#include <bits/stdc++.h>
using namespace std;
const long long N = 1000000007;
vector<long long> v, y;
void solve() {
  for (long long i = 1; i <= 9; i++) {
    for (long long l = 1; l <= 10; l++) {
      long long t = 0;
      for (long long k = 0; k < l; k++) {
        t = t * 10 + i;
      }
      y.push_back(t);
    }
  }
  for (long long i = 0; i <= 9; i++) {
    for (long long j = i + 1; j <= 9; j++) {
      for (long long l = 1; l <= 10; l++) {
        for (long long mask = 0; mask < (1 << l); mask++) {
          long long num = 0;
          for (long long k = 0; k < l; k++) {
            bool y = ((1 << k) & mask);
            if (y) {
              num = num * 10 + i;
            } else {
              num = num * 10 + j;
            }
          }
          v.push_back(num);
        }
      }
    }
  }
  sort(y.begin(), y.end());
  sort(v.begin(), v.end());
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  solve();
  while (t--) {
    long long n, k;
    cin >> n >> k;
    if (k == 1) {
      long long l = 0, r = y.size() - 1, mid = 0;
      while (l < r) {
        mid = l + (r - l) / 2;
        if (y[mid] < n) {
          l = mid + 1;
        } else {
          r = mid;
        }
      }
      cout << y[l] << "\n";
    } else {
      long long l = 0, r = v.size() - 1, mid = 0;
      while (l < r) {
        mid = l + (r - l) / 2;
        if (v[mid] < n) {
          l = mid + 1;
        } else {
          r = mid;
        }
      }
      cout << v[l] << "\n";
    }
  }
  return 0;
}
