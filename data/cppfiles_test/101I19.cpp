#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    int z = 1;
    cin >> n;
    int a[n + 5], b[n * 2 + 5];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      b[i + 1] = 0;
    }
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'B') {
        int j = 1;
        while (b[j] && j <= a[i]) {
          j++;
        }
        b[j] = 1;
        if (j > n) {
          z = 0;
          break;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (s[i] == 'B') continue;
      if (a[i] > n) {
        z = 0;
        break;
      }
      int j = a[i];
      if (j < 1) j = 1;
      while (b[j] && j <= n) {
        j++;
      }
      b[j] = 1;
      if (j > n) {
        z = 0;
        break;
      }
    }
    if (z)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
