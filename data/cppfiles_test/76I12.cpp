#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int maxn = 1e6 + 10;
int n, m;
bool g[50][50];
void dfs(int p, int cur, int val, vector<int> &vec) {
  if (p == 5) {
    for (int i : vec) printf("%d ", i);
    exit(0);
  }
  for (int i = cur; i <= n; i++) {
    bool ok = 1;
    for (int j : vec) ok &= g[i][j] == val;
    if (ok) vec[p] = i, dfs(p + 1, i + 1, val, vec);
  }
}
int main() {
  cin >> n >> m;
  n = min(n, 48);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (max(u, v) <= 48) g[u][v] = g[v][u] = 1;
  }
  vector<int> a(5);
  dfs(0, 1, 0, a);
  dfs(0, 1, 1, a);
  puts("-1");
}
