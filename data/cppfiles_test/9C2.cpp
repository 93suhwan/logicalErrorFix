#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, i, j;
  cin >> n >> m >> k;
  int a[n][m];
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  int x;
  for (i = 0; i < k; i++) {
    cin >> x;
    x--;
    int v = 0;
    while (v < n) {
      if (a[v][x] == 2) {
        v++;
      } else if (a[v][x] == 1) {
        a[v][x] = 2;
        x++;
      } else {
        a[v][x] = 2;
        x--;
      }
    }
    cout << x + 1 << " ";
  }
  cout << endl;
  return 0;
}
