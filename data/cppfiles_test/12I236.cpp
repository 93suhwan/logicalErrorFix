#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int a = n * m;
  int b = (n * m) / 2;
  while (k) {
    if (n % 2 == 0) {
      if (k <= n) {
        b = b - k;
        int d = n - k;
        int c = min(m, 2);
        m = m - 2;
        b = b - ((d / 2) * c);
        k = 0;
      } else {
        b = b - k;
        m = m - 2;
        k = k - n;
      }
    } else {
      if (k <= m / 2) {
        b = b - k;
        n = n - 1;
        k = 0;
      } else {
        b -= (k - m / 2);
        k = k - m / 2;
        n = n - 1;
      }
    }
  }
  if (b > (m * (n / 2))) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
