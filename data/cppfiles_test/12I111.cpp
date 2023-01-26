#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int a = n * m;
  int b = (n * m) / 2;
  while (k) {
    if (k <= n) {
      b = b - k;
      int c = m - 2;
      m = m - 2;
      b = b - ((n / 2) * c);
      k = 0;
    } else {
      b = b - k;
      m = m - 2;
      k = k - n;
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
