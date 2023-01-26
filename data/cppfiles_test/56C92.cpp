#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int d4x[4] = {1, 0, -1, 0};
int d4y[4] = {0, 1, 0, -1};
int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const long long oo = 1e18;
const long long maxN = 1e6;
void maximize(int &a, int b) { a = max(a, b); }
void minimize(int &a, int b) { a = min(a, b); }
const int N = 2e5;
int n;
bool f[6][6];
long long dp[N][6];
map<long long, int> mp;
int d[N], vs[N];
vector<int> g[N];
const long long MOD = 1e9 + 7;
long long Power(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return (a % MOD);
  long long T = Power(a, b / 2);
  if (b % 2) return (T * T % MOD * a % MOD);
  return (T * T % MOD);
}
long long cal_tree(int hi) {
  long long node = 1, ans = 6;
  for (int i = hi + 1; i <= n; i++) {
    ans = ans * Power(16, node) % MOD;
    node = node * 2;
  }
  return ans;
}
long long answer = 1;
int cnt = 0;
void dfs(int u, int hi) {
  cnt++;
  vs[u] = true;
  if (!g[u].size())
    for (int i = 0; i < 6; i++) dp[u][i] = 1;
  for (auto v : g[u]) {
    if (!vs[v]) dfs(v, hi + 1);
  }
  if (g[u].size() == 1) {
    int v = g[u][0];
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 6; j++)
        if (!f[i][j]) dp[u][i] = (dp[u][i] + dp[v][j]) % MOD;
    }
  }
  if (g[u].size() == 2) {
    int v = g[u][0];
    int x = g[u][1];
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 6; j++) {
        for (int k = 0; k < 6; k++) {
          if (!f[i][j] && !f[i][k]) {
            long long add = dp[v][j] * dp[x][k] % MOD;
            dp[u][i] = (dp[u][i] + add) % MOD;
          }
        }
      }
    }
  }
  if (d[u] > 0) {
    int c = d[u] - 1;
    for (int i = 0; i < 6; i++)
      if (c != i) dp[u][i] = 0;
  }
}
void solve() {
  int m;
  cin >> n >> m;
  f[0][0] = f[0][1] = true;
  f[1][0] = f[1][1] = true;
  f[2][2] = f[2][3] = true;
  f[3][2] = f[3][3] = true;
  f[4][4] = f[4][5] = true;
  f[5][4] = f[5][5] = true;
  vector<pair<long long, int>> used;
  for (int i = 1; i <= m; i++) {
    long long node;
    string color;
    cin >> node >> color;
    int c;
    if (color[0] == 'w') c = 0;
    if (color[0] == 'y') c = 1;
    if (color[0] == 'g') c = 2;
    if (color[0] == 'b') c = 3;
    if (color[0] == 'r') c = 4;
    if (color[0] == 'o') c = 5;
    used.push_back(make_pair(node, c));
  }
  set<long long> s;
  for (int i = 0; i < m; i++) {
    long long node = used[i].first;
    int c = used[i].second;
    while (node > 0) {
      s.insert(node);
      node = node / 2;
    }
  }
  int id = 0;
  for (auto i : s) {
    mp[i] = ++id;
  }
  for (int i = 0; i < m; i++) {
    long long node = used[i].first;
    int c = used[i].second;
    int id = mp[node];
    d[id] = c + 1;
    while (node > 0) {
      long long par = node / 2;
      if (par > 0) {
        int u = mp[par], v = mp[node];
        g[u].push_back(v);
      }
      node = par;
    }
  }
  for (int i = 1; i <= id; i++) {
    sort(g[i].begin(), g[i].end());
    g[i].resize(unique(g[i].begin(), g[i].end()) - g[i].begin());
  }
  dfs(1, 1);
  long long ans = Power(4, (1ll << n) - cnt - 1);
  long long answer = 0;
  for (int i = 0; i < 6; i++) answer = (answer + dp[1][i]) % MOD;
  ans = answer * ans % MOD;
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1, ddd = 0;
  while (tc--) {
    solve();
  }
}
