#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m, k;
  cin >> n >> m >> k;
  int array[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> array[i][j];
    }
  }
  int pos[k];
  for (int i = 0; i < k; i++) cin >> pos[i];
  for (int i = 0; i < k; i++) {
    pair<int, int> currentpos;
    currentpos.first = 0;
    currentpos.second = pos[i] - 1;
    while (currentpos.first != n) {
      int row = currentpos.first;
      int column = currentpos.second;
      if (array[currentpos.first][currentpos.second] == 1) {
        currentpos.second++;
      } else if (array[currentpos.first][currentpos.second] == 2) {
        currentpos.first++;
      } else {
        currentpos.second--;
      }
      array[row][column] = 2;
    }
    cout << currentpos.second + 1;
    cout << " ";
  }
  return 0;
}
