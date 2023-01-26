#include <bits/stdc++.h>
using namespace std;
using intll = long long int;
void solve() {
  int n;
  cin >> n;
  int a[n][5];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) cin >> a[i][j];
  }
  for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 5; j++) {
      int x = 0, y = 0, z = 0;
      for (int k = 0; k < n; k++) {
        if (a[k][i] == 1) x++;
        if (a[k][j] == 1) y++;
        if (a[k][j] == 1 && a[k][i] == 1) z++;
      }
      x -= z;
      y -= z;
      if (x <= n / 2 && y <= n / 2 && x + y + z == n) {
        cout << "YES" << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
}
int main() {
  intll t;
  cin >> t;
  while (t--) {
    solve();
  }
}
