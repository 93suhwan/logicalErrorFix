#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  int a[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (int b = 0; b < k; b++) {
    int x;
    cin >> x;
    int i = 0, j = x - 1;
    while (i < n) {
      if (a[i][j] == 1) {
        j++;
        a[i][j - 1] = 2;
      } else if (a[i][j] == 2) {
        i++;
        a[i - 1][j] = 2;
      } else {
        j--;
        a[i][j + 1] = 2;
      }
    }
    cout << j + 1 << ' ';
  }
  cout << '\n';
  return 0;
}
