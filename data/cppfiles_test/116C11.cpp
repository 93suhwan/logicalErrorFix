#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template <typename T>
void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
void print(T x, char let) {
  print(x), putchar(let);
}
const int N = 3e5 + 5;
const int MOD = 998244353;
int n, m, k, vis[N], in[N], out[N], d[N], a[N], cnt, vis1[N];
int b[N], e[N], cnt2, vis2[N], dp[N];
vector<int> G[N];
bool dfs(int u, int idx) {
  vis[u] = 1;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (!vis[v] && in[v] == 1 && out[v] <= 1) {
      bool b = dfs(v, idx);
      if (b) d[u] = idx;
      return b;
    } else {
      return false;
    }
  }
  d[u] = idx;
  return true;
}
int main() {
  n = read();
  m = read();
  k = read();
  int x, y;
  for (int i = 1; i <= n; i++) {
    x = read();
    int l;
    for (int j = 1; j <= x; j++) {
      y = read();
      if (j != 1) {
        G[l].push_back(y);
      }
      l = y;
    }
  }
  for (int i = 1; i <= k; i++) {
    sort(G[i].begin(), G[i].end());
    vector<int>::iterator x = unique(G[i].begin(), G[i].end());
    G[i].erase(x, G[i].end());
    for (int j = 0; j < G[i].size(); j++) {
      int v = G[i][j];
      in[v]++;
      out[i]++;
    }
  }
  int tot = 0;
  for (int i = 1; i <= k; i++) {
    if (!vis[i] && in[i] == 0 && out[i] == 1) {
      dfs(i, ++tot);
    }
    if (in[i] == 0 && out[i] == 0) {
      d[i] = ++tot;
    }
  }
  for (int i = 1; i <= k; i++) {
    if (d[i]) {
      if (vis1[d[i]] == 0) {
        ++cnt;
        a[cnt] = 1;
        vis1[d[i]] = cnt;
      } else {
        a[vis1[d[i]]]++;
      }
    }
  }
  for (int i = 1; i <= cnt; i++) {
    if (vis2[a[i]] == 0) {
      ++cnt2;
      b[cnt2] = a[i];
      e[cnt2] = 1;
      vis2[a[i]] = cnt2;
    } else {
      e[vis2[a[i]]]++;
    }
  }
  dp[0] = 1;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= cnt2; j++) {
      if (i >= b[j]) {
        dp[i] = (dp[i] + 1ll * dp[i - b[j]] * e[j] % MOD) % MOD;
      }
    }
  }
  cout << dp[m] << endl;
  return 0;
}
