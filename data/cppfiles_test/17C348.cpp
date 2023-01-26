#include <bits/stdc++.h>
using namespace std;
long long n, r[50005][6];
int main() {
  long long t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < 5; j++) {
        cin >> r[i][j];
      }
    }
    long long ans = 0, x;
    for (long long i = 1; i < n; i++) {
      x = 0;
      for (long long j = 0; j < 5; j++) {
        if (r[i][j] < r[ans][j]) x++;
      }
      if (x > 2) ans = i;
    }
    for (long long i = 0; i < n; i++) {
      x = 0;
      if (i == ans) continue;
      for (long long j = 0; j < 5; j++) {
        if (r[i][j] < r[ans][j]) x++;
      }
      if (x > 2) {
        ans = -2;
        break;
      }
    }
    cout << ans + 1 << endl;
  }
  return 0;
}
