#include <bits/stdc++.h>
using namespace std;
string solve() {
  long long n;
  cin >> n;
  long long a[n][5];
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < 5; j++) {
      cin >> a[i][j];
    }
  for (long long i = 0; i < 5; i++)
    for (long long j = i + 1; j < 5; j++) {
      long long counta = 0, countb = 0, both = 0;
      for (long long k = 0; k < n; k++) {
        if (a[k][i] == 1 && a[k][j] == 0)
          counta++;
        else if (a[k][i] == 0 && a[k][j] == 1)
          countb++;
        else if (a[k][i] == 1 && a[k][j] == 1)
          both++;
      }
      if (counta >= n / 2 && countb >= n / 2) return "YES";
      if (counta > n / 2 || countb > n / 2) continue;
      both = both - (n / 2 - counta);
      if (both < 0) continue;
      if (countb + both >= n / 2) return "YES";
    }
  return "NO";
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) cout << solve() << "\n";
}
