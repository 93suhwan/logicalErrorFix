#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    long long int a[2000], b[2000];
    long long int c[2000];
    long long int ans[2000];
    cin >> n;
    for (long long int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
    }
    for (long long int i = 0; i < 2000; i++) {
      c[i] = 1;
      ans[i] = 0;
    }
    long long int z = 1;
    while (z) {
      z = 0;
      for (long long int i = 0; i < n; i++) {
        if (ans[i] == 0) {
          z = 1;
        }
      }
      for (long long int i = n - 1; i >= 0; i--) {
        long long int ans_num = 0;
        long long int p;
        for (long long int j = a[i]; j <= b[i]; j++) {
          if (c[j]) {
            ans_num++;
            if (ans_num > 1) {
              break;
            }
            p = j;
          }
        }
        if (ans_num == 1) {
          ans[i] = p;
          c[p] = 0;
        }
      }
    }
    for (long long int i = 0; i < n; i++) {
      cout << a[i] << ' ' << b[i] << ' ' << ans[i] << '\n';
    }
    cout << '\n';
  }
  return 0;
}
