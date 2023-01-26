#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
double c[N][N];
void solve() {
  int n;
  double p;
  cin >> n >> p;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= min(i, 3); j++) {
      if (j == 0)
        c[i][j] = 1;
      else if (j == 1)
        c[i][j] = i;
      else if (j == 2)
        c[i][j] = i * (i - 1) / 2;
      else if (j == 3)
        c[i][j] = i * (i - 1) * (i - 2) / 6;
    }
  for (int i = 0; i <= n; i++) {
    double c3, c2, c1, c0;
    c3 = c[i][3] * c[n - i][0];
    c2 = c[i][2] * c[n - i][1];
    c1 = c[i][1] * c[n - i][2];
    c0 = c[i][0] * c[n - i][3];
    double tmp;
    if ((c3 + c2 + c1 * 0.5) == 0)
      tmp = 0;
    else
      tmp = (c3 + c2 + c1 * 0.5) / (c3 + c2 + c1 + c0);
    if (tmp >= p) {
      cout << (int)i << "\n";
      return;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
