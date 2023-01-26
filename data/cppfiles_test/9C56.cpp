#include <bits/stdc++.h>
using namespace std;
int A[1000][1000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cin >> A[i][j];
  }
  while (k--) {
    int c;
    cin >> c;
    int cur_x = 0, cur_y = c - 1;
    while (cur_x < n) {
      if (A[cur_x][cur_y] == 1) {
        A[cur_x][cur_y] = 2;
        ++cur_y;
      } else if (A[cur_x][cur_y] == 2) {
        ++cur_x;
      } else if (A[cur_x][cur_y] == 3) {
        A[cur_x][cur_y] = 2;
        --cur_y;
      }
    }
    cout << cur_y + 1 << ' ';
  }
  cout << '\n';
  return 0;
}
