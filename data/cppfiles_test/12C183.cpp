#include <bits/stdc++.h>
using namespace std;
char grid1[100][100];
int grid[100][100];
int n, m, k;
int N;
char C;
bool flag;
void incC() {
  C++;
  if (C > 'z') C = 'a';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        grid1[i][j] = '0';
        grid[i][j] = 0;
      }
    C = 'a';
    N = 1;
    flag = true;
    if (n % 2 == 1) {
      for (int i = 1; i < m && k > 0; i += 2) {
        grid[n - 1][i] = N;
        grid[n - 1][i - 1] = N;
        N++;
        k--;
      }
    }
    for (int i = 1; i < m && k > 0; i += 2) {
      for (int j = 1; j < n; j += 2) {
        grid[j][i] = N;
        grid[j][i - 1] = N;
        k--;
        if (k == 0) break;
        N++;
        grid[j - 1][i] = N;
        grid[j - 1][i - 1] = N;
        k--;
        if (k == 0) break;
        N++;
      }
    }
    if (k > 0) {
      cout << "NO" << endl;
      continue;
    }
    N = -1;
    for (int j = 0; j < m; j++) {
      for (int i = 1; i < n; i += 2) {
        if (grid[i][j] == 0 && grid[i - 1][j] == 0) {
          grid[i][j] = grid[i - 1][j] = N;
          N--;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        if (grid[i][j] == 0) flag = false;
    }
    if (!flag) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
  }
  return 0;
}
