#include <bits/stdc++.h>
using namespace std;
void fun() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> grid(n, vector<char>(m));
  vector<int> prefix(m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
      if (i > 0 and j > 0) {
        if (grid[i - 1][j] == 'X' and grid[i][j - 1] == 'X') prefix[j] = 1;
      }
    }
  }
  for (int j = 1; j < m; j++) prefix[j] += prefix[j - 1];
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    int val = prefix[b - 1] - prefix[a - 1];
    if (val == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
int main() {
  int t = 1;
  while (t--) {
    fun();
  }
  return 0;
}
