#include <bits/stdc++.h>
using namespace std;
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, 1, -1};
const int mx = 1e6 + 5;
bool check(char **a, int p, int q, int n, int m, int **visited) {
  int counter = 0;
  if (p - 1 >= 0 && a[p - 1][q] == '.' && visited[p - 1][q] == 0) {
    counter++;
  }
  if (p + 1 < n && a[p + 1][q] == '.' && visited[p + 1][q] == 0) {
    counter++;
  }
  if (q - 1 >= 0 && a[p][q - 1] == '.' && visited[p][q - 1] == 0) {
    counter++;
  }
  if (q + 1 < m && a[p][q + 1] == '.' && visited[p][q + 1] == 0) {
    counter++;
  }
  if (counter >= 2) {
    return false;
  }
  return true;
}
void dfs(char **a, int p, int q, int n, int m, int **visited) {
  visited[p][q] = 1;
  for (int i = 0; i < 4; i++) {
    int r = dx[i] + p;
    int c = dy[i] + q;
    if (r < n && c < m && r >= 0 && c >= 0 && visited[r][c] != 1 &&
        a[r][c] != '#') {
      if (check(a, r, c, n, m, visited)) {
        a[r][c] = '+';
        visited[r][c] = 1;
        dfs(a, r, c, n, m, visited);
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    char **a = new char *[n];
    int **visited = new int *[n];
    pair<int, int> p;
    for (int i = 0; i < n; i++) {
      a[i] = new char[m];
      visited[i] = new int[m];
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
        if (a[i][j] == 'L') {
          p = {i, j};
        }
        visited[i][j] = 0;
      }
    }
    dfs(a, p.first, p.second, n, m, visited);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << a[i][j];
      }
      cout << "\n";
    }
  }
  return 0;
}
