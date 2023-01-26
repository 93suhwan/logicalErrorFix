#include <bits/stdc++.h>
using namespace std;
int n, m;
int x;
vector<int> adj[1000 * 1000 + 1];
bool viz[1000 * 1000 + 1];
int dim[1000 * 1000 + 1];
int Dl[4] = {0, 1, 0, -1};
int Dc[4] = {-1, 0, 1, 0};
int nr = 0;
void dfs(int v) {
  viz[v] = 1;
  dim[nr]++;
  for (auto i : adj[v])
    if (!viz[i]) dfs(i);
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> x;
      for (int k = 0; k < 4; k++)
        if ((x & (1 << k)) == 0) {
          int c1 = m * (i - 1) + j;
          int c2 = m * (i - 1) + j + Dl[k] * m + Dc[k];
          adj[c1].push_back(c2);
          adj[c2].push_back(c1);
        }
    }
  for (int i = 1; i <= n * m; i++)
    if (!viz[i]) {
      nr++;
      dfs(i);
    }
  sort(dim + 1, dim + nr + 1);
  for (int i = nr; i >= 1; i--) cout << dim[i] << " ";
  return 0;
}
