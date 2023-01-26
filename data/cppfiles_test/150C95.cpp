#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    int Max = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      Max = max(Max, a[i] / 3);
    }
    long long ans = INT_MAX;
    for (long long i = 0; i <= 2; i++) {
      for (long long j = 0; j <= 2; j++) {
        long long res = 0;
        for (long long k = 0; k < n; k++) {
          long long num = INT_MAX;
          for (long long x = 0; x <= i; x++) {
            for (long long y = 0; y <= j; y++) {
              long long left = a[k] - x - 2 * y;
              if (left >= 0 && left % 3 == 0) {
                num = min(num, left / 3);
              }
            }
          }
          res = max(res, num);
        }
        ans = min(ans, res + i + j);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
