#include <bits/stdc++.h>
using namespace std;
bool a[2005][2005];
int s0[2005][2005], s1[2005][2005];
int q(int l, int r, int y) {
  return s0[r - 1][y] - s0[l][y] + !a[l][y] + !a[r][y];
}
void Main() {
  int n, m, i, j, k, l, ykb, sum = 0, Min = 999999999;
  char A;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      cin >> A;
      a[i][j] = (A == '1');
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      s0[i][j] = s0[i - 1][j] + a[i][j];
      s1[i][j] = s1[i - 1][j] + !a[i][j];
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = i + 4; j <= n; j++) {
      sum = 999999999;
      for (k = 3; k < m; k++) {
        sum = min(q(i, j, k) + q(i, j, k - 1) + s1[j - 1][k - 2] - s1[i][k - 2],
                  sum + q(i, j, k));
        Min = min(Min, sum + s1[j - 1][k + 1] - s1[i][k + 1]);
      }
    }
  }
  cout << Min << endl;
}
int main() {
  int t, i;
  cin >> t;
  for (i = 0; i < t; i++) {
    Main();
  }
}
