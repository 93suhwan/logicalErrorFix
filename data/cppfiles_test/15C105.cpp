#include <bits/stdc++.h>
using namespace std;
const int N = 2e2 + 5, mod = 1e9 + 7;
int e[N], ne[N], h[N], idx;
int d[N];
long long f[N][N];
void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }
void dfs(int x, int fa, int dis, int f) {
  d[dis]++;
  for (int i = h[x]; ~i; i = ne[i]) {
    int u = e[i];
    if (u == fa) continue;
    dfs(u, x, dis + 1, f);
  }
}
int main() {
  int _;
  cin >> _;
  memset(h, -1, sizeof h);
  while (_--) {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
      int a, b;
      cin >> a >> b;
      add(a, b);
      add(b, a);
    }
    long long ans = 0;
    if (k == 2) {
      cout << n * (n - 1) / 2 << endl;
    } else {
      vector<int> g[N];
      for (int i = 1; i <= n; i++) {
        for (int i = 1; i <= n; i++) g[i].clear();
        int x = i;
        for (int j = h[x]; ~j; j = ne[j]) {
          memset(d, 0, sizeof d);
          int u = e[j];
          dfs(u, x, 1, x);
          for (int i = 1; i <= n; i++) g[i].push_back(d[i]);
        }
        for (int i = 1; i <= n; i++) {
          f[0][0] = 1;
          if (g[i].size() < k) continue;
          for (int j = 1; j <= g[i].size(); j++) {
            for (int w = 0; w <= k; w++) {
              f[j][w] = f[j - 1][w];
              if (w >= 1)
                f[j][w] = (f[j][w] + f[j - 1][w - 1] * g[i][j - 1] % mod) % mod;
            }
          }
          ans = (ans + f[g[i].size()][k]) % mod;
        }
      }
      cout << ans << endl;
    }
    idx = 0;
    for (int i = 1; i <= n; i++) h[i] = -1;
  }
}
