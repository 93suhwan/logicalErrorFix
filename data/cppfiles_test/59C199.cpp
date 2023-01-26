#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n][5];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        cin >> a[i][j];
      }
    }
    int f = 0;
    for (int i = 0; i < 5; i++) {
      for (int j = i + 1; j < 5; j++) {
        int count = 0, cnt = 0, pnt = 0;
        for (int k = 0; k < n; k++) {
          if (a[k][i] == 1 || a[k][j] == 1) count++;
          if (a[k][i] == 1) cnt++;
          if (a[k][j] == 1) pnt++;
        }
        if (count == n && cnt >= n / 2 && pnt >= n / 2) {
          cout << "YES" << endl;
          f = 1;
          break;
        }
      }
      if (f) break;
    }
    if (!f) cout << "NO" << endl;
  }
  return 0;
}
