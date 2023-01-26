#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> grid(n, vector<int>(m));
  vector<vector<bool>> vis(n, vector<bool>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }
  vector<int> pos(k);
  for (auto &i : pos) cin >> i;
  for (int i = 0; i < k; i++) {
    int r = 0, c = pos[i] - 1;
    bool flag = true;
    while (r < n) {
      if (vis[r][c]) {
        cout << c + 1 << " ";
        flag = false;
        break;
      } else {
        vis[r][c] = true;
        if (grid[r][c] == 1)
          c++;
        else if (grid[r][c] == 2)
          r++;
        else
          c--;
      }
    }
    if (flag) cout << c + 1 << " ";
  }
}
