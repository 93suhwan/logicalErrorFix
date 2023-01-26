#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, m, q;
  cin >> n >> m >> q;
  vector<vector<bool>> grid(n + 2, vector<bool>(m + 2, true));
  vector<vector<long long int>> one(n + 2, vector<long long int>(m + 2, 0));
  vector<vector<long long int>> two(n + 2, vector<long long int>(m + 2, 0));
  long long int total = 0;
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 1; j <= m; j++) {
      one[i][j] = two[i][j] = 1;
      one[i][j] += two[i][j - 1];
      two[i][j] += one[i - 1][j];
      total += one[i][j] + two[i][j] - 1;
    }
  }
  for (long long int i = 1; i <= q; i++) {
    long long int x, y;
    cin >> x >> y;
    if (grid[x][y]) {
      grid[x][y] = !grid[x][y];
      total -= one[x][y];
      total -= two[x][y];
      total++;
      one[x][y] = 0;
      two[x][y] = 0;
      for (long long int step = 1; step <= n - 1; step++) {
        if ((x + step - 1 <= n) and (y + step <= m) &&
            grid[x + step - 1][y + step]) {
          long long int temp = two[x + step - 1][y + step - 1] + 1;
          total += (temp - one[x + step - 1][y + step]);
          one[x + step - 1][y + step] = temp;
        }
        if ((x + step <= n) and (y + step - 1 <= m) &&
            grid[x + step][y + step - 1]) {
          long long int temp = one[x + step - 1][y + step - 1] + 1;
          total += (temp - two[x + step][y + step - 1]);
          two[x + step][y + step - 1] = temp;
        }
        if (x + step > n || y + step > m) break;
        if (!grid[x + step][y + step]) break;
        long long int temp = one[x + step - 1][y + step] + 1;
        total += (temp - two[x + step][y + step]);
        two[x + step][y + step] = temp;
        temp = two[x + step][y + step - 1] + 1;
        total += (temp - one[x + step][y + step]);
        one[x + step][y + step] = temp;
      }
    } else {
      grid[x][y] = !grid[x][y];
      one[x][y] = 1 + two[x][y - 1];
      two[x][y] = 1 + one[x - 1][y];
      total += one[x][y] + two[x][y] - 1;
      for (long long int step = 1; step <= n - 1; step++) {
        if ((x + step - 1 <= n) and (y + step <= m) &&
            grid[x + step - 1][y + step]) {
          long long int temp = two[x + step - 1][y + step - 1] + 1;
          total += (temp - one[x + step - 1][y + step]);
          one[x + step - 1][y + step] = temp;
        }
        if ((x + step <= n) and (y + step - 1 <= m) &&
            grid[x + step][y + step - 1]) {
          long long int temp = one[x + step - 1][y + step - 1] + 1;
          total += (temp - two[x + step][y + step - 1]);
          two[x + step][y + step - 1] = temp;
        }
        if (x + step > n || y + step > m) break;
        if (!grid[x + step][y + step]) break;
        long long int temp = one[x + step - 1][y + step] + 1;
        total += (temp - two[x + step][y + step]);
        two[x + step][y + step] = temp;
        temp = two[x + step][y + step - 1] + 1;
        total += (temp - one[x + step][y + step]);
        one[x + step][y + step] = temp;
      }
    }
    cout << total << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tc = 1;
  while (tc--) {
    solve();
  }
  return 0;
}
