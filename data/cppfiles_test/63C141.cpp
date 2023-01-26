#include <bits/stdc++.h>
using namespace std;
int forest[1009][2];
int res[1009][2];
inline void cnt(int node1, int node2, int conf) {
  while (forest[node1][conf] > 0) node1 = forest[node1][conf];
  while (forest[node2][conf] > 0) node2 = forest[node2][conf];
  if (forest[node1][conf] < forest[node2][conf])
    forest[node2][conf] = node1;
  else if (forest[node1][conf] > forest[node2][conf])
    forest[node1][conf] = node2;
  else {
    forest[node2][conf] = node1;
    --forest[node1][conf];
  }
}
inline bool q(int node1, int node2, int conf) {
  while (forest[node1][conf] > 0) node1 = forest[node1][conf];
  while (forest[node2][conf] > 0) node2 = forest[node2][conf];
  return node1 == node2;
}
int main() {
  ios::sync_with_stdio(false);
  int n, m1, m2, u, v, h;
  h = 0;
  for (int i = 0; i < 1009; i++) {
    forest[i][0] = forest[i][1] = -1;
  }
  cin >> n >> m1 >> m2;
  for (int i = 0; i < m1; i++) {
    cin >> u >> v;
    cnt(u, v, 0);
  }
  for (int i = 0; i < m2; i++) {
    cin >> u >> v;
    cnt(u, v, 1);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      if (!q(i, j, 0) && !q(i, j, 1)) {
        cnt(i, j, 0);
        cnt(i, j, 1);
        res[h][0] = i;
        res[h][1] = j;
        ++h;
      }
    }
  }
  cout << h << endl;
  for (int i = 0; i < h; i++) {
    cout << res[i][0] << " " << res[i][1] << endl;
  }
  return 0;
}
