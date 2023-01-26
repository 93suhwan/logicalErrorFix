#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    int i = 0;
    while (k--) {
      int j = i;
      for (int h = 0; h < m; h++) {
        int x = h < n % m ? n / m + 1 : n / m;
        cout << x;
        while (x--) {
          cout << ' ' << ++j;
          j %= n;
        }
        if (h < n % m) i = j;
        cout << '\n';
      }
    }
  }
  return 0;
}
