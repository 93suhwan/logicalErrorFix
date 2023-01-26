#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, s = 0;
    cin >> n;
    long long int a[n][5];
    for (long long int i = 0; i < n; i++) {
      for (long long int j = 0; j < 5; j++) cin >> a[i][j];
    }
    for (long long int i = 0; i < 5; i++) {
      for (long long int j = i + 1; j < 5; j++) {
        long long int one = 0, two = 0, both = 0;
        for (long long int k = 0; k < n; k++) {
          if (a[k][i]) one++;
          if (a[k][j]) two++;
          if (a[k][i] && a[k][j]) both++;
        }
        if (one >= n / 2 && two >= n / 2 && one + two - both == n) s = 1;
      }
    }
    if (s == 1)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
