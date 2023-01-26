#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    int m, n;
    cin >> m >> n;
    int matrix[m][n];
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cin >> matrix[i][j];
      }
    }
    pair<int, int> x = {-1, -1};
    int ans = 0;
    int max_joy = 0;
    for (int i = 0; i < m; i++) {
      pair<int, int> l1, l2;
      if (matrix[i][0] >= matrix[i][1]) {
        l1 = {matrix[i][0], 0};
        l2 = {matrix[i][1], 1};
      } else {
        l2 = {matrix[i][0], 0};
        l1 = {matrix[i][1], 1};
      }
      for (int j = 2; j < n; j++) {
        if (matrix[i][j] > l1.first) {
          l1 = {matrix[i][j], j};
        } else if (matrix[i][j] > l2.first && matrix[i][j] <= l1.first) {
          l2 = {matrix[i][j], j};
        }
      }
      if (l2.first > max_joy) {
        max_joy = l2.first;
        x = {l1.second, l2.second};
      }
    }
    ans = max_joy;
    for (int j = 0; j < n; j++) {
      if (j == x.first || j == x.second) continue;
      max_joy = 0;
      for (int i = 0; i < m; i++) {
        if (matrix[i][j] > max_joy) max_joy = matrix[i][j];
      }
      ans = min(ans, max_joy);
    }
    cout << ans << endl;
  }
  return 0;
}
