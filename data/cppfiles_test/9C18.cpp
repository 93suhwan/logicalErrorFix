#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> a;
int dfs(int i, int j) {
  if (i >= a.size())
    return j;
  else if (j >= a[0].size())
    return j - 1;
  else if (j < 0)
    return j + 1;
  int temp = a[i][j];
  a[i][j] = 2;
  if (temp == 1) return dfs(i, j + 1);
  if (temp == 2)
    return dfs(i + 1, j);
  else
    return dfs(i, j - 1);
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    a[i].resize(m);
    for (int j = 0; j < m; j++) cin >> a[i][j];
  }
  while (k--) {
    int x;
    cin >> x;
    cout << dfs(0, x - 1) + 1 << " ";
  }
}
