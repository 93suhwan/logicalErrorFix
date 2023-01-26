#include <bits/stdc++.h>
using namespace std;
int n, m, k, t;
int arr[1005][1005], c[1005][1005], b[1005];
void check(int i, int j) {
  k++;
  c[i][j] = 1;
  if (!(arr[i][j] & 1)) {
    if (!c[i][j - 1]) {
      check(i, j - 1);
    }
  }
  if (!((arr[i][j] >> 1) & 1)) {
    if (!c[i + 1][j]) {
      check(i + 1, j);
    }
  }
  if (!((arr[i][j] >> 2) & 1)) {
    if (!c[i][j + 1]) {
      check(i, j + 1);
    }
  }
  if (!((arr[i][j] >> 3) & 1)) {
    if (!c[i - 1][j]) {
      check(i - 1, j);
    }
  }
}
void solve() {
  cin >> n >> m;
  t = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> arr[i][j];
      c[i][j] = 0;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      k = 0;
      if (!c[i][j]) {
        check(i, j);
        b[t] = k;
        t++;
      }
      k = 0;
    }
  }
  sort(b, b + t);
  for (int i = t - 1; i >= 0; i--) {
    cout << b[i] << " ";
  }
}
int main() {
  solve();
  return 0;
}
