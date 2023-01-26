#include <bits/stdc++.h>
const long long mod = 1000000007;
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long test;
  cin >> test;
  while (test--) {
    long long n;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
    }
    long long x = 0;
    long long ans1 = 0;
    long long ans2 = 0;
    long long y = 1;
    long long o = 0;
    long long e = 0;
    bool exist = true;
    for (long long i = 0; i < n; i++) {
      if (arr[i] % 2 == 0) {
        e++;
      } else {
        o++;
      }
    }
    if (abs(o - e) > 1) {
      exist = false;
      cout << -1 << "\n";
      ;
    }
    if (exist == true) {
      for (long long i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
          ans2 += abs(i - y);
          y += 2;
        }
      }
      for (long long i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
          ans1 += abs(i - x);
          x += 2;
        }
      }
      if (o == e) {
        cout << min(ans1, ans2) << "\n";
        ;
      } else if (o < e) {
        cout << ans1 << "\n";
        ;
      } else {
        cout << ans2 << "\n";
        ;
      }
    }
  }
  return 0;
}
