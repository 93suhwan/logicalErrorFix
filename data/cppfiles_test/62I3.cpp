#include <bits/stdc++.h>
using namespace std;
long long col(long long n, long long m) {
  long long ans1;
  if (n <= m)
    ans1 = n;
  else
    ans1 = m + 1;
  ans1 = ans1 + min(n, m) + 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long ans = 0;
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ans = ans + col(i, j) + col(j, i) - 1;
    }
  }
  int ok[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) ok[i][j] = 1;
  }
  for (int i = 0; i < q; i++) {
    long long sum = 1;
    long long x, y;
    cin >> x >> y;
    x--;
    y--;
    long long x1 = x, y1 = y;
    y1++;
    while (x1 < n && y1 < m) {
      if (ok[x1][y1] == 1) {
        sum++;
        x1++;
      } else
        break;
      if (x1 < n && y1 < m && ok[x1][y1] == 1) {
        sum++;
        y1++;
      } else
        break;
    }
    x1 = x;
    y1 = y;
    x1++;
    while (x1 < n && y1 < m) {
      if (ok[x1][y1] == 1) {
        sum++;
        y1++;
      } else
        break;
      if (x1 < n && y1 < m && ok[x1][y1] == 1) {
        sum++;
        x1++;
      } else
        break;
    }
    x1 = x;
    y1 = y;
    y1--;
    while (x1 >= 0 && y1 >= 0) {
      if (ok[x1][y1] == 1) {
        sum++;
        x1--;
      } else
        break;
      if (x1 >= 0 && y1 >= 0 && ok[x1][y1] == 1) {
        sum++;
        y1--;
      } else
        break;
    }
    x1 = x;
    y1 = y;
    x1--;
    while (x1 >= 0 && y1 >= 0) {
      if (ok[x1][y1] == 1) {
        sum++;
        y1--;
      } else
        break;
      if (x1 >= 0 && y1 >= 0 && ok[x1][y1] == 1) {
        sum++;
        x1--;
      } else
        break;
    }
    ok[x][y] = ok[x][y] * -1;
    ans = ans + sum * ok[x][y];
    cout << ans << "\n";
  }
}
