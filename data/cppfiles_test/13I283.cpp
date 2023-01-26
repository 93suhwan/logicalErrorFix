#include <bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> grid) {
  int n = grid.size();
  int m = grid[0].size();
  vector<string> ans;
  for (int i = 0; i < n; i++) {
    string s = "a";
    for (int j = 1; j < m; j++) {
      char c;
      if (i && grid[i][j] == grid[i - 1][j])
        c = ans.back()[j];
      else if (grid[i][j] == grid[i][j - 1])
        c = s.back();
      else {
        c = 'a';
        while (c == s.back() || (i && ans.back()[j] == c))
          c = (c - 'a' + 1) % 26 + 'a';
      }
      s += c;
    }
    ans.push_back(s);
  }
  for (int i = 0; i < n; i++) cout << ans[i] << '\n';
}
void run() {
  int n, m, k;
  cin >> n >> m >> k;
  int num = 1;
  vector<vector<int>> grid(n, vector<int>(m, 0));
  if (n % 2) {
    for (int i = 0; i < m; i += 2) {
      grid[n - 1][i] = grid[n - 1][i + 1] = num++;
      k--;
    }
    if (k < 0) {
      cout << "NO\n";
      return;
    }
    n--;
  }
  if (k % 2) {
    cout << "NO\n";
    return;
  }
  if (n == 0) {
    if (k)
      cout << "NO\n";
    else {
      cout << "YES\n";
      print(grid);
    }
    return;
  }
  int colLeft = 2 * ((k + n - 1) / n);
  if (colLeft > m) {
    cout << "NO\n";
    return;
  }
  for (int i = 0; i < n; i += 2)
    for (int j = 0; j < m - colLeft; j++) grid[i][j] = grid[i + 1][j] = num++;
  for (int i = 0; i < n; i++)
    for (int j = m - colLeft; j < m - 2; j += 2) {
      grid[i][j] = grid[i][j + 1] = num++;
      k--;
    }
  if (colLeft >= 2) {
    for (int i = 0; i < k; i++) grid[i][m - 2] = grid[i][m - 1] = num++;
    for (int i = k; i < n; i += 2) {
      grid[i][m - 2] = grid[i + 1][m - 2] = num++;
      grid[i][m - 1] = grid[i + 1][m - 1] = num++;
    }
  }
  cout << "YES\n";
  print(grid);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tichnas;
  cin >> tichnas;
  while (tichnas--) run();
  return 0;
}
