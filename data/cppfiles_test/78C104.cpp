#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[35];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int j = 0; j < 32; j++) a[j] = 0;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      for (int j = 0; j < 32; j++) {
        a[j] += (x >> j) & 1;
      }
    }
    for (int i = 1; i <= n; i++) {
      bool p = 1;
      for (int j = 0; j < 32; j++)
        if (a[j] % i != 0) {
          p = 0;
          break;
        }
      if (p) cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}
