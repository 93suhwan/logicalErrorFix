#include <bits/stdc++.h>
using namespace std;
vector<long long> num;
void solve() {
  int n;
  cin >> n;
  char arr[2][n];
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }
  int row = 0, col = 0;
  int visited[2][n];
  memset(visited, false, sizeof(visited));
  while (col < n - 1) {
    visited[row][col] = true;
    if (!visited[row][col + 1] && arr[row][col + 1] != '1')
      col++;
    else if (!visited[1 - row][col] && arr[1 - row][col] != '1') {
      row = 1 - row;
    } else if (!visited[1 - row][col + 1] && arr[1 - row][col + 1] != '1') {
      row = 1 - row;
      col++;
    } else {
      break;
    }
  }
  if (col == n - 1)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
