#include <bits/stdc++.h>
using namespace std;
const int N = 12;
int n, a[N], m, f[N][2][2];
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    m = 0;
    while (n) a[++m] = n % 10, n /= 10;
    memset(f, 0, sizeof(f));
    f[0][0][0] = 1;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < 2; j++)
        for (int k = 0; k < 2; k++) {
          int t = f[i][j][k], x = a[i + 1] - j;
          f[i + 1][k][0] += t * (x + 1);
          f[i + 1][k][1] += t * (9 - x);
        }
    cout << f[m][0][0] - 2 << endl;
  }
  return 0;
}
