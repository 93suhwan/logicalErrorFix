#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int n, m;
char A[405][405];
int S[405][405][2];
int qry(int up, int down, int col, int num) {
  return S[down][col][num] - S[up - 1][col][num];
}
int center(int up, int down, int col) {
  return qry(up + 1, down - 1, col, 1) + !A[down][col] + !A[up][col];
}
int main() {
  int kases;
  cin >> kases;
  while (kases--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> A[i][j];
        A[i][j] -= '0';
        S[i][j][0] = S[i - 1][j][0] + !A[i][j];
        S[i][j][1] = S[i - 1][j][1] + A[i][j];
      }
    }
    int ans = INF;
    for (int i = 1; i <= n; i++) {
      for (int j = i + 4; j <= n; j++) {
        int mi = INF;
        for (int k = 3; k < m; k++) {
          mi = min(mi + center(i, j, k), center(i, j, k) + center(i, j, k - 1) +
                                             qry(i + 1, j - 1, k - 2, 0));
          ans = min(ans, mi + qry(i + 1, j - 1, k + 1, 0));
        }
      }
    }
    cout << ans << endl;
  }
}
