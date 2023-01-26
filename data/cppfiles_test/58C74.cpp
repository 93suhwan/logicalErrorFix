#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    bool f = true;
    long long n;
    cin >> n;
    char a[2][n];
    for (long long i = 0; i < 2; i++) {
      for (long long j = 0; j < n; j++) {
        cin >> a[i][j];
      }
    }
    long long i = 0;
    for (long long j = 0; j < n; j++) {
      if (a[i][j] == '1' && a[i + 1][j] == '1') {
        f = false;
        break;
      }
    }
    if (f == true) {
      cout << "YES"
           << "\n";
    } else {
      cout << "NO"
           << "\n";
    }
  }
  return 0;
}
