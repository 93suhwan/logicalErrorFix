#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int a[n], b[n];
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    long long sum = 0;
    int d[n];
    for (int i = 0; i < n; i++) sum += a[i] - b[i];
    sum -= ((long long)n) * m;
    int mn[n];
    for (int i = 0; i < n; i++) {
      int mx;
      mn[i] = max(0, m - a[i]);
      mx = min(b[i], m);
      d[i] = mx - mn[i];
      sum += 2 * mn[i];
    }
    if (sum >= 0) {
      cout << sum << "\n";
      for (int i = 0; i < n; i++) cout << m - mn[i] << " " << mn[i] << "\n";
    } else {
      long long x = 0;
      for (int i = 0; i < n; i++) x += 2 * d[i];
      if (x + sum >= 0) {
        if (sum % 2 == 0)
          cout << "0\n";
        else
          cout << "1\n";
        x = (-sum) / 2;
        for (int i = 0; i < n; i++) {
          long long temp = min(x, (long long)d[i]);
          cout << m - (temp + mn[i]) << " " << temp + mn[i] << "\n";
          x -= temp;
        }
      } else {
        cout << abs(x + sum) << "\n";
        for (int i = 0; i < n; i++) {
          int temp = mn[i] + d[i];
          cout << m - temp << " " << temp << "\n";
        }
      }
    }
  }
}
