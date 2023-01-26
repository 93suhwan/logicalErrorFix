#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int a = n * m;
  int b = (n * m) / 2;
  if (n % 2 == 0) {
    while (k) {
      if (k >= n) {
        m = m - 2;
        b = b - (n);
        k = k - n;
      } else {
        int c = m - 2;
        m = m - 2;
        b = b - k;
        b -= ((n / 2) * c - k);
        k = 0;
      }
    }
    if (b > (n / 2) * m) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  } else {
    while (k) {
      if (k > m / 2) {
        n = n - 1;
        b = b - m / 2;
        k = k - m / 2;
      } else {
        n = n - 1;
        b = b - k;
        int c = m - 2 * k;
        b = b - (c / 2);
        k = 0;
      }
    }
    if (b > (n / 2) * m) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
