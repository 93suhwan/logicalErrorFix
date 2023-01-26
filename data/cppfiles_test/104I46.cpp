#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (!b)
    return a;
  else
    return gcd(b, a % b);
}
vector<int> adj[4000001];
vector<int> radj[4000001];
struct SCC {
  int n, timer = 0, ccnt = 0;
  vector<int> low, tin, comp;
  stack<int> stk;
  SCC(int _n) {
    n = _n;
    low.assign(n, 0);
    tin.assign(n, -1);
    comp.assign(n, 0);
  }
  void dfs(int v) {
    stk.push(v);
    low[v] = tin[v] = ++timer;
    for (int x : adj[v]) {
      if (tin[x] == -1) dfs(x);
      low[v] = min(low[v], low[x]);
    }
    if (tin[v] == low[v]) {
      ccnt++;
      while (true) {
        int j = stk.top();
        stk.pop();
        comp[j] = ccnt;
        low[j] = 1e9;
        if (j == v) break;
      }
    }
  }
  void build() {
    for (int i = 0; i < n; i++) {
      if (tin[i] == -1) dfs(i);
    }
  }
};
int ans[2000][2000];
char c[2000][2000];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        adj[i * m + j].clear();
        radj[i * m + j].clear();
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> c[i][j];
        int x = i;
        int y = j;
        if (c[i][j] == 'R') y++;
        if (c[i][j] == 'L') y--;
        if (c[i][j] == 'U') x--;
        if (c[i][j] == 'D') x++;
        if (y >= 0 && x >= 0 && x < n && y < m) {
          adj[i * m + j].push_back(x * m + y);
          radj[x * m + y].push_back(i * m + j);
        }
        ans[i][j] = -1e9;
      }
    }
    SCC s(n * m);
    s.build();
    vector<int> cnt(s.ccnt + 1, 0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cnt[s.comp[i * m + j]]++;
      }
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (cnt[s.comp[i * m + j]] >= 2) {
          ans[i][j] = cnt[s.comp[i * m + j]];
          q.push(i * m + j);
        }
        if (adj[i * m + j].empty()) {
          ans[i][j] = 1;
          q.push(i * m + j);
        }
      }
    }
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int x : radj[v]) {
        if (ans[x / m][x % m] == -1e9) {
          ans[x / m][x % m] = ans[v / m][v % m] + 1;
          q.push(x);
        }
      }
    }
    int sx, sy, mx = -1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (ans[i][j] > mx) {
          mx = ans[i][j];
          sx = i + 1;
          sy = j + 1;
        }
      }
    }
    cout << sx << " " << sy << " " << mx << '\n';
  }
}
