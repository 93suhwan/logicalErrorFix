#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
int max(int a, int b) {
  if (a > b) return a;
  return b;
}
int min(int a, int b) {
  if (a < b) return a;
  return b;
}
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> grid(n + 1, vector<int>(m + 1, 0));
  int i = 1;
  int j = 1;
  if (n & 1) {
    while (j + 1 <= m) {
      grid[i][j] = grid[i][j + 1] = 1;
      k--;
      j += 2;
    }
    i = 2;
    j = 1;
  }
  while (k) {
    if (i + 1 <= n && j + 1 <= m) {
      grid[i][j] = grid[i][j + 1] = 1;
      i++;
      k--;
      if (k == 0) break;
      grid[i][j] = grid[i][j + 1] = 1;
      i++;
      k--;
    } else if (j + 1 <= m) {
      j += 2;
      if (n & 1)
        i = 2;
      else
        i = 1;
    } else
      break;
  }
  for (int j = 1; j <= m; ++j) {
    int s = 0;
    for (int i = 1; i <= n; ++i)
      if (grid[i][j] == 0) s++;
    if (s & 1) {
      k = 1;
      break;
    }
  }
  if (k == 0)
    cout << "YES\n";
  else {
    cout << "NO\n";
    return;
  }
  vector<vector<char>> res(n + 1, vector<char>(m + 1, 0));
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      if (res[i][j]) continue;
      if (grid[i][j] == 1 && res[i][j + 1] == 0 && grid[i][j + 1] == 1) {
        char d = 'a';
        int c = 0;
      begin1:
        for (int x = -1; x <= 1; x++) {
          for (int y = -1; y <= 2; y++) {
            if (i + x >= 0 && i + x <= n && j + y >= 0 && j + y <= m) {
              if (res[i + x][j + y] == d) {
                c++;
                c %= 26;
                d = 'a' + c;
                goto begin1;
              }
            }
          }
        }
        res[i][j] = res[i][j + 1] = d;
      } else if (grid[i][j] == 0 && res[i + 1][j] == 0 && grid[i + 1][j] == 0) {
        char d = 'a';
        int c = 0;
      begin2:
        for (int x = -1; x <= 2; x++) {
          for (int y = -1; y <= 1; y++) {
            if (i + x >= 0 && i + x <= n && j + y >= 0 && j + y <= m) {
              if (res[i + x][j + y] == d) {
                c++;
                c %= 26;
                d = 'a' + c;
                goto begin2;
              }
            }
          }
        }
        res[i][j] = res[i + 1][j] = d;
      }
    }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) cout << res[i][j];
    cout << "\n";
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
