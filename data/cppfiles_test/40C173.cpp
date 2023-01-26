#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    long long a[2][n], fr = 0, m, x = 0, b = 0, c = 0;
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < n; j++) {
        cin >> a[i][j];
        if (i == 0) fr += a[i][j];
      }
    for (int i = 0; i < n; i++) {
      fr -= a[0][i];
      if (i > 0) x += a[1][i - 1];
      if (i == 0 || m > max(fr, x)) m = max(fr, x);
    }
    cout << m << endl;
  }
  return 0;
}
