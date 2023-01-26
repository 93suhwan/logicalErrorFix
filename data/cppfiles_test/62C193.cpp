#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long tt = 1;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (a[0] == 1) {
      cout << n + 1 << " ";
      for (long long i = 1; i <= n; i++) {
        cout << i << " ";
      }
      cout << '\n';
    } else {
      long long j;
      for (j = 0; j < n; j++) {
        if (a[j] == 1) break;
      }
      if (j == n) {
        for (long long i = 1; i <= n; i++) {
          cout << i << " ";
        }
        cout << n + 1 << '\n';
      } else {
        for (long long i = 1; i <= j; i++) {
          cout << i << " ";
        }
        cout << n + 1 << " ";
        for (long long i = j + 1; i <= n; i++) {
          cout << i << " ";
        }
        cout << '\n';
      }
    }
  }
  return 0;
}
