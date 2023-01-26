#include <bits/stdc++.h>
using namespace std;
int n, m, a[10004][1004];
int ok(int r, int c) {
  if (r == n) {
    return c + 1;
  }
  int k = a[r][c];
  a[r][c] = 2;
  if (k == 1) {
    return ok(r, c + 1);
  } else if (k == 2) {
    return ok(r + 1, c);
  } else
    return ok(r, c - 1);
}
int main() {
  int p, i, j, k;
  cin >> n >> m >> k;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  while (k--) {
    cin >> p;
    cout << ok(0, p - 1) << " ";
  }
}
