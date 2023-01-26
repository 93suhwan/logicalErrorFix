#include <bits/stdc++.h>
using namespace std;
void go(int testcase) {
  int n, k;
  cin >> n >> k;
  int a[n + 1];
  for (int i = 1; i < n + 1; i++) cin >> a[i];
  int d[n + 1][n + 1];
  memset(d, 0, sizeof d);
  for (int i = 1; i < n + 1; i++) {
    if (i > 1) {
      for (int j = 0; j < n; j++) {
        d[i][j + 1] = d[i - 1][j];
      }
    } else {
      d[1][1] = 0;
    }
    if (i > 1) {
      for (int j = 0; j < n + 1; j++) {
        d[i][j] = max(d[i - 1][j], d[i][j]);
      }
    }
    if (a[i] <= i) {
      if (i > 1)
        d[i][i - a[i]] = max(d[i - 1][i - a[i]] + 1, d[i][i - a[i]]);
      else
        d[i][0] = 1;
    } else if (i > 1) {
      for (int j = 0; j < n + 1; j++) {
        d[i][j] = max(d[i - 1][j], d[i][j]);
      }
    } else {
      for (int j = 0; j < n + 1; j++) {
        d[1][j] = 0;
      }
    }
  }
  for (int j = 0; j < n + 1; j++) {
    if (d[n][j] >= k) {
      cout << j << '\n';
      return;
    }
  }
  cout << "-1\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) go(i);
  return 0;
}
