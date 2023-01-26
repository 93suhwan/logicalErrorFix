#include <bits/stdc++.h>
using namespace std;
const int maxn = 10101;
const int mxlg = 31;
int n, K;
int x[maxn];
int o[3][3];
int a[3][3];
int andf(int i, int j) {
  cout << "and " << i + 1 << " " << j + 1 << endl;
  int her;
  cin >> her;
  return her;
}
int orf(int i, int j) {
  cout << "or " << i + 1 << " " << j + 1 << endl;
  int her;
  cin >> her;
  return her;
}
void solve() {
  cin >> n >> K;
  for (int i = 0; i < 3; i++)
    for (int j = i + 1; j < 3; j++) {
      o[i][j] = o[j][i] = orf(i, j);
      a[i][j] = a[j][i] = andf(i, j);
    }
  for (int l = mxlg; l--;)
    for (int i = 0; i < 3; i++)
      for (int j = i + 1; j < 3; j++) {
        int k = 3 - i - j;
        if (o[i][j] & (1 << l) == 0) {
          x[k] |= o[i][k] & (1 << l);
        }
        if (a[i][j] & (1 << l) != 0) {
          x[i] |= (1 << l);
          x[j] |= (1 << l);
          x[k] |= a[i][k] & (1 << l);
        }
      }
  for (int i = 3; i < n; i++) {
    int O = orf(0, i);
    int A = andf(0, i);
    for (int l = mxlg; l--;)
      if (x[0] & (1 << l) == 0) {
        x[i] |= O & (1 << l);
      } else {
        x[i] |= A & (1 << l);
      }
  }
  sort(x, x + n);
  cout << "finish " << x[K - 1] << endl;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
