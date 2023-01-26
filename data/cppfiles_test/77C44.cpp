#include <bits/stdc++.h>
using namespace std;
const long double PI = atan(1) * 4.0;
int n, m;
const int N = 1e3 + 4;
int mat[N][N];
bool visited[N][N];
int comp = 0;
void dfs(int i, int j) {
  if (visited[i][j]) {
    return;
  }
  comp++;
  visited[i][j] = 1;
  if (i - 1 >= 0) {
    if ((1 << 3) & mat[i][j]) {
    } else {
      dfs(i - 1, j);
    }
  }
  if (j + 1 < m) {
    if ((1 << 2) & mat[i][j]) {
    } else {
      dfs(i, j + 1);
    }
  }
  if (i + 1 < n) {
    if ((1 << 1) & mat[i][j]) {
    } else {
      dfs(i + 1, j);
    }
  }
  if (j - 1 >= 0) {
    if ((1 << 0) & mat[i][j]) {
    } else {
      dfs(i, j - 1);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
    }
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!visited[i][j]) {
        dfs(i, j);
        ans.push_back(comp);
        comp = 0;
      }
    }
  }
  sort(ans.rbegin(), ans.rend());
  for (int i = 0; i < int(ans.size()); i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
