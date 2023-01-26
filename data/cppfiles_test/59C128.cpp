#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long day[n][5];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < 5; j++) {
      cin >> day[i][j];
    }
  }
  for (long long i = 0; i < 4; i++) {
    for (long long j = i + 1; j < 5; j++) {
      long long a = 0, b = 0, c = 0, d = 0;
      for (long long k = 0; k < n; k++) {
        if (day[k][i] == 0 && day[k][j] == 1)
          a++;
        else if (day[k][i] == 1 && day[k][j] == 0)
          b++;
        else if (day[k][i] == 0 && day[k][j] == 0)
          c++;
        else if (day[k][i] == 1 && day[k][j] == 1)
          d++;
        if (c != 0) {
          break;
        }
      }
      if (a > n / 2 || b > n / 2 || c != 0) {
        continue;
      } else {
        cout << "YES" << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
}
int main() {
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
