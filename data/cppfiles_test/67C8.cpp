#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n;
long double p, c[N][N];
int main() {
  for (int i = 0; i < N; ++i) c[i][0] = 1;
  for (int i = 1; i < N; ++i)
    for (int j = 1; j <= i; ++j) {
      c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }
  cin >> n >> p;
  for (int k = 0; k <= n; ++k) {
    long double cur =
        (c[k][3] + 0.5 * c[k][1] * c[n - k][2] + c[k][2] * c[n - k][1]) /
        c[n][3];
    if (cur >= p) {
      cout << k << '\n';
      return 0;
    }
  }
  return 0;
}
