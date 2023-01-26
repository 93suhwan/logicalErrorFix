#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    if (n % 2 == 1 and m % 2 == 0) {
      int q = m / 2;
      if (k < q) {
        cout << "NO" << '\n';
      } else {
        int d = k - q;
        if (d % 2 == 0) {
          cout << "YES" << '\n';
        } else {
          cout << "NO" << '\n';
        }
      }
    } else if (n % 2 == 0 and m % 2 == 1) {
      int q = n / 2;
      k = n * m / 2 - k;
      if (k < q) {
        cout << "NO" << '\n';
      } else {
        int d = k - q;
        if (d % 2 == 0) {
          cout << "YES" << '\n';
        } else {
          cout << "NO" << '\n';
        }
      }
    } else {
      if (k % 2 == 0)
        cout << "YES" << '\n';
      else
        cout << "NO" << '\n';
    }
  }
  return 0;
}
