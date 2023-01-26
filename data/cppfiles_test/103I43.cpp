#include <bits/stdc++.h>
using namespace std;
const unsigned long long INF = ~0ull >> 1;
const long double EPS = 1e-10;
char land[2000][2000];
long long dp[2000][2000];
int color[2000][2000];
void solve() {
  register int n, m;
  cin >> n >> m;
  for (int i = (0); i <= (n - 1); ++i)
    for (int j = (0); j <= (m - 1); ++j) {
      cin >> land[i][j];
      dp[i][j] = 0;
      color[i][j] = 0;
    }
  register long long answer = 1;
  register int a_i = 1, a_j = 1;
  register int i, j, k, cycle_i, cycle_j, in_cycle;
  register long long cc;
  for (int _i = (0); _i <= (n - 1); ++_i)
    for (int _j = (0); _j <= (m - 1); ++_j) {
      if (dp[_i][_j] != 0) continue;
      i = _i;
      j = _j;
      k = i * n + j + 1;
      cc = 0;
      cycle_i = -1;
      cycle_j = -1;
      in_cycle = false;
      while (i >= 0 && j >= 0 && i < n && j < m) {
        if (color[i][j] != 0) break;
        color[i][j] = k;
        ++cc;
        if (land[i][j] == 'U')
          --i;
        else if (land[i][j] == 'R')
          ++j;
        else if (land[i][j] == 'L')
          --j;
        else
          ++i;
      }
      if (i >= 0 && j >= 0 && i < n && j < m) {
        if (color[i][j] == k)
          cycle_i = i, cycle_j = j;
        else if (color[i][j] != 0)
          cc += dp[i][j];
      }
      if (answer < cc) {
        answer = cc;
        a_i = _i + 1;
        a_j = _j + 1;
      }
      i = _i;
      j = _j;
      while (i >= 0 && j >= 0 && i < n && j < m) {
        if (dp[i][j] != 0) break;
        if (i == cycle_i && j == cycle_j) in_cycle = true;
        dp[i][j] = cc;
        if (!in_cycle) --cc;
        if (land[i][j] == 'U')
          --i;
        else if (land[i][j] == 'R')
          ++j;
        else if (land[i][j] == 'L')
          --j;
        else
          ++i;
      }
    }
  cout << a_i << " " << a_j << " " << answer << ' ';
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) solve();
}
