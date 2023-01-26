#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const int INF = 1000000000 + 1e8;
const long long LINF = 2000000000000000000;
const int N = 60;
bitset<N> cur;
bitset<N> g[N];
bitset<N> rg[N];
vector<vector<int>> ag;
int n, m;
void go(int v, int cnt = 1) {
  cur[v] = 1;
  if (cnt == 5) {
    for (int i = 0; i < n; i++)
      if (cur[i]) cout << i + 1 << ' ';
    exit(0);
  }
  for (int i = 0; i < n; i++) {
    if (!cur[i] && g[v][i] && (cur & g[i]) == cur) {
      go(i, cnt + 1);
    }
  }
  cur[v] = 0;
}
void solve() {
  cin >> n >> m;
  n = min(n, N);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      rg[i][j] = 1;
    }
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (u < n && v < n) g[u][v] = g[v][u] = 1;
  }
  for (int i = 0; i < n; i++) go(i);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) g[i][j] = 1 - g[i][j];
  for (int i = 0; i < n; i++) go(i);
  cout << -1;
}
int main() {
  srand(time(0));
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tst = 1;
  while (tst--) {
    solve();
  }
}
