#include <bits/stdc++.h>
using namespace std;
int n, m;
string arr[1000005];
void jao(int row, int col) {
  int f = 0;
  if (arr[row][col] == '.') {
    if (arr[row][col - 1] == '.') f++;
    if (arr[row - 1][col] == '.') f++;
    if (arr[row][col + 1] == '.') f++;
    if (arr[row + 1][col] == '.') f++;
    if (f < 2) {
      arr[row][col] = '+';
      if (arr[row][col - 1] == '.') jao(row, col - 1);
      if (arr[row - 1][col] == '.') jao(row - 1, col);
      if (arr[row][col + 1] == '.') jao(row, col + 1);
      if (arr[row + 1][col] == '.') jao(row + 1, col);
    }
  }
  if (arr[row][col] == 'L') {
    if (arr[row][col - 1] == '.') f++;
    if (arr[row - 1][col] == '.') f++;
    if (arr[row][col + 1] == '.') f++;
    if (arr[row + 1][col] == '.') f++;
    if (f < 3) {
      if (arr[row][col - 1] == '.') jao(row, col - 1);
      if (arr[row - 1][col] == '.') jao(row - 1, col);
      if (arr[row][col + 1] == '.') jao(row, col + 1);
      if (arr[row + 1][col] == '.') jao(row + 1, col);
    }
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t, r, c;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    arr[0] = arr[n + 1] = "";
    for (int j = 0; j < m + 2; j++) {
      arr[0] += '#';
      arr[n + 1] += '#';
    }
    for (int i = 1; i < n + 1; i++) {
      cin >> arr[i];
      arr[i] = '#' + arr[i] + '#';
      for (int j = 1; j < m + 1; j++) {
        if (arr[i][j] == 'L') {
          r = i;
          c = j;
        }
      }
    }
    jao(r, c);
    for (int i = 1; i < n + 1; i++) {
      for (int j = 1; j < m + 1; j++) cout << arr[i][j];
      cout << "\n";
    }
    cout << "\n";
  }
  return 0;
}
