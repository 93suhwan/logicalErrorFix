#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, m, k;
  cin >> n >> m >> k;
  long long int a[n][m];
  long long int res[n][m];
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  long long int c[k];
  for (long long int i = 0; i < k; i++) {
    cin >> c[i];
  }
  for (long long int i = 0; i < k; i++) {
    long long int x = 0, y = c[i] - 1;
    while (x < n) {
      if (a[x][y] == 1) {
        y++;
        a[x][y - 1] = 2;
        continue;
      }
      if (a[x][y] == 2) {
        x++;
        continue;
      }
      if (a[x][y] == 3) {
        y--;
        a[x][y + 1] = 2;
        continue;
      }
    }
    cout << y + 1 << " ";
  }
  cout << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
}
