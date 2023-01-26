#include <bits/stdc++.h>
using namespace std;
long long int grid[2000][2000], lefft[2000][2000], upp[2000][2000],
    righht[2000][2000], dowwn[2000][2000], visited[2000][2000];
vector<long long int> ans2;
long long int row, col;
bool valid(long long int nx, long long int ny) {
  if (nx >= 0 && nx < row && ny >= 0 && ny < col) return true;
  return false;
}
long long int DFS(long long int i, long long int j) {
  long long int ans = 1;
  visited[i][j] = 1;
  int flag = 0;
  if (valid(i, j - 1)) {
    if (lefft[i][j] == 0 && righht[i][j - 1] == 0 && visited[i][j - 1] == 0) {
      ans += DFS(i, j - 1);
      flag = 1;
    }
  }
  if (valid(i, j + 1)) {
    if (righht[i][j] == 0 && lefft[i][j + 1] == 0 && visited[i][j + 1] == 0) {
      ans += DFS(i, j + 1);
      flag = 1;
    }
  }
  if (valid(i - 1, j)) {
    if (upp[i][j] == 0 && dowwn[i - 1][j] == 0 && visited[i - 1][j] == 0) {
      ans += DFS(i - 1, j);
      flag = 1;
    }
  }
  if (valid(i + 1, j)) {
    if (dowwn[i][j] == 0 && upp[i + 1][j] == 0 && visited[i + 1][j] == 0) {
      ans += DFS(i + 1, j);
      flag = 1;
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u,
      v, w, x, y, z;
  string s1;
  cin >> row >> col;
  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      cin >> grid[i][j];
      a = grid[i][j];
      s1 = "";
      visited[i][j] = 0;
      upp[i][j] = 0;
      dowwn[i][j] = 0;
      lefft[i][j] = 0;
      righht[i][j] = 0;
      while (a != 0) {
        s1 += ((a % 2) + '0');
        a /= 2;
      }
      while (s1.size() != 4) s1 += '0';
      reverse(s1.begin(), s1.end());
      if (s1[0] == '1') {
        upp[i][j] = 1;
      }
      if (s1[1] == '1') righht[i][j] = 1;
      if (s1[2] == '1') dowwn[i][j] = 1;
      if (s1[3] == '1') lefft[i][j] = 1;
    }
  }
  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      if (visited[i][j] == 0) ans2.push_back(DFS(i, j));
    }
  }
  sort(ans2.begin(), ans2.end());
  n = ans2.size();
  for (i = n - 1; i >= 0; i--) cout << ans2[i] << " ";
  cout << "\n";
  return 0;
}
