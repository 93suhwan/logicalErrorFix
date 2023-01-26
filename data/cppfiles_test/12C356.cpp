#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k, g;
    cin >> n >> m >> k;
    g = n * m / 2 - k;
    if (n % 2 == 0 && m % 2 == 0) {
      if (k % 2 == 0 && g % 2 == 0) {
        cout << "YES\n" << endl;
      } else {
        cout << "NO\n" << endl;
      }
    } else if (n % 2 == 0) {
      if (g >= n / 2) {
        g = g - n / 2;
        m--;
        if (g % 2 == 0 && k % 2 == 0) {
          cout << "YES\n" << endl;
        } else
          cout << "NO\n" << endl;
      } else {
        cout << "NO\n" << endl;
      }
    } else {
      if (k >= m / 2) {
        k = k - m / 2;
        n--;
        if (g % 2 == 0 && k % 2 == 0) {
          cout << "YES\n" << endl;
        } else
          cout << "NO\n" << endl;
      } else {
        cout << "NO\n" << endl;
      }
    }
  }
  return 0;
}
