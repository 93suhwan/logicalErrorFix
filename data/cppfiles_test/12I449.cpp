#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, m, k;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> n >> m >> k;
    if (n % 2 == 0) {
      cout << (k % 2 == 0 ? "YES" : "NO") << endl;
    } else {
      if (k < m / 2) {
        cout << "NO" << endl;
      } else {
        k -= m / 2;
        cout << (k % 2 == 0 ? "YES" : "NO") << endl;
      }
    }
  }
  return 0;
}
