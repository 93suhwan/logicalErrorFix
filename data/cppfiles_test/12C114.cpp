#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    int cnt = (m / 2) * n;
    if (cnt < k) {
      cout << "NO" << endl;
      continue;
    }
    if (m == 1 && k >= 1) {
      cout << "NO" << endl;
      continue;
    }
    if (n % 2 == 0 && m % 2 == 0) {
      if (k % 2 == 0)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    } else if (n % 2 == 0) {
      if (k % 2 == 1) {
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
      }
    } else if (m % 2 == 0) {
      k = k - (m / 2);
      if (k % 2 == 1 || k < 0) {
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
      }
    }
  }
}
